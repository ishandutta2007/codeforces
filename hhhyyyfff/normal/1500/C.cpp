#include <bits/stdc++.h>

using namespace std;

vector<int> A[1510];
int n, m, B[1510][1510], ban[1510][1510], pass[1510][1510];
int cnt[1510], ans[1510], col;
bool vis[1510], flag;

const bool cmp(const vector<int>& x, const vector<int>& y)
    { return x[col] < y[col]; }

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    A[i] = vector<int>(m + 1);
    for (int j = 1; j <= m; ++j)
      scanf("%d", &A[i][j]);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      scanf("%d", &B[i][j]);
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= m; ++j)
      if (B[i][j] < B[i + 1][j])
        pass[j][++pass[j][0]] = i; else
      if (B[i][j] > B[i + 1][j]) {
        ban[i][++ban[i][0]] = j;
        ++cnt[j];
      }
  }
  do {
    flag = 0;
    for (int i = 1; i <= m; ++i)
      if (cnt[i] == 0) {
        flag = 1;
        ans[++ans[0]] = i;
        cnt[i] = -1;
        for (int j = 1; j <= pass[i][0]; ++j) {
          if (vis[pass[i][j]]) continue;
          vis[pass[i][j]] = 1;
          for (int k = 1; k <= ban[pass[i][j]][0]; ++k)
            --cnt[ban[pass[i][j]][k]];
        }
      }
  } while (flag);
  for (int i = ans[0]; i > 0; --i) {
    col = ans[i];
    stable_sort(A + 1, A + n + 1, cmp);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (A[i][j] != B[i][j]) {
        puts("-1");
        return 0;
      }
  printf("%d\n", ans[0]);
  for (int i = ans[0]; i > 0; --i) printf("%d ", ans[i]);
  puts("");
  return 0;
}