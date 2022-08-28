#include <cstdio>

#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  int n;
  scanf("%d", &n);
  vector<ll> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", &a[i]);
  for (int i = 0; i < n; ++i)
    scanf("%d", &b[i]);
  vector<int> cnt(n);
  queue<int> q;
  int m = n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      if (i != j)
        if (a[i] & ~a[j])
          ++cnt[i];
    if (cnt[i] == n - 1) {
      q.push(i);
      cnt[i] = -1;
    }
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    --m;
    for (int i = 0; i < n; ++i)
      if (cnt[i] != -1) {
        if (a[i] & ~a[u])
          --cnt[i];
        else
          if (cnt[i] == m - 1) {
            cnt[i] = -1;
            q.push(i);
          }
      }
  }
  ll ans = 0;
  if (m >= 2) {
    for (int i = 0; i < n; ++i)
      if (cnt[i] != -1)
        ans += b[i];
  }
  printf("%lld\n", ans);
  return 0;
}