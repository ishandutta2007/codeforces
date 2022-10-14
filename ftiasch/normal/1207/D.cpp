#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 300'000;
const int MOD = 998'244'353;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int n, fact[N + 1];
std::pair<int, int> a[N];

int main() {
  scanf("%d", &n);
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = 1LL * fact[i - 1] * i % MOD;
  }
  std::map<int, int> fm, sm;
  std::map<std::pair<int, int>, int> pm;
  for (int i = 0, x, y; i < n; ++i) {
    scanf("%d%d", &x, &y);
    a[i] = {x, y};
    fm[x]++;
    sm[y]++;
    pm[a[i]]++;
  }
  int result = fact[n];
  {
    int fbad = 1;
    for (auto [_, v] : fm) {
      fbad = 1LL * fbad * fact[v] % MOD;
    }
    add(result, MOD - fbad);
  }
  {
    int sbad = 1;
    for (auto [_, v] : sm) {
      sbad = 1LL * sbad * fact[v] % MOD;
    }
    add(result, MOD - sbad);
  }
  std::sort(a, a + n);
  bool ok = true;
  for (int i = 1; i < n; ++i) {
    ok &= a[i - 1].second <= a[i].second;
  }
  if (ok) {
    int pbad = 1;
    for (auto [_, v] : pm) {
      pbad = 1LL * pbad * fact[v] % MOD;
    }
    add(result, pbad);
  }
  printf("%d\n", result);
}