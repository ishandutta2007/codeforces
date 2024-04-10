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
struct RMQ{
	#define ss (1<<19)
	int seg[ss], sum[ss], sz;
	void init(int n){
		sz = 1;
		while(sz < n) sz <<= 1;
		rep(i, 2*sz) seg[i] = 0, sum[i] = 0;
	}
	void update(int a,int b,int k,int l,int r, int v){
		if(r<a || b<l || a>b) return;
		if(a <= l && r <= b && seg[k] != -1){
			seg[k] = v;
			sum[k] = v * (r-l+1);
			return;
		}
		if(seg[k] != -1){
			seg[k*2+1] = seg[k];
			seg[k*2+2] = seg[k];
			sum[k*2+1] = seg[k] * (r-l+1) / 2;
			sum[k*2+2] = seg[k] * (r-l+1) / 2;
		}
		update(a, b, k*2+1, l, (l+r)/2, v);
		update(a, b, k*2+2, (l+r)/2+1, r, v);
		sum[k] = sum[k*2+1] + sum[k*2+2];
		if(seg[k*2+1] != -1 && seg[k*2+2] != -1 && seg[k*2+1] == seg[k*2+2]){
			seg[k] = seg[k*2+1];
		}
		else{
			seg[k] = -1;
		}
	}
	int query(int a,int b,int k,int l,int r){
		if(r<a || b<l || a>b) return 0;
		if(a<=l && r<=b) return sum[k];
		else{
			if(seg[k] != -1){
				seg[k*2+1] = seg[k];
				seg[k*2+2] = seg[k];
				sum[k*2+1] = seg[k] * (r-l+1) / 2;
				sum[k*2+2] = seg[k] * (r-l+1) / 2;
			}
			int vl=query(a,b,k*2+1,l,(l+r)/2);
			int vr=query(a,b,k*2+2,(l+r)/2+1,r);
			return vl + vr;
		}
	}
	int query(int a, int b){
		return query(a, b, 0, 0, sz-1);
	}
	void update(int a, int b, int v){
		update(a, b, 0, 0, sz-1, v);
	}
}seg;

void solve(){
	int n, q; cin >> n >> q;
	string s, t; cin >> s >> t;
	vc<int>l(q), r(q);
	rep(i, q){
		cin >> l[i] >> r[i];
		l[i] --;
		r[i] --;
	}
	seg.init(n+2);
	rep(i, n){
		seg.update(i, i, (t[i]-'0'));
	}
	for(int i=q-1;i>=0;i--){
		int a = seg.query(l[i], r[i]);
		if( (r[i]-l[i]+1)%2 == 0 && a == (r[i]-l[i]+1) / 2){
			cout << "NO" << '\n';
			return;
		}
		if(a > (r[i]-l[i]+1)/2){
			seg.update(l[i], r[i], 1);
		}
		else{
			seg.update(l[i], r[i], 0);
		}
	}
	rep(i, s.size()){
		int a = seg.query(i, i);
		if(s[i]-'0' != a){
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
	return;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; cin >> t;
	while(t--) solve();
}