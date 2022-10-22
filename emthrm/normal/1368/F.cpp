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
  int n; cin >> n;
  if (n <= 3) {
    cout << 0 << endl;
    return 0;
  }
  int len = 0, r = 0;
  FOR(i, 2, n + 1) {
    int block = (n + i - 1) / i, now_r = n - block - (i - 1);
    if (now_r > r) {
      len = i;
      r = now_r;
    }
  }
  int block = (n + len - 1) / len;
  vector<vector<int>> off(block);
  vector<bool> need(n, false);
  REP(i, n) {
    off[i / len].emplace_back(i);
    need[i] = true;
  }
  REP(i, block) {
    need[off[i].back()] = false;
    off[i].pop_back();
  }
  vector<bool> on(n, false);
  int cnt = 0;
  function<vector<int>(const vector<int>&)> query = [&](const vector<int> &choose) {
    int m = choose.size();
    cout << m << ' ';
    REP(i, m) {
      cout << choose[i] + 1;
      if (i + 1 == m) {
        cout << endl;
      } else {
        cout << ' ';
      }
    }
    int ans; cin >> ans;
    assert(ans != -1);
    --ans;
    vector<int> res;
    REP(i, m) res.emplace_back((ans + i) % n);
    return res;
  };
  while (cnt < r) {
    vector<int> choose;
    REP(i, block) {
      while (!off[i].empty() && choose.size() < len) {
        choose.emplace_back(off[i].back());
        on[off[i].back()] = true;
        off[i].pop_back();
        ++cnt;
      }
    }
    for (int e : query(choose)) {
      if (on[e] && need[e]) {
        off[e / len].emplace_back(e);
        --cnt;
      }
    }
  }
  cout << 0 << endl;
  return 0;
}