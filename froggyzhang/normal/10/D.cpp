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
int n,m,a[N],b[N],dp[N][N],pre[N][N];
void dfs(int i,int j){
	if(!i||!j)return;
	dfs(i-1,pre[i][j]);
	if(pre[i][j]^j)printf("%d ",b[j]);	
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	m=read();
	for(int i=1;i<=m;++i){
		b[i]=read();
	}
	b[0]=-1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			dp[i][j]=dp[i-1][j];
			pre[i][j]=j;
			if(a[i]==b[j]){
				for(int k=j-1;k>=0;--k){
					if(b[j]>b[k]){
						if(dp[i-1][k]+1>dp[i][j]){
							dp[i][j]=dp[i-1][k]+1;
							pre[i][j]=k;
						}
					}	
				}
			}
		}	
	}
	int mx=*max_element(dp[n],dp[n]+m+1);
	printf("%d\n",mx);
	for(int j=0;j<=m;++j){
		if(dp[n][j]==mx){
			dfs(n,j);
			return 0;
		}
	}
	return 0;
}