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

void solve(){
	int n, x, y; cin >> n >> x >> y;
	vc<int>p(n+1);
	vc<vc<int>>pos(n+2);
	vc<int>in(n+2);
	repn(i, n){
		cin >> p[i];
		pos[p[i]].pb(i);
		in[p[i]] = 1;
	}
	int pat;
	repn(i, n+1) if(!in[i]) pat = i;
	priority_queue<P>que;
	repn(i, n+1) que.push(mp((int)(pos[i].size()), i));
	vc<int>ans(n+1);
	rep(_, x){
		auto q = que.top(); que.pop();
		ans[pos[q.b].back()] = q.b;
		pos[q.b].pop_back();
		que.push(mp(q.a-1, q.b));
	}
	vc<P>zan;
	int mx = 0;
	repn(i, n+1){
		for(auto at:pos[i]) zan.pb(mp(i, at));
		if(mx < pos[i].size()) mx = pos[i].size();
	}
	int lim = n-y;
	rep(i, zan.size()){
		ans[zan[i].b] = zan[(i+mx)%zan.size()].a;
		if(zan[i].a == zan[(i+mx)%zan.size()].a){
			ans[zan[i].b] = pat;
			lim--;
			if(lim < 0){
				o("NO");
				return;
			}
		}
	}
	repn(i, n) if(ans[i] != p[i] && ans[i] != pat && lim) {
		ans[i] = pat;
		lim--;
	}
	assert(lim == 0);
	o("YES");
	repn(i,n) cout << ans[i] << " ";
	cout << '\n';
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; cin >> t;
	while(t--) solve();
}