//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
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
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}

class segtree
{
public:
	#define s (1<<17)
	ll seg[s*2];
	ll lazy[s*2];
	void lazy_evaluate(int k, int l, int r)
	{
		if(k*2+2>=s*2) return ;
		lazy[k*2+2]+=lazy[k];
		lazy[k*2+1]+=lazy[k];
		seg[k*2+2]+=lazy[k] * (r-l+1) / 2;
		seg[k*2+1]+=lazy[k] * (r-l+1) / 2;
		lazy[k]=0;
	}
	ll update(int beg,int end,int idx,int lb,int ub,ll num)
	{
		if(ub<beg||end<lb)
		{
			return seg[idx];
		}
		if(beg<=lb&&ub<=end)
		{
			lazy[idx]+=num;
			seg[idx]+=num * (ub-lb+1);
			return seg[idx];
		}
		if(lazy[idx])
		{
			lazy_evaluate(idx, lb, ub);
		}
		return seg[idx]=(update(beg,end,idx*2+1,lb,(lb+ub)/2,num)+update(beg,end,idx*2+2,(lb+ub)/2+1,ub,num));
	}
	ll query(int beg,int end,int idx,int lb,int ub)
	{
		if(ub<beg||end<lb)
		{
			return 0LL;
		}
		if(beg<=lb&&ub<=end)
		{
			return seg[idx];
		}
		if(lazy[idx])
		{
			lazy_evaluate(idx, lb, ub);
		}
		return (query(beg,end,idx*2+1,lb,(lb+ub)/2)+query(beg,end,idx*2+2,(lb+ub)/2+1,ub));
	}
}fuyuko;
#define SZ 100005
int n;
vector<int>edge[SZ];
int up[20][SZ],dep[SZ], sz[SZ], beg[SZ], curid;
int par[SZ], ran[SZ];
P db[20][SZ * 2];
int revs[SZ * 2], ln[SZ] , unid;

