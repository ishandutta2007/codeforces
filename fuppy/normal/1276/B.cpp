#include <bits/stdc++.h>

#include <unistd.h>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
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
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx_ori[4] = { -1,0, 1,0 }, dy_ori[4] = { 0,1,0,-1 };
int dx[4] = {0, 0, 0, 0}, dy[4] = {0, 0, 0, 0};
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
//const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

class UnionFind {
public:
  int n;
  vi par; //
  vi ran; //
  vi num; //
  int g; // group
 
  UnionFind(int _n) {
    n = _n;
    g = n;
    par.resize(n); ran.resize(n); num.resize(n);
    for (int i = 0; i < n; i++) {
      par[i] = i; ran[i] = 0; num[i] = 1;
    }
  }
 
  //
  int find(int x) {
    if (par[x] == x) {
      return x;
    }
    else {
      return par[x] = find(par[x]);
    }
  }
 
  //xy
  void unite(int x, int y) {
    x = find(x); y = find(y);
    int numsum = num[x] + num[y];
    if (x == y) {
      return;
    }
    if (ran[x]<ran[y]) {
      par[x] = y;
    }
    else {
      par[y] = x;
      if (ran[x] == ran[y]) {
        ran[x]++;
      }
    }
    num[x] = num[y] = numsum;
    g--;
  }
 
  //xy
  bool same(int x, int y) {
    return find(x) == find(y);
  }
 
};

void solve() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  a--; b--;
  vii G(n);
  rep (i, m) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  UnionFind uf(n);
  rep (u, n) {
    if (u == a) continue;
    for (int v: G[u]) {
      if (v == a) continue;
      uf.unite(u, v);
    }
  }

  int an = 0;
  rep (i, n) {
    if (i == a or i == b) continue;
    if (not uf.same(i, b)) an++;
  }

  uf = UnionFind(n);
  rep (u, n) {
    if (u == b) continue;
    for (int v: G[u]) {
      if (v == b) continue;
      uf.unite(u, v);
    }
  }

  int bn = 0;
  rep (i, n) {
    if (i == a or i == b) continue;
    if (not uf.same(i, a)) bn++;
  }

  cout << (ll)an * bn << endl;
}

signed main() {
  fio();
  int t;
  cin >> t;
  rep (i, t) {
    solve();
  }
}


/*
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<pii>> dp(n + 1, vector<pii>(5, pii(inf, inf)));
  dp[0][0] = pii(0, 0);
  rep (i, n) {
    rep (j, 5) {
      if (s[i] == 'o') {
        if (j == 4) {}
        else {
          chmin(dp[i + 1][1], pii(dp[i][j].first, j));
        }
      }
      else if (s[i] == 'n') {
        if (j == 1) {
          chmin(dp[i + 1][2], pii(dp[i][j].first, j));
        }
        else {
          chmin(dp[i + 1][0], pii(dp[i][j].first, j));
        }
      }
      else if (s[i] == 'e') {
        if (j == 2) {}
        else {
          chmin(dp[i + 1][0], pii(dp[i][j].first, j));
        }
      }
      else if (s[i] == 't') {
        chmin(dp[i + 1][3], pii(dp[i][j].first, j));
      }
      else if (s[i] == 'w') {
        if (j == 3) {
          chmin(dp[i + 1][4], pii(dp[i][j].first, j));
        }
        else {
          chmin(dp[i + 1][0], pii(dp[i][j].first, j));
        }
      }
      else {
        chmin(dp[i + 1][0], pii(dp[i][j].first, j));
      }
      chmin(dp[i + 1][j], pii(dp[i][j].first + 1, j));
    }
  }
  //DEBUG_MAT(dp);

  pii mi(inf, inf);
  rep (j, 5) chmin(mi, pii(dp[n][j].first, j));
  int i = n, j = mi.second;
  vi rem;
  while (i > 0) {
    int pre_j = dp[i][j].second;
    if (dp[i - 1][pre_j].first < dp[i][j].first) {
      rem.push_back(i);
    }
    i--;
    j = pre_j;
  }
  cout << rem.size() << endl;
  rep (i, rem.size()) {
    cout << rem[i] << " ";
  }
  cout << endl;
}

signed main() {
  fio();
  int t;
  cin >> t;
  rep (_, t) {
    solve();
  }
}
//*/