#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl

typedef long long ll;
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
const ll INF = 1e18;
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair

int n;
vi p;
vii child;
vl a, s;

void dfs(int u, ll sum, int d) {
  if (d == 0) {
    a[0] = s[0];
    rep (i, child[0].size()) {
      dfs(child[0][i], s[0], d + 1);
    }
  }
  else if (d % 2 == 0) {
    if (sum > s[u]) {
      cout << -1 << endl;
      exit(0);
    }
    ll mi = INF;
    a[u] = s[u] - sum;
    rep (i, child[u].size()) {
      dfs(child[u][i], s[u], d + 1);
    }
  }
  else {
    if (child[u].size() == 0) {
      a[u] = 0;
      return;
    }
    ll mi = INF;
    rep (i, child[u].size()) {
      int v = child[u][i];
      mi = min(mi, s[v]);
    }
    if (mi < sum) {
      cout << -1 << endl;
      exit(0);
    }
    a[u] = mi - sum;
    rep (i, child[u].size()) {
      dfs(child[u][i], mi, d + 1);
    }
  }
}
      

int main() {
  cin >> n;
  p.resize(n);
  child.resize(n);
  a.resize(n);
  s.resize(n);
  a[0] = 1;
  p[0] = -1;
  rep1 (i, n - 1) {
    cin >> p[i];
    p[i]--;
    child[p[i]].push_back(i);
  }
  rep (i, n) {
    cin >> s[i];
  }
  dfs(0, 0, 0);
  ll ans = 0;
  rep (i, n) {
    ans += a[i];
  }
  cout << ans << endl;
}