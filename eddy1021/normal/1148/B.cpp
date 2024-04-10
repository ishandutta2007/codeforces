#include <bits/stdc++.h>
using namespace std;
constexpr int N = 404040;
int n, m, ta, tb, k, a[N], b[N];
void no() {
  puts("-1");
  exit(0);
}
int main() {
  scanf("%d%d%d%d%d", &n, &m, &ta, &tb, &k);
  for (int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < m; ++i){
    scanf("%d", &b[i]);
  }
  if (k >= min(n, m)) {
    no();
  }
  int ans = 0;
  for (int i = 0; i <= k; ++i) {
    int at = lower_bound(b, b + m, a[i] + ta) - b;
    if (at + (k - i) >= m) {
      no();
    }
    ans = max(ans, b[at + (k - i)] + tb);
  }
  printf("%d\n", ans);
}