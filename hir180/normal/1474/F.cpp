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
#define eb emplace_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
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
#define si(x) (long long)(x.size())

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
	return os<<"{"<<p.a<<","<<p.b<<"}";
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
const ll mod = 998244353;
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
typedef vector<int> vi;
typedef vector<P> vp;
struct L_interpolation{
	int deg;
	vector<pair<ll,ll> >pts;
	ll ff[305];
	L_interpolation(){}
	//must call init first!!!!
	//vec-x (: )
	void init(vector<pair<ll,ll> >vec, int n = -1){
		SORT(vec);
		ERASE(vec);
		if(n == -1) n = si(vec)-1;
		assert(vec.size() > n);
		vec.resize(n+1);
		this->deg = n;
		this->pts = vec;
		ff[0] = 1;
		for(int i=1;i<305;i++) ff[i] = ff[i-1]*1LL*i%mod;
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
	//return f(x)
	//O(N log N)
	ll f(ll x){
		vector<ll>up;
		ll M = 1;
		rep(i,deg+1){
			if(pts[i].fi == x) return pts[i].sc;
			up.pb(x-pts[i].fi);
			M *= (x-pts[i].fi);
			M %= mod;
		}
		//vec.size() <= 1 -> broken
		ll d = pts[1].fi-pts[0].fi,ret = 0;
		rep(i,deg+1){
			ll add = pts[i].sc;
			add = add*M%mod;
			add = add*(this->modpow((x-pts[i].fi)%mod,mod-2))%mod;
			//plus i * minus n-i
			add = add*(this->modpow(this->modpow(d,deg),mod-2))%mod;
			add = add*(this->modpow(ff[i],mod-2))%mod;
			add = add*(this->modpow(ff[deg-i],mod-2))%mod;
			if((deg-i)%2 == 1) add = (mod-add)%mod;
			else add = (add+mod)%mod;
			ret += add;
		}
		return ret%mod;
	}
};
int n;
ll d[55], dm;
vc<ll>v;
;

P calc(int lb, vc<pair<ll,ll>>I){
	vc<pair<P, vp>>cur;
	cur.pb(mp(mp(lb, 1e12), vp({mp(lb, 0)})));
	rep(i, n){
		if(max(I[i].a, I[i].b) < lb) continue;
		chmax(I[i].a, lb);
		chmax(I[i].b, lb);
		vi za; vc<pair<P, vp>>nxt;
		for(auto at:cur){
			za.pb(at.a.a);
			za.pb(at.a.b+1);
		}
		za.pb(min(I[i].a, I[i].b));
		za.pb(max(I[i].a, I[i].b)+1);
		if(min(I[i].a, I[i].b) == lb){
			za.pb(lb+1);
		}
		SORT(za); ERASE(za);
		vp zan[205];
		rep(i, cur.size()){
			rep(j, za.size()-1){
				if(cur[i].a.a <= za[j] && za[j+1]-1 <= cur[i].a.b){
					zan[j] = cur[i].b;
				}
			}
		}
		//dmp(za.size());
		//rep(i, za.size()-1) dmp(zan[i]);
		if(I[i].a <= I[i].b){
			rep(j, za.size()-1){
				if(min(I[i].a, I[i].b) <= za[j] && za[j+1]-1 <= max(I[i].a, I[i].b)){
					ll uv = 0;
					int sz = zan[j].size() + 1;
					if(j != 0){
						L_interpolation z;
						if(min(I[i].a, I[i].b) == za[j]){
							z.init(zan[j-1]);
							uv = z.f(za[j]-1);
							if(sz < si(zan[j-1])) sz = si(zan[j-1]);
						}
						else{
							z.init(nxt[j-1].b);
							uv = z.f(za[j]-1);
							if(sz < si(nxt[j-1].b)) sz = si(nxt[j-1].b);
						}
					}
					sz += 1;
					if(sz > za[j+1] - za[j]) sz = za[j+1] - za[j];
					vp N;
					L_interpolation zz;
					zz.init(zan[j]);
					for(int i=za[j];i<za[j]+sz;i++){
						uv += zz.f(i);
						uv %= mod;
						if(za[j] == lb) uv = (uv+1)%mod;
						N.pb(mp(i, uv%mod));
					}
					nxt.pb(mp(mp(za[j], za[j+1]-1), N));
				}
				else{
					nxt.pb(mp(mp(za[j], za[j+1]-1), zan[j]));
				}
			}
			swap(cur, nxt);
		}
		else{
			rep(j, za.size()-1){
				if(min(I[i].a, I[i].b) <= za[j] && za[j+1]-1 <= max(I[i].a, I[i].b)){
					ll uv = 0;
					int sz = zan[j].size();
					if(j != 0){
						L_interpolation z;
						z.init(zan[j-1]);
						uv = z.f(za[j]-1);
						if(sz < si(zan[j-1])) sz = si(zan[j-1]);
					}
					sz += 1;
					if(sz > za[j+1] - za[j]) sz = za[j+1] - za[j];
					vp N;
					L_interpolation zz;
					zz.init(zan[j]);
					for(int i=za[j];i<za[j]+sz;i++){
						ll C = zz.f(i);
						uv += C;
						uv %= mod;
						if(za[j] == lb) uv = (uv+1)%mod;
						N.pb(mp(i, uv));
						uv = C;
					}
					nxt.pb(mp(mp(za[j], za[j+1]-1), N));
				}
				else{
					nxt.pb(mp(mp(za[j], za[j+1]-1), zan[j]));
				}
			}
			swap(cur, nxt);
		}
	}
	L_interpolation las;
	for(int i=cur.size()-1;i>=0;i--){
		bool ok = 0;
		for(auto at:cur[i].b) if(at.b) ok = 1;
		if(!ok) continue;
		las.init(cur[i].b);
		return mp(cur[i].a.b-lb+1, las.f(cur[i].a.b));
	}
}

void solve(){
	cin >> n >> dm;
	vc<ll>v;
	repn(i, n) {
		ll x; cin>>x;
		if(x == 0) continue;
		if(v.empty()) v.pb(x);
		else if( (v.back()<0) == (x<0) ) v[v.size()-1] += x;
		else v.pb(x);
	}
	n = v.size();
	if(n == 0){
		cout << 1 << " " << 1 << endl;
		return;
	}
	if(n == 1){
		if(v[0] > 0){
			cout << v[0]+1 << " " << 1 << endl;
		}
		else{
			cout << 1 << " " << (1-v[0])%mod << endl;
		}
		return;
	}
	ll curr = 0;
	vc<ll>cand;
	vp I;
	rep(i, n){
		cand.pb(curr);
		ll L = curr, R = curr + v[i];
		ll RR = R;
		if(L < R) RR--; else RR ++;
		I.pb(mp(L, RR));
		curr = R;
	}
	I[n-1].b = curr;
	cand.pb(curr);
	SORT(cand); ERASE(cand);
	P zan = mp(-1, 0);
	
	for(auto at:cand){
		P p = calc(at, I);
		dmp(at);
		dmp(p);
		if(zan.a > p.a) continue;
		if(zan.a < p.a) zan = p;
		else zan.b += p.b;
	}
	cout << zan.a << " " << (zan.b%mod+mod)%mod << endl;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}