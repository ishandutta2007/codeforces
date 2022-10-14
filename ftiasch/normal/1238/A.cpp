#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    puts([&]() {
        long long d = x - y;
        if (~d & 1) {
            return true;
        }
        return d >= 3;
    }() ? "YES" : "NO");
  }
}