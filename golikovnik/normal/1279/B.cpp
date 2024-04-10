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
    int n, s;
    cin >> n >> s;
    vector<i64> a(n);
    for (auto& x : a) {
      cin >> x;
    }
    vector<i64> pref(n + 1);
    for (int i = 0; i < n; ++i) {
      pref[i + 1] = pref[i] + a[i];
    }
    auto get = [&](int l, int r) -> i64 {
      if (l > r) {
        return 0;
      }
      return pref[r + 1] - pref[l];
    };

    i64 ans = -1;
    int id = -1;
    for (int i = 0; i < n; ++i) {
      auto first = get(0, i - 1);
      if (first > s) {
        break;
      }
      auto can = s - first;
      first = i;
      int left = 0;
      int right = n - i;
      while (left + 1 != right) {
        int middle = (left + right) / 2;
        auto cur = get(i + 1, i + 1 + middle - 1);
        if (cur > can) {
          right = middle;
        } else {
          left = middle;
        }
      }
      if (first + left > ans) {
        ans = first + left;
        id = i + 1;
      }
    }
    if (get(0, n - 1) <= s) {
      id = 0;
    }
    cout << id << '\n';
  }
  return 0;
}