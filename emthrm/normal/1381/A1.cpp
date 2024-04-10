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

int main() {
  int t; cin >> t;
  while (t--) {
    int n; string a, b; cin >> n >> a >> b;
    vector<int> ans;
    bool rev = false;
    int l = 0, r = n - 1;
    for (int i = n - 1; i >= 0; --i) {
      int ai = rev ? (a[l] - '0' + 1) % 2 : a[r] - '0', bi = b[i] - '0';
      if (ai != bi) {
        int c = rev ? (a[r] - '0' + 1) % 2 : a[l] - '0';
        // cout << i << ' ' << ai << ' ' << bi << ' ' << c << '\n';
        if (c == bi) ans.emplace_back(0);
        ans.emplace_back(i);
        rev = !rev;
      }
      if (rev) {
        ++l;
      } else {
        --r;
      }
    }
    if (ans.empty()) {
      cout << 0 << '\n';
    } else {
      int k = ans.size();
      cout << k << ' ';
      REP(i, k) cout << ans[i] + 1 << " \n"[i + 1 == k];
    }
  }
  return 0;
}