#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

const string ABACABA = "abacaba";

void solve() {
  int n; string s; cin >> n >> s;
  for (int i = 0; i + 7 <= n; ++i) {
    string t = s;
    bool ok = true;
    REP(j, 7) ok &= t[i + j] == '?' || t[i + j] == ABACABA[j];
    if (!ok) continue;
    REP(j, 7) t[i + j] = ABACABA[j];
    for (char &c : t) {
      if (c == '?') c = 'z';
    }
    int cnt = 0;
    for (int j = 0; j + 7 <= n; ++j) cnt += t.substr(j, 7) == ABACABA;
    if (cnt == 1) {
      cout << "Yes\n" << t << '\n';
      return;
    }
  }
  cout << "No\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}