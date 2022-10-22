#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> a(n);
  vector<int> cnt(n+1, 0);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    ++cnt[a[i]];
  }
  for (int i = 0; i <= n; ++i) {
    cnt[i] = min(cnt[i], k);
  }
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int l, int r) {
    int val = a[l], var = a[r];
    return make_pair(cnt[val], val) > make_pair(cnt[var], var);
  });
  vector<int> colored;
  for (int x : id) {
    int val = a[x];
    if (cnt[val] <= 0) continue;
    --cnt[val];
    colored.push_back(x);
  }
  int z = colored.size() / k;
  colored.resize(z * k);
  vector<int> ans(n, 0);
  for (int i = 0; i < (int)colored.size(); ++i)
    ans[colored[i]] = (i % k) + 1;
  for (int i = 0; i < n; ++i)
    printf("%d%c", ans[i], i+1 == n ? '\n' : ' ');
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}