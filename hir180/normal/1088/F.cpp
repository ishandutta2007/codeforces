#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define rdll(x) scanf("%lld",&x);
int n;
ll a[500005];
vector<int>edge[500005];
int up[500005][21];
vector<pair<ll,P> >vec;

void dfs(int v,int u){
	up[v][0]=u;
	rep(i,edge[v].size()){
		int to = edge[v][i];
		if(to == u) continue;
		dfs(to,v);
	}
}
int par[500005],ran[500005];
void init(){ for(int i=0;i<500005;i++) par[i] = i; }
int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
void unite(int x,int y){
	x = find(x); y = find(y); if(x==y) return;
	if(ran[x] < ran[y]) par[x] = y;
	else{
		par[y] = x;
		if(ran[x] == ran[y]) ran[x]++;
	}
}
bool same(int x,int y){ return find(x)==find(y); }

int main(){
	scanf("%d",&n);
	repn(i,n) rdll(a[i]);
	rep(i,n-1){
		ll a,b; rdll(a); rdll(b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	int root = -1, val = INF;
	repn(i,n){
		if(val > a[i]){ val=a[i];root=i;}
	}
	dfs(root,-1);
	rep(j,20) repn(i,n){
		if(up[i][j]==-1) up[i][j+1]=-1;
		else up[i][j+1] = up[up[i][j]][j];
	}
	for(int i=1;i<=n;i++){
		int cur = up[i][0];
		ll pr=0;
		ll curmin = 1e18;
		while(1){
		    if(cur != -1){
			    if(curmin > a[cur]+a[i]+pr*a[cur]){
			        vec.pb(mp(a[cur]+a[i]+pr*a[cur],mp(cur,i)));
			        curmin = a[cur]+a[i]+pr*a[cur];
			    }
			}else{
			    if(curmin > a[root]+a[i]+pr*a[root] ){
			        vec.pb(mp(a[root]+a[i]+pr*a[root],mp(root,i)));
			        curmin = a[root]+a[i]+pr*a[root];
			    }
			}
			
			if(cur==-1) break;
			cur = up[cur][pr];
			pr++;
		}
	}
	SORT(vec);
	init();
	ll ans = 0;
	rep(i,vec.size()){
		ll val = vec[i].fi;
		int a = vec[i].sc.fi, b = vec[i].sc.sc;
		if(same(a,b)) continue;
		unite(a,b); ans += val;
	}
	cout<<ans<<endl;
}