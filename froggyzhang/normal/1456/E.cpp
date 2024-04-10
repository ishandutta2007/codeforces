#include<bits/stdc++.h>
using namespace std;
#define N 55
typedef long long ll;
const ll inf=1e18;
int n,m;
ll L[N],R[N],c[N],dp[N][N][N][2][2][2][2];
ll dfs(int u,int l,int r,int zl,int tl,int zr,int tr){
	if(u==m)return l>r?0:inf;
	ll &ans=dp[u][l][r][zl][tl][zr][tr];
	if(~ans)return ans;
	ans=inf;
	int cl=((zl?R[l-1]:L[l-1])>>u&1)^tl;
	int cr=((zr?R[r+1]:L[r+1])>>u&1)^tr;
	ans=min(ans,dfs(u+1,l,r,zl,0,zr,0)+(l!=1&&r!=n&&cl^cr?c[u]:0));
	ll zz=(1LL<<60)-(1LL<<u+1);
	for(int k=l;k<=r;++k){
		if(!u){
			for(int t=0;t<2;++t){
				ans=min(ans,dfs(u,l,k-1,zl,tl,t,0)+dfs(u,k+1,r,t,0,zr,tr));
			}
		}
		if(!(L[k]>>u&1)&&(L[k]&zz)<(R[k]&zz)){
			ans=min(ans,dfs(u,l,k-1,zl,tl,0,1)+dfs(u,k+1,r,0,1,zr,tr));
		}
		if((R[k]>>u&1)&&(L[k]&zz)<(R[k]&zz)){
			ans=min(ans,dfs(u,l,k-1,zl,tl,1,1)+dfs(u,k+1,r,1,1,zr,tr));
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>L[i]>>R[i];
	}
	for(int i=0;i<m;++i){
		cin>>c[i];
	}
	memset(dp,-1,sizeof(dp));
	cout<<dfs(0,1,n,0,0,0,0)<<'\n';
	return 0;
}