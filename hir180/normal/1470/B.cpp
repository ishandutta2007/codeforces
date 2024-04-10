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
#define a first
#define b second
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
const ll mod = 1000000007;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
int pr[1000005];
void solve(){
	int n; cin >> n;
	int mx0 = 0, mx1 = 0;
	map<int, int>M;
	rep(i, n){
		int a; cin >> a;
		int A = a;
		vc<int>v;
		while(a != 1){
			v.pb(pr[a]);
			a /= pr[a];
		}
		int aa = 1;
		for(auto at:v){
			int c = 0;
			while(A%at == 0){
				A/=at;
				c++;
			}
			if(c&1) aa = aa * at;
		}
		M[aa]++;
	}
	for(auto at:M) chmax(mx0, at.b);
	int v = M[1];
	for(auto at:M){
		if(at.a != 1 && at.b%2 == 0) v += at.b;
	}
	mx1 = mx0;
	chmax(mx1, v);
	
	int q; cin >> q;
	while(q--){
		ll w; cin >> w;
		if(w == 0) cout << mx0 << '\n';
		else cout << mx1 << '\n';
	}
}
signed main(){
	for(int i=2;i<1000005;i++){
		if(pr[i]) continue;
		for(int j=1;i*j<1000005;j++) pr[i*j] = i;
	}
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; cin >> t;
	while(t--) solve();
}