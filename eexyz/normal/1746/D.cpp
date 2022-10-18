#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define IOS ios::sync_with_stdio(0)
#define ls k<<1
#define rs k<<1|1
int T,n,m,i,j,k,x,y,fa[N],s[N]; 
vector<int>son[N];
ll ans,dp[N][2];
void dfs(int now,int l,int r){
//	cout<<now<<"\n";
	int ss=0,gg;vector<ll>q;ll zz=0;dp[now][0]=dp[now][1]=0;
	for(int T,i=0;i<son[now].size();++i){
		T=son[now][i];
		dfs(T,l/(son[now].size()),(r+son[now].size()-1)/son[now].size());
		dp[now][0]+=dp[T][0];
		ss+=l/(son[now].size()); 
		q.push_back(dp[T][1]-dp[T][0]);
	}
	dp[now][1]=dp[now][0];
	if(son[now].size()){
		sort(q.begin(),q.end());gg=q.size()-1;
		for(int i=ss+1;i<=l;++i)zz+=q[gg],--gg;
		dp[now][0]+=zz,dp[now][1]+=zz;
		if(l!=r)dp[now][1]+=q[gg];
	}
	dp[now][0]+=1ll*l*s[now];
	dp[now][1]+=1ll*r*s[now];
//	cout<<now<<":"<<dp[now][0]<<" "<<dp[now][1]<<"\n";
}
int main(){
	IOS;
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(i=2;i<=n;++i)cin>>fa[i],son[fa[i]].push_back(i);
		for(i=1;i<=n;++i)cin>>s[i];
		dfs(1,k,k);
		cout<<dp[1][0]<<"\n";
		for(i=1;i<=n;++i)son[i].clear();
	}
}