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
int n, k;
string ff[505];
int rui[505][505], f[505][505], col[505][505];
int tmp[350005], cnt[350005];
int par[350005],ran[350005],sz[350005];

void init(){ for(int i=0;i<350005;i++) par[i] = i; }
int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
void unite(int x,int y){
	x = find(x); y = find(y); if(x==y) return;
	if(ran[x] < ran[y]) par[x] = y;
	else{
		par[y] = x;
		if(ran[x] == ran[y]) ran[x]++;
	}
}
bool same(int x,int y){ return find(x)==find(y); }
int S;
inline void add(int ty){
	tmp[ty] ++;
	if(tmp[ty] == 1) S += sz[ty];
}
inline void rem(int ty){
	tmp[ty] --;
	if(tmp[ty] == 0) S -= sz[ty];
}
int rng(int a, int b, int c, int d){
	return rui[c][d] - rui[a-1][d] - rui[c][b-1] + rui[a-1][b-1];
}
void solve(){
	cin >> n >> k;
	rep(i, n){
		cin >> ff[i];
		rep(j, n){
			f[i+1][j+1] = (ff[i][j] == '.');
		}
	}
	init();
	repn(i, n){
		repn(j, n){
			if(i > 1 && f[i][j] == 1 && f[i-1][j] == 1) unite(i*501+j, i*501+j-501);
			if(j > 1 && f[i][j] == 1 && f[i][j-1] == 1) unite(i*501+j, i*501+j-1);
		}
	}
	repn(i, n) repn(j, n) {
		if(f[i][j] == 0) col[i][j] = 0;
		else{
			col[i][j] = find(i*501 + j);
			sz[col[i][j]] ++;
		}
		rui[i][j] = rui[i-1][j] + rui[i][j-1] - rui[i-1][j-1] + 1 - f[i][j];
	}
    /*cout << rui[n][n] << endl;
    repn(i, n) {
        repn(j, n) cout << col[i][j] << " ";
        cout << endl;
    }*/
	int ans = 0;
	for(int i=1;i<=n+1-k;i++){
		memset(tmp, 0, sizeof(tmp));
		S = 0;
		for(int x=i-1;x<=i+k;x++) for(int y=1;y<=k+1;y++){
			if(x == 0 || x == n+1 || y == n+1 || mp(x, y) == mp(i-1, k+1) || mp(x, y) == mp(i+k, k+1)) continue;
			add(col[x][y]);
		}
		for(int j=1;j<=n+1-k;j++){
			chmax(ans, rng(i, j, i+k-1, j+k-1) + S);
			if(j == n+1-k) break;
			if(col[i-1][j]) rem(col[i-1][j]);
			if(col[i+k][j]) rem(col[i+k][j]);
			for(int a=i;a<=i+k-1;a++) if(col[a][j-1]) rem(col[a][j-1]);
			
			if(col[i-1][j+k]) add(col[i-1][j+k]);
			if(col[i+k][j+k]) add(col[i+k][j+k]);
			for(int a=i;a<=i+k-1;a++) if(col[a][j+k+1]) add(col[a][j+k+1]);
		}
	}
	cout << ans << endl;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}