//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define int long long
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
const ll inf = 1000000000000000001LL;
template<class T>
void add(T&a,T b){
	a+=b;
}
template<typename F, typename T>
struct segtree{
	int sz;
	vector<T>seg;
	const F f;
	const T e;
	segtree(int n, const F f, const T e): f(f), e(e) {
		sz = 1;
		while(sz < n) sz <<= 1;
		seg.assign(2*sz, e);
	}
	void init(int n){
		sz = 1;
		while(sz < n) sz <<= 1;
		seg.assign(2*sz, e);
	}
	//ok...
	void update(int a, T p, bool ok){
		a += sz-1;
		if(ok) seg[a] = f(seg[a], p);
		else seg[a] = p;
		while(a){
			a = (a-1)/2;
			seg[a] = f(seg[a*2+1], seg[a*2+2]);
		}
	}
	void make(vector<T>a){
		rep(i, a.size()) seg[i+sz-1] = a[i];
		for(int i=sz-2;i>=0;i--) seg[i] = f(seg[i*2+1], seg[i*2+2]);
	}
	T query(int a, int b){
		a += sz-1, b += sz-1;
		T L = e, R = e;
		while(a <= b){
			if((a&1) == 0) { L = f(L, seg[a++]); }
			if((b&1) == 1) { R = f(seg[b--], R); }
			if(a > b) break;
			a = (a-1) >> 1;
			b = (b-1) >> 1;
		}
		return f(L, R);
	}
	int find_left(int a, int b, int k, int l, int r, T v){
		if(r < a || b < l) return INF;
		if(a <= l && r <= b){
			if(f(seg[k], v) == seg[k]){
				while(k < sz-1){
					if(f(seg[k*2+1], v) == seg[k*2+1]) k = k*2+1;
					else k = k*2+2;
				}
				return k - (sz-1);
			}
			return INF;
		}
		int ret = find_left(a, b, k*2+1, l, (l+r)/2, v);
		if(ret != INF) return ret;
		return find_left(a, b, k*2+2, 1+(l+r)/2, r, v);
	}
	//[a, b]f(*, v)=** INF
	int find_left(int a, int b, T v){
		return find_left(a, b, 0, 0, sz-1, v);
	}
};
//
//f, e
//segtree<decltype(f), decltype(e)>seg(, f, e); 

auto f = [](int a, int b){ return min(a, b); };
int e = 1e18;

int n, c, q, p[30005];
ll dp[30005][5];
//use, id, - / 0 / +
ll val[5][30005][3], rui[5][30005];
vector<segtree<decltype(f), decltype(e)>>seg(5, segtree<decltype(f), decltype(e)>((1<<15), f, e));

void solve(){
	memset(val, 0, sizeof(val));
	memset(rui, 0, sizeof(rui));
	cin >> n >> c >> q;
	rep(i, 5) seg[i].init(n+1);
	repn(i, n) cin >> p[i];
	rep(x, c+1){
		repn(i, n){
			repn(y, c-x+1){
				if(i+y-1 > n) continue;
				int id = 1;
				if(p[i] > p[i+y-1]) id = 0;
				else if(p[i] < p[i+y-1]) id = 2;
				
				add(val[x][i][id], dp[n+1-i-y][c-x-y+1]);
			}
		}
		repn(i, n){
			rui[x][i] = rui[x][i-1];
			rui[x][i] += val[x][i][0];
			seg[x].update(i, rui[x][i] + val[x][i][1], 1);
		}
	}
	rep(i, q){
		int pos;
		ll rem;
		cin >> pos >> rem;
		if(dp[n][c] < rem){
			cout << -1 << '\n';
			continue;
		}
		int use = 0, id = 1;
		vc<P>flip;
		
		while(1){
			ll cur = rui[use][id-1];
			int x = lower_bound(rui[use]+id, rui[use]+n+1, cur+rem) - rui[use];
			int y = seg[use].find_left(id, n, rem+cur-1);
			chmin(x, y);
			if(x > n) break;
			
			rem -= (rui[use][x-1] - rui[use][id-1]);
			id = x;
			vector<P>vec;
			repn(y, 5){
				if(id+y-1 > n || use+y-1 > c) continue;
				vec.pb(mp(p[id+y-1], dp[n+1-id-y][c-(use+y-1)]));
			}
			sort(all(vec));
			rep(i, vec.size()){
				if(rem > vec[i].sc){
					rem -= vec[i].sc;
					continue;
				}
				assert(vec[i].fi != p[id]);
				rep(y, 5){
					if(p[id+y] == vec[i].fi){
						flip.pb(mp(id, id+y));
						id += y+1;
						use += y;
						goto nxt;
					}
				}
			}
			assert(0);
			nxt:;
		}
		rep(i, flip.size()){
			if(flip[i].fi <= pos && pos <= flip[i].sc){
				pos = flip[i].fi + flip[i].sc - pos;
			}
		}
		cout << p[pos] << '\n';
	}
}
signed main(){
	dp[0][0] = 1;
	for(int i=1;i<=30000;i++){
		rep(j, 5) for(int k=1;j+k-1<=4 && k<=i;k++){
			dp[i][j+k-1] += dp[i-k][j];
		}
	}
	rep(i, 30005){
		rep(j, 4){
			add(dp[i][j+1], dp[i][j]);
		}
	}
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; cin >> t;
	while(t--) solve();
}