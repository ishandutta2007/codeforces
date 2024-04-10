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
int T,n,m,x,y,z,vis[100005];
int main(){
	T=read()+1;
	while(--T){
		n=read();m=read();
		for(int i=1;i<=n;++i)vis[i]=0;
		for(int i=1;i<=m;++i){
			x=read();y=read();z=read();
			vis[y]=1;
		}
		int root=0;
		for(int i=1;i<=n;++i){
			if(!vis[i]){
				root=i;break;
			}
		}
		for(int i=1;i<=n;++i){
			if(i!=root){
				cout<<i<<" "<<root<<"\n";
			}
		}
	}
	return 0;
}