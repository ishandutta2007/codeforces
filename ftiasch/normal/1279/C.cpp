#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<int> stk(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &stk[i]);
      stk[i]--;
    }
    std::vector<bool> touched(n);
    int top = 0, idx = 0;
    long long result = 0;
    for (int j = 0, b; j < m; ++j) {
      scanf("%d", &b);
      b--;
      if (touched[b]) {
        top--;
      } else {
        while (stk[idx] != b) {
          top++;
          touched[stk[idx++]] = true;
        }
        idx ++;
        result += top;
      }
    }
    printf("%lld\n", 2LL * result + m);
  }
}