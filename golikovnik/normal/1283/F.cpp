#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n - 1);
  vector<int> deg(n);
  for (int& x : a) {
    cin >> x;
    --x;
    ++deg[x];
  }
  reverse(a.begin(), a.end());
  set<pair<int, int>> st;
  for (int i = 0; i < n; ++i) {
    if (!deg[i]) {
      st.emplace(i + 1, i);
    }
  }
  vector<pair<int, int>> edges;
  edges.reserve(n - 1);
  cout << a.back() + 1 << '\n';
  for (int it = 0; it < n - 1; ++it) {
    auto[d, who] = *st.begin();
    st.erase(st.begin());
    auto par = a[it];
    cout << par + 1 << ' ' << who + 1 << '\n';
    if (!--deg[par]) {
      st.emplace(max(par + 1, d), par);
    }
  }
  return 0;
}