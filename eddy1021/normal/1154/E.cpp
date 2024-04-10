#include <bits/stdc++.h>
using namespace std;
const int N = 202020;
int n, k, a[N], at[N], nxt[N], pre[N], ans[N];
int main() {
  scanf("%d%d", &n, &k);
  for (int i=1; i<=n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i=1; i<=n; ++i) {
    pre[i] = i - 1;
    if (i<n) {
      nxt[i] = i + 1;
    }
    at[a[i]] = i;
  }
  auto del = [&](int pos) {
    if (nxt[pos]) {
      pre[nxt[pos]] = pre[pos];
    }
    if (pre[pos]) {
      nxt[pre[pos]] = nxt[pos];
    }
  };
  int team = 1;
  for (int i=n; i>=1; --i) {
    if (ans[at[i]]) {
      continue;
    }
    int pos = at[i];
    for (int _=0; _<k; ++_) {
      if (nxt[pos] == 0) {
        break;
      }
      ans[nxt[pos]] = team;
      del(nxt[pos]);
    }
    for (int _=0; _<k; ++_) {
      if (pre[pos] == 0) {
        break;
      }
      ans[pre[pos]] = team;
      del(pre[pos]);
    }
    ans[pos] = team;
    del(pos);
    team = 3 - team;
  }
  for (int i=1; i<=n; ++i) {
    printf("%d", ans[i]);
  }
  puts("");
}