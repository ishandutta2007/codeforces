#include <bits/stdc++.h>

using i64 = int64_t;

using namespace std;

int main() {
  int const MAX = (int) 2e5 + 20;
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  sort(a.begin(), a.end());
  vector<pair<int, int>> b;
  for (int i = 0; i < n; ++i) {
    int j = i;
    while (j < n && a[i] == a[j]) ++j;
    b.emplace_back(a[i], j - i);
    i = j - 1;
  }
  n = (int) b.size();
  vector<int> pref(n + 1);
  for (int i = 0; i < n; ++i) {
    pref[i + 1] = pref[i] + b[i].second;
  }
  auto get = [&](int from, int to) {
    //  [from; to)
    auto l = lower_bound(b.begin(), b.end(), make_pair(from, 0));
    if (l == b.end()) {
      return 0;
    }
    auto r = lower_bound(b.begin(), b.end(), make_pair(to, 0));
    auto li = l - b.begin();
    auto ri = r - b.begin();
    return pref[ri] - pref[li];
  };
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    auto x = b[i].first;
    i64 cur = 0;
    for (int start = x; start < MAX; start += x) {
      auto c = get(start, start + x);
      cur += 1ll * start * c;
    }
    ans = max(ans, cur);
  }
  cout << ans << '\n';
  return 0;
}