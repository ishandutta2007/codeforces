#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
vector<int>adj[3001];
ll ans=0;
int sz[3001];
ll dp[3001][3001];
int haha[3001][3001];
int huhu[3001][3001];
int dist[3001][3001];
vector<pair<int,int> >v[3001];
void dfs(int id,int p){
	sz[id]=1;
	for(auto cur:adj[id]){
		if(cur==p) continue;
		dfs(cur,id);
		sz[id]+=sz[cur];
	}
}
void dfs2(int id,int p,int rt){
	for(auto cur:adj[id]){
		if(cur==p) continue;
		dist[rt][cur]=dist[rt][id]+1;
		dfs2(cur,id,rt);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<n ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1; i<=n ;i++){
		dfs2(i,0,i);
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			if(i==j) continue;
			v[dist[i][j]].push_back({i,j});
		}
	}
	ll ans=0;
	for(int i=1; i<=n ;i++){
		for(auto cur:v[i]){
			int p=cur.fi,q=cur.se;
			if(i==1){
				int x=sz[p],y=sz[q];
				haha[p][q]=n-y;
				huhu[p][q]=y;
				if(x<y){
					haha[p][q]=x;
					huhu[p][q]=n-x;
				}
				dp[p][q]=haha[p][q]*huhu[p][q];
				ans=max(ans,dp[p][q]);
				//cout << p << ' ' << q << ' ' << dp[p][q] << endl;
				continue;
			}
			int r,s;
			for(auto x:adj[p]){
				if(dist[x][q]+1==dist[p][q]){
					r=x;break;
				}
			}
			if(sz[r]<sz[p]) haha[p][q]=n-sz[r];
			else haha[p][q]=sz[p];
			for(auto x:adj[q]){
				if(dist[p][x]+1==dist[p][q]){
					s=x;break;
				}
			}
			if(sz[s]<sz[q]) huhu[p][q]=n-sz[s];
			else huhu[p][q]=sz[q];
			dp[p][q]=max(dp[p][s],dp[r][q])+haha[p][q]*huhu[p][q];
			ans=max(ans,dp[p][q]);
			//cout << p << ' ' << q << ' ' << r << ' ' << s << ' ' << dp[p][q] << endl;
		}
	}
	cout << ans << '\n';
}