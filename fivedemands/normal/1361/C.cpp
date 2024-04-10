#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
const int iu=1<<22;
int n;
int a[N],b[N];
int par[iu];
int sz[iu];
int deg[iu];
int c=0;
int find(int x){
	if(par[x]!=x) par[x]=find(par[x]);
	return par[x];
}
void join(int x,int y){
	x=find(x);y=find(y);
	if(x==y) return;
	c-=(sz[x]!=0 && sz[y]!=0);
	par[x]=y;
	sz[y]+=sz[x];
}
vector<pair<int,int> >adj[iu];
bool vis[iu];
bool vis2[iu];
bool dead[2*N];
stack<int>ans;
void dfs(int id){
	int last=0;
	while(!adj[id].empty()){
		auto c=adj[id].back();
		adj[id].pop_back();
		if(dead[c.se]) continue;
		dead[c.se]=true;
		dead[((c.se-1)^1)+1]=true;
		dfs(c.fi);
		last=c.se;
		ans.push(((c.se-1)^1)+1);
		ans.push(c.se);
	}
	
}
void solve(int x){
	for(int i=1; i<=n ;i++){
		a[i]&=(1<<x)-1;
		b[i]&=(1<<x)-1;
		adj[a[i]].push_back({b[i],2*i-1});
		adj[b[i]].push_back({a[i],2*i});
	}
	dfs(a[1]);
	cout << x << '\n';
	while(!ans.empty()){
		cout << ans.top() << ' ';
		ans.pop();
	}
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=0; i<iu ;i++) par[i]=i;
	for(int i=1; i<=n ;i++){
		cin >> a[i] >> b[i];
	}
	for(int i=1; i<=n ;i++){
		if(++sz[find(a[i])]==1) c++;
		if(++sz[find(b[i])]==1) c++;
		deg[a[i]]++;deg[b[i]]++;
	}
	for(int i=1; i<=n ;i++) join(a[i],b[i]);
	bool ok=true;
	int d=0;
	for(int i=0; i<(1<<20) ;i++){
		if(deg[i]%2!=0) d++;
	}
	if(c==1 && d==0){
		solve(20);return 0;
	}
	for(int i=19; i>=0 ;i--){
		for(int j=(1<<i); j<(1<<(i+1)) ;j++){
			if(deg[j]%2==1 && deg[j^(1<<i)]%2==1) d-=2;
			deg[j^(1<<i)]+=deg[j];
			join(j,j^(1<<i));
		}
		if(c==1 && d==0){
			solve(i);return 0;
		}
	}
}