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
    int n, x, y; cin >> n >> x >> y;
    vector<vector<int>> pos(n + 1);
    vector exist(n + 1, false);
    map<int, vector<int>> mp;
    vector<int> b(n);
    REP(i, n) {
      cin >> b[i]; --b[i];
      pos[b[i]].emplace_back(i);
      exist[b[i]] = true;
    }
    int dislike = 0;
    while (exist[dislike]) ++dislike;
    REP(i, n + 1) {
      if (!pos[i].empty()) mp[pos[i].size()].emplace_back(i);
    }
    vector ans(n, -1);
    REP(_, x) {
      int val = mp.rbegin()->second.back(), sz = pos[val].size();
      mp[sz].pop_back();
      if (mp[sz].empty()) mp.erase(sz);
      int idx = pos[val].back();
      ans[idx] = val;
      pos[val].pop_back();
      if (sz > 1) mp[sz - 1].emplace_back(val);
    }
    if (x < n) {
      vector<int> vals, idx;
      vals.reserve(n - x);
      idx.reserve(n - x);
      for (auto it = mp.begin(); it != mp.end(); ++it) {
        for (int val : it->second) {
          for (int e : pos[val]) {
            vals.emplace_back(val);
            idx.emplace_back(e);
          }
        }
      }
      int width = mp.rbegin()->first, rem = y - x;
      // REP(i, n - x) cout << vals[i] << " \n"[i + 1 == n - x];
      // REP(i, n - x) cout << idx[i] << " \n"[i + 1 == n - x];
      // cout << width << '\n';
      bool ok = true;
      for (int i = (n - x - width - 1 + n - x) % (n - x); rem > 0; i = (i - 1 + n - x) % (n - x), --rem) {
        ans[idx[i]] = vals[(i - width + n - x) % (n - x)];
        ok &= ans[idx[i]] != b[idx[i]];
      }
      if (!ok) {
        cout << "NO\n";
        continue;
      }
    }
    cout << "YES\n";
    REP(i, n) cout << (ans[i] == -1 ? dislike : ans[i]) + 1 << " \n"[i + 1 == n];
  }
  return 0;
}