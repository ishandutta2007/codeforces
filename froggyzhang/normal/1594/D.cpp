#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,m,col[N];
vector<pair<int,int> > G[N];
int cnt[2],ans,ok;
void dfs(int u){
	if(!ok)return;
	cnt[col[u]]++;
	for(auto [v,w]:G[u]){
		int t=col[u]^w;
		if(~col[v]){
			if(col[v]^t){
				ok=0;break;
			}
		}
		else{
			col[v]=t;
			dfs(v);
		}
	}	
}
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)G[i].clear();
	ans=0;
	for(int i=1;i<=m;++i){
		int u,v;
		string s;
		cin>>u>>v>>s;
		int w=s[0]=='i'?1:0;
		G[u].emplace_back(v,w);
		G[v].emplace_back(u,w);
	}
	memset(col,-1,sizeof(col));
	ok=1;
	for(int i=1;i<=n;++i){
		if(~col[i])continue;
		cnt[0]=cnt[1]=0;
		col[i]=0;
		dfs(i);	
		if(!ok){
			cout<<-1<<'\n';
			return;
		}
		ans+=max(cnt[0],cnt[1]);
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}