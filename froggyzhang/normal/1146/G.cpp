#include<bits/stdc++.h>
using namespace std;
#define N 55
typedef long long ll;
int s[N][N][N],n,H,m;
int dp[N][N][N],g[N][N][N];
inline int calc(int l1,int r1,int l2,int r2,int h){
	return s[r1][r2][h]-s[l1-1][r2][h]-s[r1][l2-1][h]+s[l1-1][l2-1][h];	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>H>>m;
	for(int i=1;i<=m;++i){
		int l,r,h,w;
		cin>>l>>r>>h>>w;
		if(h<H)s[l][r][h+1]+=w;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=H;++k)
				s[i][j][k]+=s[i][j][k-1];	
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=H;++k)
				s[i][j][k]+=s[i][j-1][k];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=H;++k)
				s[i][j][k]+=s[i-1][j][k];
	for(int len=1;len<=n;++len){
		for(int l=1;l+len-1<=n;++l){
			int r=l+len-1;
			for(int k=l;k<=r;++k){
				for(int i=0;i<=H;++i){
					dp[l][r][i]=max(dp[l][r][i],g[l][k-1][i]+g[k+1][r][i]-calc(l,k,k,r,i)+i*i);	
				}
			}
			g[l][r][0]=dp[l][r][0];
			for(int i=1;i<=H;++i){
				g[l][r][i]=max(g[l][r][i-1],dp[l][r][i]);
			}
		}
	}
	cout<<g[1][n][H]<<'\n';
	return 0;
}