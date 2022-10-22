#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
template <typename T, typename U>
inline void chmax(T &a, U b) { if (a < b) a = b; }
template <typename T, typename U>
inline void chmin(T &a, U b) { if (a > b) a = b; }

struct SegmentTree {
  int n, p2 = 1;
  vector<int> dat;

  SegmentTree(int n) : n(n) {
    while (p2 < n) p2 <<= 1;
    dat.assign(p2 << 1, -INF);
  }

  void set(int idx, int val) {
    idx += p2;
    dat[idx] = val;
    while (idx >>= 1) dat[idx] = max(dat[idx << 1], dat[(idx << 1) + 1]);
  }

  int get(int left, int right) const {
    int l_res = -INF, r_res = -INF;
    for (left += p2, right += p2; left < right; left >>= 1, right >>= 1) {
      if (left & 1) chmax(l_res, dat[left++]);
      if (right & 1) chmax(r_res, dat[--right]);
    }
    return max(l_res, r_res);
  }

  int operator[](const int idx) const { return dat[idx + p2]; }
};

void solve() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i], --a[i];
  vector<int> p(n);
  iota(ALL(p), 0);
  sort(ALL(p), [&](int l, int r) { return a[l] == a[r] ? l < r : a[l] < a[r]; });
  set<int> st;
  REP(i, n) st.emplace(i);
  SegmentTree dp(n);
  REP(_, n) {
    int i = p[_], large = (st.lower_bound(i) == st.begin() ? -1 : *prev(st.lower_bound(i)));
    int d = large == -1 ? 1 : 2;
    chmax(d, dp.get(large + 1, i) + 1);
    chmax(d, dp.get(0, large) + 2);
    dp.set(i, d);
    st.erase(i);
  }
  int ans = 2, mx = -INF;
  for (int i = n - 1; i >= 0; --i) {
    chmax(ans, dp[i] + (mx > a[i]));
    chmax(mx, a[i]);
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}