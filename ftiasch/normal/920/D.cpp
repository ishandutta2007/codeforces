#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 5000;

int n, m, target, a[N];
bool dp[N + 1][N];

void move(int x, int y, int cnt = 1000000000) {
  if (cnt) {
    printf("%d %d %d\n", cnt, x + 1, y + 1);
  }
}

bool solve() {
  int sum = std::accumulate(a, a + n, 0);
  if (sum < target) {
    return false;
  }
  if (target % m == 0) {
    puts("YES");
    for (int i = 1; i < n; ++i) {
      move(i, 0);
      a[0] += a[i];
    }
    move(0, 1, target / m);
    return true;
  }
  dp[0][0] = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (dp[i][j]) {
        dp[i + 1][j] = true;
        dp[i + 1][(j + a[i]) % m] = true;
      }
    }
  }
  if (!dp[n][target % m]) {
    return false;
  }
  std::vector<int> in, out;
  for (int i = n, j = target % m; i--;) {
    if (dp[i][j]) {
      out.push_back(i);
    } else {
      in.push_back(i);
      j = (j + m - a[i] % m);
      if (j >= m) {
        j -= m;
      }
    }
  }
  puts("YES");
  int i0 = in.back();
  in.pop_back();
  for (int i : in) {
    move(i, i0);
    a[i0] += a[i];
  }
  if (a[i0] >= target) {
    int i1 = i0 ? 0 : 1;
    move(i0, i1, (a[i0] - target) / m);
  } else {
    int o0 = out.back();
    out.pop_back();
    for (int o : out) {
      move(o, o0);
    }
    move(o0, i0, (target - a[i0]) / m);
  }
  return true;
}

int main() {
  scanf("%d%d%d", &n, &m, &target);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  if (!solve()) {
    puts("NO");
  }
}