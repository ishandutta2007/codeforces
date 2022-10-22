#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

struct State {
  int val;
  long long cnt;
  long long sum;



  bool operator<(const State & s) {
    return val < s.val;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<State> cur, bef;
  cur.emplace_back(State{a[n-1], 1, 0});
  long long ans = 0;
  for (int i = n-2; i >= 0; --i) {
    bef.swap(cur);
    int x = a[i];
    cur.clear();
    for (auto & e : bef) {
      int c = (x + e.val - 1) / e.val;
      int v = x / c;
      cur.emplace_back(State{v, e.cnt, (e.sum + e.cnt * (c-1)) % mod});
    }
    cur.emplace_back(State{x, 1, 0});
    sort(cur.begin(), cur.end());
    int sz = 0;
    for (int j = 0; j < (int)cur.size(); ) {
      int val = cur[j].val;
      long long cnt = 0, sum = 0;
      while (j < (int)cur.size() && cur[j].val == val) {
        cnt += cur[j].cnt;
        if (cnt >= mod)
          cnt -= mod;
        sum += cur[j].sum;
        if (sum >= mod)
          sum -= mod;
        ++j;
      }
      cur[sz] = {val, cnt, sum};
      ++sz;
      ans += sum;
      if (ans >= mod)
        ans -= mod;
    }
    cur.resize(sz);
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}