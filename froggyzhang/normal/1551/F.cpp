#include<bits/stdc++.h>
using namespace std;
#define N 123
typedef long long ll;
const int mod=1e9+7;
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
int n,m,T,ans;
vector<int> G[N];
vector<int> tmp;
vector<vector<int> > A;
void dfs(int u,int fa,int dep){
	while(tmp.size()<=dep)tmp.push_back(0);
	++tmp[dep];
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u,dep+1);
	}
}
void calc(vector<int> &A){
	vector<int> dp(1,1);
	for(auto w:A){
		dp.push_back(0);
		for(int i=(int)dp.size()-1;i>=1;--i){
			dp[i]=(dp[i]+1LL*w*dp[i-1])%mod;
		}
	}
	ans=(ans+dp[m])%mod;
}
void Solve(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		G[i].clear();
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(m==2){
		printf("%d\n",n*(n-1)/2);
		return;	
	}
	ans=0;
	for(int rt=1;rt<=n;++rt){
		A.clear();
		for(auto v:G[rt]){
			tmp.clear();
			dfs(v,rt,0);
			A.push_back(tmp);
		}
		for(int i=0;i<n;++i){
			tmp.clear();
			for(auto t:A){
				if(t.size()>i){
					tmp.push_back(t[i]);
				}
			}
			if(tmp.size()>=m){
				calc(tmp);	
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}