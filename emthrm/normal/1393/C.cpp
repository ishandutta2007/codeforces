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

void solve() {
  int n; cin >> n;
  map<int, int> mp;
  REP(_, n) {
    int a; cin >> a;
    ++mp[a];
  }
  multiset<int> st;
  for (auto pr : mp) st.emplace(pr.second);
  int lb = 0, ub = n;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    multiset<int> tmp = st;
    bool ok = true;
    for (int i = 0; i < n; i += mid + 1) {
      if (tmp.size() < min(n - i, mid + 1)) {
        ok = false;
        break;
      }
      vector<int> v;
      REP(_, min(n - i, mid + 1)) {
        v.emplace_back(*tmp.rbegin() - 1);
        tmp.erase(prev(tmp.end()));
      }
      for (int e : v) {
        if (e > 0) tmp.emplace(e);
      }
    }
    (ok ? lb : ub) = mid;
  }
  cout << lb << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}