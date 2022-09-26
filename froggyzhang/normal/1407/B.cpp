#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1010
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,a[N],vis[N];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
			vis[i]=0;
		}
		int g=0;
		for(int i=1;i<=n;++i){
			int mx=-1,pos=-1;
			for(int j=1;j<=n;++j){
				if(vis[j])continue;
				int k=__gcd(g,a[j]);
				if(k>mx){
					mx=k,pos=j;
				}
			}
			vis[pos]=1;
			g=mx;
			printf("%d ",a[pos]);
		}
		printf("\n");
	}
	return 0;
}