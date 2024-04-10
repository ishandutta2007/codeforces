#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
  }
  bool ok = true;
  for (int it = 0; it < 2; ++it) {
    vector<pair<int, int>> events;
    for (int i = 0; i < n; ++i) {
      events.emplace_back(a[i].first, ~i);
      events.emplace_back(a[i].second, i);
    }
    sort(events.begin(), events.end());
    multiset<int> left;
    multiset<int> right;
    auto remove = [&](auto& st, int x) {
      st.erase(st.find(x));
    };
    for (auto[x, t] : events) {
      if (t < 0) {
        auto i = ~t;
        left.insert(b[i].first);
        right.insert(b[i].second);
        if (*left.rbegin() > *right.begin()) {
          ok = false;
        }
      } else {
        remove(left, b[t].first);
        remove(right, b[t].second);
      }
    }
    a.swap(b);
  }
  cout << (ok ? "YES" : "NO") << '\n';
  return 0;
}