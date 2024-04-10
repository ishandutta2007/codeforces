#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, C;
  scanf("%d%d", &n, &C);
  std::vector<long long> max_dh(C + 1);
  for (int i = 0, c, d, h; i < n; ++i) {
    scanf("%d%d%d", &c, &d, &h);
    max_dh[c] = std::max(max_dh[c], 1LL * d * h);
  }
  std::vector<long long> max_DH(C + 1);
  for (int c = 1; c <= C; ++c) {
    if (max_dh[c] > 0) {
      for (int k = 1, kc = c; kc <= C; ++k, kc += c) {
        max_DH[kc] = std::max(max_DH[kc], k * max_dh[c] - 1);
      }
    }
  }
  for (int c = 1; c <= C; ++c) {
    max_DH[c] = std::max(max_DH[c - 1], max_DH[c]);
  }
  int m;
  scanf("%d", &m);
  for (int i = 0, D; i < m; ++i) {
    long long H;
    scanf("%d%lld", &D, &H);
    int result = std::lower_bound(max_DH.begin(), max_DH.end(), 1LL * D * H) - max_DH.begin();
    printf("%d%c", result <= C ? result : -1, " \n"[i + 1 == m]);
  }
}