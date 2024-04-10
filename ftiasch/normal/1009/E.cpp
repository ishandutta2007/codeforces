#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int MOD = 998'244'353;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> power_of_two(n);
  power_of_two[0] = 1;
  for (int i = 1; i < n; ++i) {
    power_of_two[i] = power_of_two[i - 1];
    add(power_of_two[i], power_of_two[i - 1]);
  }
  int last = 0, result = 0;
  for (int i = 1, a; i <= n; ++i) {
    scanf("%d", &a);
    int cost = a - last;
    add(result, (n + 1LL - i) * cost % MOD * power_of_two[n - i] % MOD);
    last = a;
  }
  printf("%d\n", result);
}