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
#define rng(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
#define si(x) (int)(x.size())

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
int n, m, q;
int a[200005], b[200005];
int t[500005], pos[500005], x[500005];
struct S{
	int sz;
	vc<int>za;
	vc<ll>seg;
	S(){}
	S(vc<int>z){
		za = z;
		sz = 1;
		while(sz < si(za)+1) sz <<= 1;
		seg.assign(2*sz, 0LL);
	}
	void update(int val, int add){
		int id = POSL(za, val);
		assert(id < za.size() && za[id] == val);
		id += sz-1; seg[id] += add;
		while(id){
			id = (id-1) / 2;
			seg[id] = seg[id*2+1] + seg[id*2+2];
		}
	}
	ll query(int a, int b, int k, int l, int r){
		if(r < a || b < l || a > b) return 0LL;
		if(a <= l && r <= b) return seg[k];
		return query(a, b, k*2+1, l, (l+r)/2) + query(a, b, k*2+2, (l+r)/2+1, r);
	}
	ll query(int a, int b){
		return query(a, b, 0, 0, sz-1);
	}
	ll get_sum(int v){
		int a = POSL(za, v);
		return query(a, sz-1);
	}
}cnta, suma, cntb, sumb;
multiset<int>vala, valb;
vc<int>za, zb;
ll nonzero(ll v, ll k){
	ll ret = suma.seg[0] + 1LL*cnta.seg[0] * (k - v);
	ret -= sumb.seg[0] + 1LL*cntb.seg[0] * (k - v);
	return ret;
}
ll zero(ll v, ll k){
	vala.erase(vala.find(v));
	cnta.update(v, -1);
	suma.update(v, -v);
	ll S = sumb.get_sum(v-k);
	ll C = cntb.get_sum(v-k);
	S -= C * (v-k);
	ll zan = k-v;
	auto it = valb.begin();
	chmax(zan, -(*it));
	ll ret;
	if(vala.empty()){
		ret = k - S;
	}
	else{
		auto it = vala.begin();
		chmax(zan, -(*it));
		ret = k - S + suma.get_sum(-zan) + 1LL*cnta.get_sum(-zan)*zan;
	}
	vala.insert(v);
	cnta.update(v, 1);
	suma.update(v, v);
	return ret;
}
ll standard(ll k){
    auto it = valb.end(); it--;
	ll v = *it;
	ll S = sumb.get_sum(v-k);
	ll C = cntb.get_sum(v-k);
	S -= C * (v-k);
	ll zan = k-v;
	it = valb.begin();
	chmax(zan, -(*it));
	ll ret;
	it = vala.begin();
	chmax(zan, -(*it));
	ret = - S + suma.get_sum(-zan) + 1LL*cnta.get_sum(-zan)*zan;
	return ret;
}
void solve(){
	cin >> n >> m >> q;
	repn(i, n){
		cin >> a[i];
		vala.insert(a[i]);
		za.pb(a[i]);
	}
	repn(i, m){
		cin >> b[i];
		valb.insert(b[i]);
		zb.pb(b[i]);
	}
	rep(i, q){
		int ty; cin >> ty;
		if(ty == 1){
			cin >> pos[i] >> x[i];
			za.pb(x[i]);
		}
		else if(ty == 2){
			cin >> pos[i] >> x[i];
			zb.pb(x[i]);
		}
		else{
			cin >> x[i];
		}
		t[i] = ty;
	}
	SORT(za); ERASE(za);
	SORT(zb); ERASE(zb);
	cnta = S(za);
	suma = S(za);
	cntb = S(zb);
	sumb = S(zb);
	repn(i, n){
		cnta.update(a[i], 1);
		suma.update(a[i], a[i]);
	}
	repn(i, m){
		cntb.update(b[i], 1);
		sumb.update(b[i], b[i]);
	}
	rep(i, q){
		if(t[i] == 1){
			vala.erase(vala.find(a[pos[i]]));
			cnta.update(a[pos[i]], -1);
			suma.update(a[pos[i]], -a[pos[i]]);
			a[pos[i]] = x[i];
			vala.insert(a[pos[i]]);
			cnta.update(a[pos[i]], 1);
			suma.update(a[pos[i]], a[pos[i]]);
		}
		else if(t[i] == 2){
			valb.erase(valb.find(b[pos[i]]));
			cntb.update(b[pos[i]], -1);
			sumb.update(b[pos[i]], -b[pos[i]]);
			b[pos[i]] = x[i];
			valb.insert(b[pos[i]]);
			cntb.update(b[pos[i]], 1);
			sumb.update(b[pos[i]], b[pos[i]]);
		}
		else{
			int mn = INF;
			chmin(mn, *vala.begin());
			chmin(mn, *valb.begin());
			//never reset
			ll ans = -1e18;
			chmax(ans, nonzero(mn, x[i]));
			auto it = vala.upper_bound(mn + x[i]);
			if(it != vala.begin()){
			    it --;
			    chmax(ans, nonzero((*it), x[i]));
			}
			auto it2 = valb.upper_bound(mn + x[i]);
			if(it2 != valb.begin()){
    			it2 --;
    			chmax(ans, nonzero((*it2), x[i]));
			}
			//reset
			it2 = valb.end(); it2--;
			ll mx = *it2;
			it = vala.upper_bound(mx + x[i]);
			if(it != vala.end()){
				chmax(ans, zero((*it), x[i]));
			}
			it = vala.upper_bound(mx + x[i]);
			if(it != vala.begin()){
				it--;
				chmax(ans, zero((*it), x[i]));
			}
			//standard style
			chmax(ans, standard(x[i]));
			cout << ans << '\n';
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