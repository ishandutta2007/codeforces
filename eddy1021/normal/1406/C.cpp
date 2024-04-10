#include <bits/stdc++.h>
using namespace std;
constexpr int N = 101010;
int n, x[N], y[N];
vector<int> v[N];
void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    v[i].clear();
  }
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    v[x[i]].push_back(y[i]);
    v[y[i]].push_back(x[i]);
  }
}
int sz[N], mx_sz[N];
void go(int now, int prt) {
  sz[now] = mx_sz[now] = 1;
  for (int son: v[now]) {
    if (son == prt) continue;
    go(son, now);
    sz[now] += sz[son];
    mx_sz[now] = max(mx_sz[now], sz[son]);
  }
  mx_sz[now] = max(mx_sz[now], n - sz[now]);
}
void solve() {
  go(1, 1);
  int bst = N;
  vector<int> who;
  for (int i = 1; i <= n; ++i) {
    if (mx_sz[i] > bst) continue;
    if (mx_sz[i] < bst) who.clear();
    bst = mx_sz[i];
    who.push_back(i);
  }
  if (who.size() == 1u) {
    printf("%d %d\n", x[1], y[1]);
    printf("%d %d\n", x[1], y[1]);
    return;
  }
  assert(who.size() == 2u);
  for (auto nxt : v[who[0]]) {
    if (nxt == who[1]) continue;
    printf("%d %d\n", who[0], nxt);
    printf("%d %d\n", who[1], nxt);
    return;
  }
  assert(false);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    init();
    solve();
  }
}