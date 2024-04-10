#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> p(n), pos_in_p(n);
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      --x;
      p[i] = x;
      pos_in_p[x] = i;
    }
    i64 ans = 0;
    int last_i = -1;
    vector<int> fenw(n);
    auto add = [&](int at, int d) {
      for (; at < n; at |= at + 1) {
        fenw[at] += d;
      }
    };
    auto get = [&](int upto) {
      int res = 0;
      for (; upto >= 0; upto = (upto & (upto + 1)) - 1) {
        res += fenw[upto];
      }
      return res;
    };
    for (int i = 0; i < n; ++i) {
      add(i, 1);
    }
    for (int i = 0; i < m; ++i) {
      int x;
      cin >> x;
      --x;
      int ps = pos_in_p[x];
      if (last_i >= ps) {
        ans += 1;
      } else {
        ans += 2 * (get(ps - 1)) + 1;
      }
      add(ps, -1);
      last_i = max(last_i, ps);
    }
    cout << ans << '\n';
  }
  return 0;
}