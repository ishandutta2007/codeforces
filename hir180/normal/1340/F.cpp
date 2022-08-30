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
#define eb emplace_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define a first
#define b second
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

const ll mod = 1000000007;
#define M 2
ll pr[M][100005];
struct D{
	int h[2][M], len[2];
	D(){
	    memset(h, 0, sizeof(h));
	    memset(len, 0, sizeof(len));
	}
};
D make_dat(int v){
	D ret;
	if(v == 0);
	else if(v < 0){
		rep(i, M){
			ret.h[0][i] = pr[i][0] * (-v) % mod;
			ret.h[1][i] = 0;
		}
		ret.len[0] = 1; ret.len[1] = 0;
	}
	else{
		rep(i, M){
			ret.h[1][i] = pr[i][0] * v % mod;
			ret.h[0][i] = 0;
		}
		ret.len[1] = 1; ret.len[0] = 0;
	}
	return ret;
}
D merge_dat(D a, D b){
	D ret;
	if(!a.len[1]){
		ret.len[0] = a.len[0] + b.len[0];
		ret.len[1] = b.len[1];
		rep(i, M){
			ret.h[1][i] = b.h[1][i];
			ret.h[0][i] = a.h[0][i] + (ll)(b.h[0][i]) * pr[i][a.len[0]] % mod;
			if(ret.h[0][i] >= mod) ret.h[0][i] -= mod;
		}
	}
	else if(!b.len[0]){
		ret.len[0] = a.len[0];
		ret.len[1] = a.len[1] + b.len[1];
		rep(i, M){
			ret.h[0][i] = a.h[0][i];
			ret.h[1][i] = b.h[1][i] + (ll)(a.h[1][i]) * pr[i][b.len[1]] % mod;
			if(ret.h[1][i] >= mod) ret.h[1][i] -= mod;
		}
	}
	else assert(false);
	return ret;
}

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
#define SZ 5500000
int nxt_id;
struct nd{
	int l, r, cnt, val;
	D dat;
	bool bad;
	nd(){
	    l = r = cnt = val = 0;
	    bad = false;
	}
	nd(int v): l(0), r(0), val(v), bad(0){
		dat = make_dat(v);
		cnt = 1;
	}
};
nd pool[SZ];
int count(int id) { return pool[id].cnt; }
int update(int t){
    pool[t].cnt = 1 + count(pool[t].l) + count(pool[t].r);
	pool[t].dat = merge_dat(pool[pool[t].l].dat, make_dat(pool[t].val));
	pool[t].dat = merge_dat(pool[t].dat, pool[pool[t].r].dat);
	return t;
}
//pool[l].dat.len[1] == 0 or pool[r].dat.len[0] == 0
int merge(int l, int r){
	if(!l || !r) return !l ? r: l;
	int vid;
	if(mt()%(count(l) + count(r)) < count(l)){
		vid = nxt_id;
		pool[nxt_id++] = pool[l];
		pool[vid].r = merge(pool[vid].r, r);
	}
	else{
		vid = nxt_id;
		pool[nxt_id++] = pool[r];
		pool[vid].l = merge(l, pool[vid].l);
	}
	return update(vid);
}
P split(int t, int k){
	if(!t) return P(0, 0);
	int vid = nxt_id;
	pool[nxt_id++] = pool[t];
	if(k <= count(pool[vid].l)){
		P s = split(pool[vid].l, k);
		pool[vid].l = s.b;
		return mp(s.a, update(vid));
	}
	else{
		P s = split(pool[vid].r, k-count(pool[vid].l)-1);
		pool[vid].r = s.a;
		return mp(update(vid), s.b);
	}
}
//l,r
int merge0(int l, int r){
	if(!l || !r) return !l ? r: l;
	if(pool[l].bad || pool[r].bad){
		pool[nxt_id++].bad = 1;
		return nxt_id-1;
	}
	int x = pool[l].dat.len[1];
	int y = pool[r].dat.len[0];
	x = min(x, y);
	if(x){
		auto L = split(l, pool[l].cnt - x);
		auto R = split(r, x);
		assert(pool[L.b].dat.len[0] == 0 && pool[L.b].dat.len[1] == x);
		assert(pool[R.a].dat.len[0] == x && pool[R.a].dat.len[1] == 0);
		rep(t, M){
    		if(pool[L.b].dat.h[1][t] != pool[R.a].dat.h[0][t]){
    			pool[nxt_id++].bad = 1;
    			return nxt_id-1;
    		}
		}
		return merge(L.a, R.b);
	}
	return merge(l, r);
}
const int sz = (1<<17);
int n, k, seg[(1<<18)], a[(1<<17)];
void update(int i, int v){
	if(v) pool[i+1] = nd(v);
	seg[i + sz-1] = (v?i+1:0);
}
void update_after(int i, int v){
	pool[nxt_id++] = nd(v);
	seg[i + sz-1] = nxt_id - 1;
	i += sz-1;
	while(i){
		i = (i-1)/2;
		seg[i] = merge0(seg[i*2+1], seg[i*2+2]);
	}
}
void upd(){
	for(int i=sz-2;i>=0;i--){
		seg[i] = merge0(seg[i*2+1], seg[i*2+2]);
	}
}
void check(int k, int l, int r){
    if(l == r) return;
    check(k*2+1, l, (l+r)/2);
    check(k*2+2, (l+r)/2+1, r);
}
int query(int a, int b, int k, int l, int r){
	if(r < a || b < l || a > b) return 0;
	if(a <= l && r <= b) return seg[k];
	int x = query(a, b, k*2+1, l, (l+r)/2);
	int y = query(a, b, k*2+2, (l+r)/2+1, r);
	return merge0(x, y);
}
int query(int a, int b){
	return query(a, b, 0, 0, sz-1);
}
void solve(){
	ll pp[M];
	rep(i, M){
		pp[i] = 1000000 + mt()%10000000;
		pr[i][0] = 1;
		rep(j, 100004){
			pr[i][j+1] = pr[i][j] * pp[i] % mod;
		}
	}
    cin >> n >> k;
	repn(i, n) cin >> a[i];
	rep(i, sz) update(i, a[i]);
	nxt_id = sz+1;
	upd();
	int q; cin >> q;
	while(q--){
		if(nxt_id > SZ-500000){
			rep(i, sz) update(i, a[i]);
			nxt_id = sz+1;
			upd();
		}
		int ty, x, y; cin >> ty >> x >> y;
		if(ty == 1){
			a[x] = y;
			update_after(x, y);
		}
		else{
			auto ret = query(x, y);
			if(pool[ret].bad == false && pool[ret].dat.len[0] == 0 && pool[ret].dat.len[1] == 0){
				cout << "Yes" << '\n';
			}
			else{
				cout << "No" << '\n';
			}
		}
	}
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}