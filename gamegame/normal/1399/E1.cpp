#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
typedef pair<ll,int> pli;
ll n,m;
ll sum=0;
vector<pair<pli,int> >adj[N];
int ans[N];
int sz[N];
vector<pair<pli,int> >v;
vector<ll>f[3];
void dfs(int id,int p){
	sz[id]=0;
	for(auto c:adj[id]){
		if(c.se==p) continue;
		dfs(c.se,id);
		sz[id]+=sz[c.se];
		sum+=c.fi.fi*sz[c.se];
		v.push_back({c.fi,sz[c.se]});
	}
	if(sz[id]==0) sz[id]=1;
}
void solve(){
	cin >> n >> m;
	for(int i=1; i<=n ;i++) adj[i].clear();
	v.clear();f[1].clear();f[2].clear();sum=0;
	for(int i=1; i<n ;i++){
		int u,v;ll w;int c;
		cin >> u >> v >> w;
		c=1;
		adj[u].push_back({{w,c},v});
		adj[v].push_back({{w,c},u});
	}
	dfs(1,0);
	for(auto c:v){
		while(c.fi.fi!=0){
			f[c.fi.se].push_back((c.fi.fi-c.fi.fi/2)*c.se);
			c.fi.fi/=2;
		}
	}
	sort(f[1].begin(),f[1].end());
	sort(f[2].begin(),f[2].end());
	reverse(f[1].begin(),f[1].end());
	reverse(f[2].begin(),f[2].end());
	m=sum-m;
	ll p1=0,p2=0;
	while(p2<f[2].size()){
		m-=f[2][p2++];
	}
	ll ans=1e18;
	if(m<=0) ans=p2*2;
	while(p1<=f[1].size()){
		if(m<=0) ans=min(ans,p2*2+p1);
		if(m>0){
			if(p1==f[1].size()) break;
			else m-=f[1][p1++];
		}
		else if(p2>0){
			m+=f[2][--p2];
		}
		else break;
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
	
}