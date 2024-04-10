#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n), b(n, -1);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
  }
  vector<bool> used(n, false);
  for (int i = 0; i < n; ++i) {
    if (used[a[i]]) continue;
    b[i] = a[i];
    used[a[i]] = true;
  }
  vector<pair<int, int>> unused;
  for (int i = 0; i < n; ++i) {
    if (used[i]) continue;
    int v = i;
    while (b[v] != -1) {
      v = b[v];
    }
    unused.emplace_back(i, v);
  }
  if (unused.size() == 1 && unused[0].first == unused[0].second) {
    int u = unused[0].first, v = a[u];
    for (int i = 0; i < n; ++i)
      if (b[i] == v)
        b[i] = u;
    b[u] = v;
  } else if (unused.size() > 0) {
    for (int i = 0; i + 1 < (int)unused.size(); ++i) {
      b[unused[i].second] = unused[i+1].first;
    }
    b[unused.back().second] = unused[0].first;
  }
  int k = 0;
  for (int i = 0; i < n; ++i)
    k += a[i] == b[i];
  printf("%d\n", k);
  for (int i = 0; i < n; ++i)
    printf("%d%c", b[i] + 1, i+1 == n ? '\n' : ' ');
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}