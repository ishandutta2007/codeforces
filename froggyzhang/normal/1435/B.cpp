#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
#define N 505
int T,n,m,a[N][N],pos[N*N],p[N];
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				a[i][j]=read();
				pos[a[i][j]]=i;
			}
		}
		for(int i=1;i<=n;++i){
			int x=read();
			for(int j=1;j<=m;++j){
				printf("%d ",a[pos[x]][j]);
			}
			printf("\n");
		}
		for(int j=2;j<=m;++j){
			for(int i=1;i<=n;++i){
				read();
			}
		}
	}
	return 0;
}