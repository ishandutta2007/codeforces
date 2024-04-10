#line 1 "sol.cpp"
#include <bits/stdc++.h>

char s[2'000'001];
int cnt[10], result[10][10], dist[10];

int main() {
  scanf("%s", s);
  for (int i = 1; s[i]; ++i) {
    cnt[((s[i] - '0') + 10 - (s[i - 1] - '0')) % 10]++;
  }
  for (int x = 0; x < 10; ++x) {
    for (int y = 0; y < 10; ++y) {
      memset(dist, -1, sizeof(dist));
      dist[x] = dist[y] = 0;
      std::queue<int> q;
      q.push(x);
      if (x != y) {
        q.push(y);
      }
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int t = 0; t < 2; ++t) {
          int v = (u + (t ? y : x)) % 10;
          if (!~dist[v]) {
            dist[v] = dist[u] + 1;
            q.push(v);
          }
        }
      }
      int result = 0;
      for (int d = 0; d < 10 && ~result; ++d) {
        if (~dist[d]) {
          result += cnt[d] * dist[d];
        } else if (cnt[d]) {
          result = -1;
        }
      }
      printf("%d%c", result, " \n"[y == 9]);
    }
  }
}