#include<bits/stdc++.h>
using namespace std;
#define N 505
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
int n,m,k,dp[12][N][N],a[N][N],b[N][N];
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<m;++j){
			a[i][j]=read();
		}
	}
	for(int i=1;i<n;++i){
		for(int j=1;j<=m;++j){
			b[i][j]=read();
		}
	}
	if(k&1){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				printf("-1 ");
			}
			printf("\n");
		}
		return 0;
	}
	k>>=1;
	for(int p=1;p<=k;++p){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				int &tp=dp[p][i][j];
				tp=2e9;
				if(i>1)tp=min(tp,dp[p-1][i-1][j]+b[i-1][j]);
				if(j>1)tp=min(tp,dp[p-1][i][j-1]+a[i][j-1]);
				if(i<n)tp=min(tp,dp[p-1][i+1][j]+b[i][j]);
				if(j<m)tp=min(tp,dp[p-1][i][j+1]+a[i][j]);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			printf("%d ",dp[k][i][j]<<1);
		}
		printf("\n");
	}
	return 0;
}