struct dbling{
	bool ready = 0;
	void dfs(int v,int u,int d){
		up[0][v] = u; dep[v] = d; sz[v] = 1;
		P p = mp(-1, -1);
		rep(i,edge[v].size()){
			if(edge[v][i] == u) continue;
			dfs(edge[v][i], v, d+1);
			sz[v] += sz[edge[v][i]];
			chmax(p, mp(sz[edge[v][i]], i));
		}
		if(p.sc == -1) return;
		swap(edge[v][0], edge[v][p.sc]);
	}
	void dfs2(int v, int u, int d){
		beg[v] = curid++;
		ln[v] = unid;
		db[0][unid++] = mp(d, v);
		rep(i, edge[v].size()){
			if(edge[v][i] == u) continue;
			if(i == 0){
				par[edge[v][i]] = par[v];
				ran[edge[v][i]] = ran[v]+1;
			}
			else{
				par[edge[v][i]] = edge[v][i];
				ran[edge[v][i]] = 0;
			}
			dfs2(edge[v][i], v, d+1);
			db[0][unid++] = mp(d, v);
		}
	}
	void prepare(){
	    rep(j, 20)rep(k, SZ * 2) db[j][k] = mp(INF, INF);
	    curid = 0;
	    dfs(1,-1,0);
	    par[1] = 1, ran[1] = 0;
	    dfs2(1, -1, 0);
		rep(j,19){
			rep(i,SZ){
				if(up[j][i] == -1) up[j+1][i] = up[j][i];
				else up[j+1][i] = up[j][up[j][i]];
			}
			rep(i, SZ*2){
			    db[j+1][i] = db[j][i];
			    if(i+(1<<j) < SZ*2) chmin(db[j+1][i], db[j][i+(1<<j)]);
			}
		}
		repn(i, SZ*2-1){
		    for(int j=0;;j++){
		        if((2<<j) >= i && i >= (1<<j)){
		            revs[i] = j; break;
		        }
		    }
		}
		ready = 1;
	}
	int get(int a,int b){
		int l = ln[a], r = ln[b];
		if(l > r) swap(l, r);
		int k = revs[r-l+1];
		return min(db[k][l], db[k][r+1-(1<<k)]).sc;
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
	void add(int v, int val){
		while(1){
			int u = par[v];
			fuyuko.update(beg[u], beg[v], 0, 0, s-1, val);
			if(u == 1) break;
			v = up[0][u];
		}
	}
	ll calc(int u, int v, int num, ll d){
		if(dep[u] > dep[v]) swap(u, v);
		int len = dist(u, v)/2;
		int mid = go_up(v, len);
		int ch = fuyuko.query(beg[mid], beg[mid], 0, 0, s-1);
		ll gen = 1LL*ch*len + 1LL*(num-ch)*(dist(u, v)-len);
		d += 1LL*dep[mid]*num;
		while(1){
			int u = par[mid];
			d -= 2LL*fuyuko.query(max(1, beg[u]), beg[mid], 0, 0, s-1);
			if(u == 1) break;
			mid = up[0][u];
		}
		return d-gen+1LL*num*dist(u, v);
	}
}kaede;
ll ans;
P1 get_diam(int a, int b, int c){
	P1 ret = mp(-1, mp(-1, -1));
	chmax(ret, mp(kaede.dist(a, b), mp(a, b)));
	chmax(ret, mp(kaede.dist(b, c), mp(b, c)));
	chmax(ret, mp(kaede.dist(c, a), mp(c, a)));
	return ret;
}
void solve(int l, int r){
	if(l == r) return;
	int m = (l+r)/2;
	//[m,m] ...[l,m]
	//[m+1,m+1] ... [m+1, r]
	//[m,m+1]diam(x, y)
	
	//
	//[x, m] ym+1 -> r
	//[m+1, p-1][x,m]diam
	//[p, q][x,m]diam + [m+1, y]diam
	//[q+1, r][m+1, y]diam
	//p, q
	//1, 3
	//2[m+1, y][a, b] (l<=a, b<=m) 
	//[m+1, y][a,b]
	//HLD....

	vector<P1>le, ri;
	P1 cur = mp(0, mp(m, m));
	for(int i=m;i>=l;i--){
		cur = get_diam(cur.sc.fi, cur.sc.sc, i);
		le.pb(cur);
	}
	cur = mp(0, mp(m+1, m+1));
	vector<ll>rui(r-m+1, 0);
	for(int i=m+1;i<=r;i++){
		cur = get_diam(cur.sc.fi, cur.sc.sc, i);
		ri.pb(cur);
		rui[i-m] = rui[i-m-1] + cur.fi;
	}
	vector<vector<P>>query(r-m+2);
	for(int i=m;i>=l;i--){
		int lb, ub, p, q;
		lb = m, ub = r+1;
		while(ub-lb > 1){
			int mid = (lb+ub)/2;
			if(ri[mid-m-1].fi > le[m-i].fi || get_diam(le[m-i].sc.fi, le[m-i].sc.sc, ri[mid-m-1].sc.fi).fi > le[m-i].fi || get_diam(le[m-i].sc.fi, le[m-i].sc.sc, ri[mid-m-1].sc.sc).fi > le[m-i].fi){
				ub = mid;
			}
			else{
			    lb = mid;
			}
		}
		p = ub;
		lb = m, ub = r+1;
		while(ub-lb > 1){
			int mid = (lb+ub)/2;
			if(ri[mid-m-1].fi < le[m-i].fi || get_diam(le[m-i].sc.fi, le[m-i].sc.sc, ri[mid-m-1].sc.fi).fi > ri[mid-m-1].fi || get_diam(le[m-i].sc.fi, le[m-i].sc.sc, ri[mid-m-1].sc.sc).fi > ri[mid-m-1].fi){
				lb = mid;
			}
			else{
				ub = mid;
			}
		}
		q = lb;
		if(q-p+1 < 0){
			ans += 1LL*(p-m-1)*le[m-i].fi;
			ans += rui[r-m] - rui[p-1-m];
		}
		else{
			ans += 1LL*(p-m-1)*le[m-i].fi;
			ans += rui[r-m] - rui[q-m];
			if(p <= q){
    			int x = le[m-i].sc.fi, y = le[m-i].sc.sc;
    			int xd = get_diam(x, ri[q-m-1].sc.fi, ri[q-m-1].sc.sc).fi;
    			int yd = get_diam(y, ri[q-m-1].sc.fi, ri[q-m-1].sc.sc).fi;
    			int V;
    			if(xd > yd) V = x;
    			else V = y;
    			query[p-m].pb(mp(V, 1));
    			query[q-m+1].pb(mp(V, -1));
    		}
		}
	}
	int num = 0;
	ll d = 0;
	for(int i=1;i<=r-m+1;i++){
		for(const auto at:query[i]){
			kaede.add(at.fi, at.sc);
			num += at.sc;
			d += 1LL * dep[at.fi] * at.sc;
		}
		if(i == r-m+1) break;
		int u = ri[i-1].sc.fi, v = ri[i-1].sc.sc;
		ans += kaede.calc(u, v, num, d);
	}
	assert(!num);
	solve(l, m);
	solve(m+1, r);
}
int main(){
	cin >> n;
	rep(i, n-1){
		int a, b; cin >> a >> b;
		edge[a].pb(b);
		edge[b].pb(a);
	}
	kaede.prepare();
	solve(1, n);
	cout << ans << endl;
}