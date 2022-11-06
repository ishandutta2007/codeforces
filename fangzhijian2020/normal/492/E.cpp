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
int n,m,dx,dy,X,Y,x,y,ans[1000005];
int exgcd(int a,int b,int&x,int&y){
	if(!b){x=1;y=0;return a;}
	int d=exgcd(b,a%b,x,y),z=x;
	x=y,y=z-(a/b)*y;return d;
}
int main(){
	n=read();m=read();dx=read();dy=read();
	exgcd(dx,n,X,Y);
	for(int i=1;i<=m;++i){
		x=read();y=read();
		x=1ll*x*X%n;
		y=(y-1ll*x*dy%n+n)%n;
		++ans[y];
	}
	int Max=-1,num=0;
	for(int i=0;i<n;++i){
		if(ans[i]>Max){
			Max=ans[i];num=i;
		}
	}
	cout<<0<<" "<<num<<"\n";
	return 0;
}