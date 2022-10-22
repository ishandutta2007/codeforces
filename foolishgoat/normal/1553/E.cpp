#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> p(n);
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    --p[i];
    int r = (p[i] - i) % n;
    if (r < 0)
      r += n;
    ++mp[r];
  }
  vector<int> ans;
  vector<int> q = p;
  vector<bool> vis(n, false);
  for (auto& it : mp) {
    if (it.second < n / 3) continue;
    int r = it.first;
    for (int i = 0; i < n; ++i) {
      q[(i + r) % n] = p[i];
    }
    vis.assign(n, false);
    int sw = 0;
    for (int i = 0; i < n; ++i) {
      if (vis[i]) continue;
      int now = i;
      int cnt = 0;
      while (!vis[now]) {
        ++cnt;
        vis[now] = true;
        now = q[now];
      }
      sw += cnt - 1;
    }
    if (sw <= m) {
      ans.push_back((n - r) % n);
    }
  }
  sort(ans.begin(), ans.end());
  printf("%d", (int)ans.size());
  for (int x : ans)
    printf(" %d", x);
  printf("\n");
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}