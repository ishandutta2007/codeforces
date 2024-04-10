#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define int long long
const ll mod=998244353;
const int N=2e5+1;
int n;
int d[N];
queue<int>q;
 
vector<int>adj[N];
int g[N],h[N],z;
bool use[N];
vector<int>ans[N];
 
vector<int>f[N];
bool vis[N];
void dfs(int id,int p){
	vis[id]=true;
	for(auto c:adj[id]){
		if(c==p || d[c]!=d[id]) continue;
		dfs(c,id);
		for(int i=1; i<=z ;i++){
			ans[id][i]=min(ans[id][i],ans[c][i]+1);
		}
		ans[id][h[d[id]]]=1;
	}
}
void dfs2(int id,int p){
	for(auto c:adj[id]){
		if(c==p || d[c]!=d[id]) continue;
		for(int i=1; i<=z ;i++){
			ans[c][i]=min(ans[c][i],ans[id][i]+1);
		}
		ans[c][h[d[c]]]=1;
		dfs2(c,id);
	}
}
main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		int x;cin >> x;
		if(x==1) q.push(i);
		else d[i]=1e9;		
	}
	for(int i=1; i<n ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		for(auto c:adj[x]){
			if(d[c]>d[x]+1){
				d[c]=d[x]+1;
				q.push(c);
			}
		}
	}
	for(int i=1; i<=n ;i++){
		f[d[i]].push_back(i);
		for(auto c:adj[i]){
			if(d[c]==d[i] && c>i){
				use[d[i]]=true;
			}
		}
	}
	for(int i=0; i<=n ;i++){
		if(use[i]){
			g[++z]=i;
			h[i]=z;
		}
	}/*
	for(int i=1; i<=n ;i++){
		cout << d[i] << ' ';
	}
	cout << endl;*/
	for(int i=1; i<=n ;i++){
		ans[i].resize(z+1);
	}
	for(int j=0; j<=n ;j++){
		for(auto x:f[j]){
			for(int i=1; i<=z ;i++) ans[x][i]=1e9;
			for(auto c:adj[x]){
				if(d[c]==d[x]-1){
					for(int i=1; i<=z ;i++) ans[x][i]=min(ans[x][i],max((ll)0,ans[c][i]-1));
				}
			}
		}
		
		for(auto x:f[j]){
			if(!vis[x]){
				dfs(x,0);
				dfs2(x,0);
			}
		}
		/*for(auto x:f[j]){
			cout << x << ": ";
			for(int i=1; i<=z ;i++) cout << ans[x][i] << ' ';
			cout << '\n';
		}*/
	}
	for(int i=1; i<=n ;i++){
		int res=d[i];
		for(int j=1; j<=z ;j++){
			if(ans[i][j]==0) res=max(res,d[i]*2-g[j]);
		}
		cout << res << ' ';
	}
	cout << '\n';
}