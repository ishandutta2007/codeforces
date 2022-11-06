#include<bits/stdc++.h>
using namespace std;
const int N=2e5+11;
int n;
vector<int> e[N];
int ans[N];
vector<int> b[2];
int c[N];
void dfs(int x){
	b[c[x]].push_back(x);
	for(int y:e[x]){
		e[y].erase(find(e[y].begin(),e[y].end(),x));
		c[y]=c[x]^1;
		dfs(y);
	}
}
int Log[N];
void work(){
	cin>>n;
	for(int i=1;i<=n;++i)e[i].clear();
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	b[0].clear();
	b[1].clear();
	dfs(1);
	int vis[22]={0};
	int m=b[1].size();
	int t=Log[n];
	//cerr<<"debug: "<<t<<" "<<(1<<t+1)-1<<endl;
	if(n!=(1<<t+1)-1&&m>=n-(1<<t)+1){
		vis[t]=1;
		m-=n-(1<<t)+1;
		--t;
	}
	for(int i=0;i<=t;++i)vis[i]=m>>i&1;
	for(int i=1;i<=n;++i){
		int w=vis[Log[i]];
		ans[b[w].back()]=i;
		b[w].pop_back();
	}
	for(int i=1;i<=n;++i)cout<<ans[i]<<" \n"[i==n];
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	Log[0]=-1;
	for(int i=1;i<N;++i)Log[i]=Log[i>>1]+1;
	int t;
	cin>>t;
	while(t--)work();
}