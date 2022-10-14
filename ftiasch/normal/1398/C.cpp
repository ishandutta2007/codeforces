#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<char> s(n + 1);
    scanf("%s", s.data());
    long long result = 0;
    std::map<int, int> m;
    m[0] = 1;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += (s[i] - '0') - 1;
      result += m[sum];
      m[sum]++;
    }
    printf("%lld\n", result);
  }
}