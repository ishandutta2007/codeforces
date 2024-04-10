#line 1 "sol.cpp"
#include <bits/stdc++.h>

std::multiset<long long> set;

bool check(long long n) {
  auto iterator = set.find(n);
  if (iterator != set.end()) {
    set.erase(iterator);
    return true;
  }
  if (n == 1) {
    return false;
  }
  return check(n >> 1) && check((n + 1) >> 1);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    set.clear();
    long long sum = 0;
    for (int i = 0, a; i < n; ++i) {
      scanf("%d", &a);
      set.insert(a);
      sum += a;
    }
    puts(check(sum) ? "YES" : "NO");
  }
}