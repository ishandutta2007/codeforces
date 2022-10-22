#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
int popcount(int val) { return __builtin_popcount(val); }
int popcountll(ll val) { return __builtin_popcountll(val); }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

vector<vector<int> > nx_init(const string &s, const char basis = 'a', const int char_sz = 26) {
  int n = s.size();
  vector<vector<int> > nx(n, vector<int>(char_sz, n));
  nx[n - 1][s[n - 1] - basis] = n - 1;
  for (int i = n - 2; i >= 0; --i) {
    REP(j, char_sz) nx[i][j] = nx[i + 1][j];
    nx[i][s[i] - basis] = i;
  }
  return nx;
}

int main() {
  const int D = 250;
  int n, q; string s; cin >> n >> q >> s;
  vector<vector<int> > nx = nx_init(s);
  vector<vector<vector<int> > > dp(D + 1, vector<vector<int> >(D + 1, vector<int>(D + 1, n)));
  dp[0][0][0] = -1;
  vector<int> len(3, 0);
  vector<vector<char> > str(3);
  while (q--) {
    char ope; int i; cin >> ope >> i; --i;
    if (ope == '+') {
      char c; cin >> c;
      ++len[i];
      str[i].emplace_back(c);
      if (i == 0) {
        REP(y, len[1] + 1) REP(z, len[2] + 1) {
          int &now = dp[len[0]][y][z];
          now = n;
          if (len[0] > 0 && dp[len[0] - 1][y][z] < n - 1) chmin(now, nx[dp[len[0] - 1][y][z] + 1][str[0][len[0] - 1] - 'a']);
          if (y > 0 && dp[len[0]][y - 1][z] < n - 1) chmin(now, nx[dp[len[0]][y - 1][z] + 1][str[1][y - 1] - 'a']);
          if (z > 0 && dp[len[0]][y][z - 1] < n - 1) chmin(now, nx[dp[len[0]][y][z - 1] + 1][str[2][z - 1] - 'a']);
        }
      } else if (i == 1) {
        REP(x, len[0] + 1) REP(z, len[2] + 1) {
          int &now = dp[x][len[1]][z];
          now = n;
          if (x > 0 && dp[x - 1][len[1]][z] < n - 1) chmin(now, nx[dp[x - 1][len[1]][z] + 1][str[0][x - 1] - 'a']);
          if (len[1] > 0 && dp[x][len[1] - 1][z] < n - 1) chmin(now, nx[dp[x][len[1] - 1][z] + 1][str[1][len[1] - 1] - 'a']);
          if (z > 0 && dp[x][len[1]][z - 1] < n - 1) chmin(now, nx[dp[x][len[1]][z - 1] + 1][str[2][z - 1] - 'a']);
        }
      } else if (i == 2) {
        REP(x, len[0] + 1) REP(y, len[1] + 1) {
          int &now = dp[x][y][len[2]];
          now = n;
          if (x > 0 && dp[x - 1][y][len[2]] < n - 1) chmin(now, nx[dp[x - 1][y][len[2]] + 1][str[0][x - 1] - 'a']);
          if (y > 0 && dp[x][y - 1][len[2]] < n - 1) chmin(now, nx[dp[x][y - 1][len[2]] + 1][str[1][y - 1] - 'a']);
          if (len[2] > 0 && dp[x][y][len[2] - 1] < n - 1) chmin(now, nx[dp[x][y][len[2] - 1] + 1][str[2][len[2] - 1] - 'a']);
        }
      }
    } else if (ope == '-') {
      --len[i];
      str[i].pop_back();
    }
    cout << (dp[len[0]][len[1]][len[2]] < n ? "YES\n" : "NO\n");
  }
  return 0;
}