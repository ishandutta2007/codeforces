//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//#define int long long
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define a first
#define b second
#define fi first
#define sc second
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
#define si(x) int(x.size())

#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

template<class t> using vc=vector<t>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.fi<<","<<p.sc<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 1000000007;//998244353
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}

int n, a, b;
vc<int>edge[100005];
#define SZ 100005
int up[20][SZ],dep[SZ];
struct dbling{
	bool ready = 0;
	void dfs(int v,int u,int d){
		up[0][v] = u; dep[v] = d;
		rep(i,edge[v].size()){
			if(edge[v][i] == u) continue;
			dfs(edge[v][i], v, d+1);
		}
	}
	void prepare(){
	    dfs(1,-1,0);
		rep(j,19){
			rep(i,SZ){
				if(up[j][i] == -1) up[j+1][i] = up[j][i];
				else up[j+1][i] = up[j][up[j][i]];
			}
		}
		ready = 1;
	}
	int get(int a,int b){
		if(dep[a] > dep[b]) swap(a,b);
		int D = dep[b]-dep[a];
		rep(i,20){
			if(((D>>i)&1)) b = up[i][b];
		}
		if(a == b) return a;
		for(int i=19;i>=0;i--){
			if(up[i][a] != up[i][b]){
				a = up[i][a];
				b = up[i][b];
			}
		}
		return up[0][a];
	}
	int dist(int a,int b){
		int c = get(a,b);
		return dep[a]+dep[b]-2*dep[c];
	}
	int dist(int a,int b,int c){
		//assuming c is lca of (a,b)
		return dep[a]+dep[b]-2*dep[c];
	}
	int go_up(int v,int a){
	    if(dep[v] < a) return -1;
	    rep(i,20) if(((a>>i)&1)) v = up[i][v];
	    return v;
	}
	//a ---- b
	//x (1-indexed)
	//-1
	//verified : opencup Warsaw I
	int v_on_path(int a,int b,int x){
		int c = get(a,b);
		int d = dist(a,b,c);
		if(x <= 0 || x > d+1) return -1;
		if(x <= dep[a]-dep[c]+1){
			return go_up(a, x-1);
		}
		else{
			x = d+2-x;
			return go_up(b, x-1);
		}
	}
}kaede;

bool in_dia[100005];
int dep_from_dia[100005];
P max_depfd[100005];
int up2[20][100005];
int bos[100005];
void dfs2(int v, int u, int d, int b){
	dep_from_dia[v] = d;
	max_depfd[v] = mp(d, v);
	up2[0][v] = u;
	bos[v] = b;
	for(auto at:edge[v]){
		if(at == u || in_dia[at] == true) continue;
		dfs2(at, v, d+1, b);
		chmax(max_depfd[v], max_depfd[at]);
	}
}

void solve(){
	cin >> n >> a >> b;
	repn(i, n) edge[i].clear();
	repn(i, n) in_dia[i] = false;
	rep(i, n-1){
		int u, v; cin >> u >> v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	kaede.dfs(1, -1, 0);
	P p = mp(-1, -1);
	repn(i, n) chmax(p, mp(dep[i], i));
	kaede.dfs(p.sc, -1, 0);
	P q = mp(-1, -1);
	repn(i, n) chmax(q, mp(dep[i], i));
	kaede.prepare();
	vc<int>pat;
	int z1 = p.sc, z2 = q.sc;
	repn(i, n){
		int x = kaede.v_on_path(z1, z2, i);
		if(x == -1) break;
		pat.pb(x);
		in_dia[x] = true;
	}
	int D = kaede.dist(a, b);
	bool spot = false;
	for(auto at:pat) {
		dfs2(at, -1, 0, at);
		if(max_depfd[at].a >= D) spot = true;
	}
	if(!spot){
		o("NO");
		return ;
	}
	int goal = 0;
	if(bos[a] != bos[b]){
		if(kaede.dist(z1, bos[a]) > kaede.dist(z1, bos[b])) swap(a, b);
		if(kaede.dist(z1, bos[b]) < D || kaede.dist(z2, bos[a]) < D){
			o("NO");
			return ;
		}
	}
	else{
		vc<int>pt;
		P p = mp(INF, INF);
		repn(i, n){
			int x = kaede.v_on_path(a, b, i);
			if(x == -1) break;
			pt.pb(x);
			chmin(p, mp(dep_from_dia[x], x));
		}
		goal = p.fi;
	}
	//cout << n << " " << a << " " << b << " " << goal << endl;
	//cout << pat << endl;
	//OK
	rep(j, 18){
		repn(i, n){
			if(up2[j][i] == -1) up2[j+1][i] = -1;
			else{
				up2[j+1][i] = up2[j][up2[j][i]];
			}
		}
	}
	int za = a, zb = b;
	rep(_, 2){
		a = za, b = zb;
		unordered_set<ll>M;
		rep(r, 2*n+5){
			if(r%2 == 0){
				int margin = max_depfd[a].a - dep_from_dia[a];
				if(dep_from_dia[b]-margin <= goal){
					o("YES");
					return;
				}
				else{
					rep(j, 18) if(((margin>>j)&1)) b = up2[j][b];
					a = max_depfd[a].b;
				}
			}
			else{
				int margin = max_depfd[b].a - dep_from_dia[b];
				if(dep_from_dia[a]-margin <= goal){
					o("YES");
					return;
				}
				else{
					rep(j, 18) if(((margin>>j)&1)) a = up2[j][a];
					b = max_depfd[b].b;
				}
			}
			if(M.find(1000000LL*a+b) != M.end()) break;
			else M.insert(1000000LL*a+b);
		}
		swap(za, zb);
	}
	o("NO");
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; cin >> t;
	while(t--) solve();
}