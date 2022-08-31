#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=1e5+1;
int n,m;
vector<int>adj[N];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int x){
	//return rand()%x;
	return uniform_int_distribution<int>(0, x-1)(rng);
}
int d[N];
bool inq[N];
bool vis3[N];
bool ok=true;
void dfs3(int id){
	inq[id]=true;
	vis3[id]=true;
	for(auto x:adj[id]){
		if(!vis3[x]){
			dfs3(x);
		}
		else if(!inq[x]) ok=false;
	}
	inq[id]=false;
}
bool arin(int x){
	for(int i=1; i<=n ;i++) vis3[i]=inq[i]=false;
	ok=true;
	dfs3(x);
	return ok;
}
bool vis[N];
vector<int>ch[N];
int par[N];
int dx[N],dy[N];
int cs[N];
int up[N];
void dfs(int id){
	vis[id]=true;
	up[id]=id;
	for(auto x:adj[id]){
		if(!vis[x]){
			d[x]=d[id]+1;
			par[x]=id;
			ch[id].push_back(x);
			cs[id]=x;
			dfs(x);
		}
		else{
			//cout << "!!! " << x << ' ' << id << endl;
			dx[x]--;
			dx[id]++;
			if(d[up[id]]>d[x]) up[id]=x;
		}
	}
	for(auto x:ch[id]){
		if(d[up[x]]<d[up[id]]) up[id]=up[x];
	}
}
int dfs4(int id){
	int duh=dx[id];
	for(auto x:ch[id]) duh+=dfs4(x);
	dy[id]=duh;
	return duh;
}
bool good[N];
int rt;
void dfs2(int id){
	if(dy[id]<=1) good[id]=good[up[id]];
	if(id==rt) good[id]=true;
	for(auto x:ch[id]){
		dfs2(x);
	}
}
void solve(){
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		adj[i].clear();
		ch[i].clear();
		dx[i]=dy[i]=0;
		good[i]=false;
	}
	for(int i=1; i<=m ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
	}
	int x=0;
	for(int i=1; i<=100 ;i++){
		x=rand(n)+1;
		if(arin(x)) break;
		x=0;
	}
	if(x==0){
		cout << "-1\n";return;
	}
	for(int i=1; i<=n ;i++) vis[i]=false;
	d[x]=0;
	dfs(x);
	rt=x;
	/*cout << "info " << endl;
	for(int i=1; i<=n ;i++){
		cout << up[i] << ' ' << d[i] << ' ' << dx[i] << ' ' << dy[i] << endl;
	}
	cout << "info end" << endl;*/
	dfs4(x);
	dfs2(x);
	int cnt=0;
	for(int i=1; i<=n ;i++) if(good[i]) cnt++;
	if(cnt*5<n){
		cout << "-1\n";return;
	}
	for(int i=1; i<=n ;i++) if(good[i]) cout << i << ' ';
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	
	int t;cin >> t;while(t--) solve();
}