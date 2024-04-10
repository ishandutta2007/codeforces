#include <bits/stdc++.h>
using namespace std;
constexpr int kN = 10210;
constexpr int kP = 6;
int n, m, f, h[kN], k, p[kP], msk[kN];
vector<int> v[kN];
bool walk[kN];
void Init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    v[i].clear();
    msk[i] = 0;
  }
  while (m--) {
    int ui, vi;
    scanf("%d%d", &ui, &vi);
    v[ui].push_back(vi);
    v[vi].push_back(ui);
  }
  scanf("%d", &f);
  for (int i = 1; i <= f; ++i) {
    scanf("%d", &h[i]);
    walk[i] = false;
  }
  scanf("%d", &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &p[i]);
    walk[p[i]] = true;
    msk[h[p[i]]] |= (1 << i);
  }
}
bool inq[kN], can[kN][1 << kP];
int dst[kN];
void Push(int ui, int vi) {
  for (int i = 0; i < (1 << k); ++i)
    if (can[ui][i]) {
      can[vi][i] = true;
    }
}
bool dp[2][1 << kP];
void Solve() {
  for (int i = 1; i <= n; ++i) {
    inq[i] = false;
    dst[i] = kN + kN;
    for (int j = 0; j < (1 << k); ++j) {
      can[i][j] = false;
    }
  }
  queue<int> Q;
  Q.push(1);
  inq[1] = true;
  dst[1] = 0;
  can[1][0] = true;
  while (Q.size()) {
    int now = Q.front(); Q.pop();
    for (int i = 0; i < (1 << k); ++i)
      if (can[now][i]) {
        can[now][i | msk[now]] = true;
      }
    for (int next: v[now]) {
      if (!inq[next]) {
        inq[next] = true;
        dst[next] = dst[now] + 1;
        Q.push(next);
      }
      if (dst[next] == dst[now] + 1) {
        Push(now, next);
      }
    }
  }
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < (1 << k); ++j)
      dp[i][j] = false;
  dp[0][0] = true;
  for (int i = 1; i <= f; ++i) {
    int now = i & 1, pre = 1 - now;
    for (int j = 0; j < (1 << k); ++j)
      dp[now][j] = false;
    if (walk[i]) {
      for (int j = 0; j < (1 << k); ++j)
        dp[now][j] = dp[pre][j];
    } else {
      int at = h[i];
      for (int cur = 0; cur < (1 << k); ++cur) {
        if (!dp[pre][cur]) continue;
        for (int mr = 0; mr < (1 << k); ++mr) {
          if (can[at][mr]) {
            dp[now][cur | mr] = true;
          }
        }
      }
    }
  }
  int ans = k;
  for (int i = 0; i < (1 << k); ++i)
    if (dp[f & 1][i])
      ans = min(ans, k - (int)__builtin_popcount(i));
  printf("%d\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    Init();
    Solve();
  }
}