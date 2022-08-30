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
int n, m;
string s[1005];
int cnt[2][1005];
vc<int>pos[2][1005];
bool vis[1005][1005], bad[1005][1005];

void solve(){
	cin >> n >> m;
	rep(i, n) cin >> s[i];
	rep(i, n){
		rep(j, m){
			if(s[i][j] == '#'){
				cnt[0][i] ++;
				cnt[1][j] ++;
				pos[0][i].pb(j);
				pos[1][j].pb(i);
			}
		}
	}
	rep(i, 2)rep(j, 1005){
		if(pos[i][j].empty()) continue;
		int a = pos[i][j].back() - pos[i][j][0] + 1;
		int b = pos[i][j].size();
		if(a != b){
			cout << -1 << '\n'; return;
		}
		if(i == 0){
			rep(k, m) if(s[j][k] == '.') bad[j][k] = 1;
		}
		else{
			rep(k, n) if(s[k][j] == '.') bad[k][j] = 1;
		}
	}
	rep(i, n){
		rep(j, m) if(!bad[i][j]) goto nxt;
		cout << -1 << '\n'; return; nxt:;
	}
	rep(j, m){
		rep(i, n) if(!bad[i][j]) goto nxt2;
		cout << -1 << '\n'; return; nxt2:;
	}
	
	int ans = 0;
	rep(i, n){
		rep(j, m){
			if(s[i][j] == '#' && !vis[i][j]){
				ans++;
				queue<P>que; que.push(mp(i, j));
				while(!que.empty()){
					P p = que.front(); que.pop();
					if(vis[p.a][p.b]) continue;
					vis[p.a][p.b] = 1;
					int dx[4] = {0, 0, 1, -1};
					int dy[4] = {1, -1, 0, 0};
					rep(k, 4){
						int nx = p.a + dx[k];
						int ny = p.b + dy[k];
						if(0 <= nx && nx < n && 0 <= ny && ny < m && !vis[nx][ny] 
						&& s[nx][ny] == '#'){
							que.push(mp(nx, ny));
						}
					}
				}
			}
		}
	}
	cout << ans << '\n';
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}