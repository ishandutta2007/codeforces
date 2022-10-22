#include <bits/stdc++.h>
 
//#include <unistd.h>
//#include <iostream>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
#define int ll
 
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
//const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

ll dist[3001][3001];
ll sub[3001][3001];

vector<vector<pii>> dist2p;
vll G;

void dfs(int now, int par, int root, int depth) {
  sub[root][now] = 1;
  dist[root][now] = depth;
  if (root < now) {
    dist2p[depth].emplace_back(root, now);
  }
  for (int ch: G[now]) {
    if (ch == par) continue;
    dfs(ch, now, root, depth + 1);
    sub[root][now] += sub[root][ch];
  }
}

ll dp[3001][3001];

signed main() {
  fio();
  int n;
  cin >> n;
  G.resize(n);
  dist2p.resize(n);
  vector<pii> ab;
  rep (i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
    ab.emplace_back(u, v);
  }
  //DEBUG_VEC(ab);

  rep (root, n) {
    dfs(root, -1, root, 0);
  }

  rep (i, dist2p[1].size()) {
    pii uv = dist2p[1][i];
    int u = uv.first, v = uv.second;
    dp[u][v] = dp[v][u] = sub[v][u] * sub[u][v];
  }

  for (int d = 1; d < n; d++) {
    rep (i, dist2p[d].size()) {
      pii uv = dist2p[d][i];
      rep (_, 2) {
        int u = uv.first, v = uv.second;
        for (int nu: G[u]) {
          if (dist[nu][v] < dist[u][v]) continue;
          chmax(dp[nu][v], dp[u][v] + sub[v][nu] * sub[u][v]);
        }
        for (int nv: G[v]) {
          if (dist[u][nv] < dist[u][v]) continue;
          chmax(dp[u][nv], dp[u][v] + sub[v][u] * sub[u][nv]);
        }
        swap(uv.first, uv.second);
      }
    }
  }

  ll ans = 0;
  rep (i, n) {
    rep (j, n) {
      chmax(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
}