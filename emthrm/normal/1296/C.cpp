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

void solve() {
  int n; string s; cin >> n >> s;
  int r = 0, u = 0;
  map<pair<int, int>, vector<int> > mp;
  REP(i, n) {
    if (s[i] == 'L') {
      --r;
    } else if (s[i] == 'R') {
      ++r;
    } else if (s[i] == 'U') {
      ++u;
    } else {
      --u;
    }
    mp[{r, u}].emplace_back(i);
  }
  int ans = INF, p, q;
  int l = 0, d = 0;
  REP(i, n) {
    if (mp.count({l, d}) == 1) {
      auto it = lower_bound(ALL(mp[make_pair(l, d)]), i + 1);
      if (it != mp[{l, d}].end() && *it - i + 1 < ans) {
        ans = *it - i + 1;
        p = i;
        q = *it;
      }
    }
    if (s[i] == 'L') {
      --l;
    } else if (s[i] == 'R') {
      ++l;
    } else if (s[i] == 'U') {
      ++d;
    } else {
      --d;
    }
  }
  if (ans == INF) {
    cout << "-1\n";
  } else {
    cout << p + 1 << ' ' << q + 1 << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}