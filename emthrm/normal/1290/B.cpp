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
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  string s; cin >> s;
  int n = s.length();
  vector<vector<int> > cnt(26, vector<int>(n, 0));
  REP(i, n) {
    if (i > 0) {
      REP(j, 26) cnt[j][i] = cnt[j][i - 1];
    }
    ++cnt[s[i] - 'a'][i];
  }
  int q; cin >> q;
  while (q--) {
    int l, r; cin >> l >> r; --l; --r;
    if (l == r) {
      cout << "Yes\n";
      continue;
    }
    int exist = 0;
    REP(i, 26) {
      if (cnt[i][r] - (l > 0 ? cnt[i][l - 1] : 0) > 0) ++exist;
    }
    if (exist == 1) {
      cout << "No\n";
    } else if (exist >= 3) {
      cout << "Yes\n";
    } else {
      cout << (s[l] != s[r] ? "Yes\n" : "No\n");
    }
  }
  return 0;
}