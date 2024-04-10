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
#define fi first
#define b second
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
//mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
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
ll pw[20];
const int sz = (1<<17);
pair<ll, int>seg[(1<<18)], mn[(1<<18)];
ll lazy[(1<<18)], lazy2[(1<<18)];

void push(int k){
	if(lazy[k] == 0 && lazy2[k] == 0) return ;
	if(lazy2[k]){
		repn(i, 2){
			mn[k*2+i] = mp(0, 0);
			mn[k*2+i].sc = lower_bound(pw, pw+10, lazy2[k]) - pw;
			mn[k*2+i].fi = pw[mn[k*2+i].sc] - lazy2[k];
			
			seg[k*2+i] = mn[k*2+i];
			lazy2[k*2+i] = lazy2[k];
		}
		lazy[k] = lazy2[k] = 0;
	}
	else{
		repn(i, 2){
			mn[k*2+i].fi -= lazy[k];
			if(mn[k*2+i].fi < 0){
				ll v = pw[mn[k*2+i].sc] - mn[k*2+i].fi;
				while(pw[mn[k*2+i].sc] < v) mn[k*2+i].sc ++;
				mn[k*2+i].fi = pw[mn[k*2+i].sc] - v;
			}
			if(seg[k*2+i].fi >= 0){
				seg[k*2+i] = mn[k*2+i];
			}
			if(lazy2[k*2+i]) lazy2[k*2+i] += lazy[k];
			else lazy[k*2+i] += lazy[k];
		}
		lazy[k] = 0;
	}
}
void update(int k){
	mn[k] = min(mn[k*2+1], mn[k*2+2]);
	if(seg[k*2+1] == seg[k*2+2]) seg[k] = seg[k*2+1];
	else seg[k] = mp(-1, -1);
}
void upd(){
	for(int i=sz-2;i>=0;i--) update(i);
}
ll get(int a, int k, int l, int r){
	if(l == r){
		assert(mn[k] == seg[k]);
		return pw[mn[k].sc] - mn[k].fi;
	}
	push(k);
	if(a <= (l+r)/2) return get(a, k*2+1, l, (l+r)/2);
	return get(a, k*2+2, (l+r)/2+1, r);
}
void add(int a, int b, int k, int l, int r, ll v){
	if(r < a || b < l || a > b) return;
	if(a <= l && r <= b && (mn[k].fi >= v || seg[k].fi >= 0)){
		mn[k].fi -= v;
		if(mn[k].fi < 0){
			ll v = pw[mn[k].sc] - mn[k].fi;
			while(pw[mn[k].sc] < v) mn[k].sc ++;
			mn[k].fi = pw[mn[k].sc] - v;
		}
		if(seg[k].fi != -1) seg[k] = mn[k];
		if(lazy2[k]) lazy2[k] += v;
		else lazy[k] += v;
		return;
	}
	push(k);
	add(a, b, k*2+1, l, (l+r)/2, v);
	add(a, b, k*2+2, (l+r)/2+1, r, v);
	update(k);
}
void st(int a, int b, int k, int l, int r, ll v){
	if(r < a || b < l || a > b) return;
	if(a <= l && r <= b){
		mn[k] = mp(0, 0);
		mn[k].sc = lower_bound(pw, pw+10, v) - pw;
		mn[k].fi = pw[mn[k].sc] - v;
		
		seg[k] = mn[k];
		lazy2[k] = v;
		lazy[k] = 0;
		return;
	}
	push(k);
	st(a, b, k*2+1, l, (l+r)/2, v);
	st(a, b, k*2+2, (l+r)/2+1, r, v);
	update(k);
}
pair<ll, int>query(int a, int b, int k, int l, int r){
    if(r < a || b < l || a > b) return mp(1e18, INF);
	if(a <= l && r <= b){
		return mn[k];
	}
	push(k);
	auto L = query(a, b, k*2+1, l, (l+r)/2);
	auto R = query(a, b, k*2+2, (l+r)/2+1, r);
	return min(L, R);
}
void st(int a, int b, ll v){ st(a, b, 0, 0, sz-1, v); }
ll get(int k){ return get(k, 0, 0, sz-1); }
void add(int a, int b, ll v){
	add(a, b, 0, 0, sz-1, v);
	while(1){
		auto at = query(a, b, 0, 0, sz-1);
		if(at.fi) return;
		add(a, b, 0, 0, sz-1, v);
	}
}


int n, q, t[100005];
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	pw[0] = 1;
	for(int i=1;i<=19;i++) pw[i] = pw[i-1] * 42LL;
	
	repn(i, n){
		cin >> t[i];
		rep(x, 20){
			if(pw[x] >= t[i]){
				mn[sz-1+i] = mp(pw[x]-t[i], x);
				seg[sz-1+i] = mn[sz-1+i];
				break;
			}
		}
	}
	upd();
	rep(i, q){
		int ty; cin >> ty;
		if(ty == 1){
			int pos; cin >> pos;
			cout << get(pos) << '\n';
		}
		else{
			int a, b; ll x; cin >> a >> b >> x;
			if(ty == 2){
				st(a, b, x);
			}
			else{
				add(a, b, x);
			}
		}
	}
}