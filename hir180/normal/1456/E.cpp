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
const ll inf = 1e18;
ll dp[52][52][52][2][2];
ll rui[52][52][2][2];
int n, k;
ll a[55], b[55], c[55];
bool ok[55][55][2];
ll tmp[55][2], mn, mx;
ll val[55][55][2];
void make(ll a, ll b, ll k, ll l, ll r, int id, int sz){
	if(r < a || b < l) return;
	if(a <= l && r <= b){
		ll M;
		M = mn ^ l;
		if(M == 0 || __lg(M) <= sz){
		    ok[id][sz][0] = 1;
		    val[id][sz][0] = l;
		}
		M = mx ^ l;
		if(M == 0 || __lg(M) <= sz){
		    ok[id][sz][1] = 1;
		    val[id][sz][1] = l;
		}
		return;
	}
	make(a, b, k*2+1, l, (l+r)/2, id, sz-1);
	make(a, b, k*2+2, (l+r)/2+1, r, id, sz-1);
}
ll get(int ty, int za, ll val, int pos){
	if(za <= 0 || za > n) return 0;
	val ^= (ty==0?a[za]:b[za]);
	if( ((val>>pos)&1) ) return c[pos];
	else return 0;
}
ll get2(int za, int ty, int za2, int ty2, int pos){
	ll x = val[za][pos][ty];
	ll y = val[za2][pos][ty2];
	assert(ok[za][pos][ty] && ok[za2][pos][ty2]);
	if( ( ((x^y)>>pos) & 1) ) return c[pos];
	else return 0;
}
void solve(){
	cin >> n >> k;
	repn(i, n){
		cin >> a[i] >> b[i];
		mn = a[i], mx = b[i];
		make(a[i], b[i], 0, 0, (1LL<<k)-1, i, k);
	}
	rep(i, k) cin >> c[i];
	rep(a, 52) rep(b, 52) rep(c, 52) rep(d, 2) rep(e, 2){
		dp[a][b][c][d][e] = inf;
		rui[a][b][d][e] = inf;
	}
	repn(i, n+1) rep(a, 2) rep(b, 2) rui[i][i-1][a][b] = 0;
	for(int mx=k;mx>=0;mx--){
		repn(beg, n){
			rep(lv, 2){
				rep(i, 55) rep(j, 2) tmp[i][j] = inf;
				for(int x=beg;x<=n;x++){
					rep(y, 2){
						if(ok[x][mx][y] == false) continue;
						tmp[x][y] = rui[beg][x-1][lv][y] + get(lv, beg-1, val[x][mx][y], mx);
					}
				}
				for(int x=beg;x<=n;x++){
					rep(y, 2){
						if(tmp[x][y] == inf) continue;
						for(int nxt=x+1;nxt<=n;nxt++){
							rep(z, 2){
								if(ok[nxt][mx][z] == false) continue;
								chmin(tmp[nxt][z], tmp[x][y] + rui[x+1][nxt-1][y][z] + get2(x, y, nxt, z, mx));
							}
						}
					}
				}
				for(int x=beg;x<=n;x++){
					rep(y, 2){
						for(int nxt=x;nxt<=n;nxt++){
							rep(z, 2){
								chmin(dp[beg][nxt][mx][lv][z], tmp[x][y] + rui[x+1][nxt][y][z] + get(z, nxt+1, val[x][mx][y], mx));
							}
						}
					}
				}
			}
		}
		repn(i, n) for(int j=i-1;j<=n;j++) rep(aa, 2) rep(ab, 2){
			ll add = 0;
			if(i-1 == 0 || j+1 == n+1);
			else{
				ll u = (aa == 0?a[i-1]:b[i-1]);
				ll v = (ab == 0?a[j+1]:b[j+1]);
				u ^= v;
				if( (u & (1LL<<mx)) ) add = c[mx];
			}
			rui[i][j][aa][ab] += add;
			chmin(rui[i][j][aa][ab], dp[i][j][mx][aa][ab]);
		}
	}
	ll ans = 1e18;
	rep(a, 2) rep(b, 2) rep(c, k+1){
		chmin(ans, dp[1][n][c][a][b]);
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