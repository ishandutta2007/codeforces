#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,m1,m2,x,y,fa1[100005],fa2[100005],tot,X[100005],Y[100005];
int getfzj1(int x){
	if(x==fa1[x])return x;
	return fa1[x]=getfzj1(fa1[x]);
}
void merge1(int x,int y){
	x=getfzj1(x);y=getfzj1(y);
	fa1[x]=y;
}
int getfzj2(int x){
	if(x==fa2[x])return x;
	return fa2[x]=getfzj2(fa2[x]);
}
void merge2(int x,int y){
	x=getfzj2(x);y=getfzj2(y);
	fa2[x]=y;
}
bool check(int x,int y){
	if(getfzj1(x)==getfzj1(y))return 0;
	if(getfzj2(x)==getfzj2(y))return 0;
	return 1;
}
int main(){
	n=read();m1=read();m2=read();
	for(int i=1;i<=n;++i)fa1[i]=fa2[i]=i;
	for(int i=1;i<=m1;++i){
		x=read();y=read();
		merge1(x,y);
	}
	for(int i=1;i<=m2;++i){
		x=read();y=read();
		merge2(x,y);
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(check(i,j)){
				merge1(i,j);
				merge2(i,j);
				++tot;X[tot]=i;Y[tot]=j;
			}
		}
	}
	cout<<tot<<"\n";
	for(int i=1;i<=tot;++i)cout<<X[i]<<" "<<Y[i]<<"\n";
	return 0;
}