#include<bits/stdc++.h>
using namespace std;
#define N 500010
typedef long long ll;
int n,a[N],rt;
ll sum;
vector<int> G[N];
void dfs(int u,int fa){
	static int st[N],top;
	st[++top]=u;
	if(u^rt){
		ll mn=1e18;
		for(int i=0;i<=20;++i){
			mn=min(mn,1LL*(i+1)*a[st[max(1,top-(1<<i))]]);		
		}
		sum+=mn;
	}
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);	
	}
	--top;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rt=min_element(a+1,a+n+1)-a;
	sum-=a[rt];
	dfs(rt,0);
	cout<<sum<<'\n';
	return 0;
}