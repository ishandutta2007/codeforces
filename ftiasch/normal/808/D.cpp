#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  long long sum = std::accumulate(a.begin(), a.end(), 0LL);

  auto check = [&]() {
    if (sum & 1) {
      return false;
    }
    long long tar = sum >> 1, pre = 0, suf = sum;
    std::set<long long> s;
    for (int i = 0; i < n; ++i) {
      pre += a[i];
      suf -= a[i];
      s.insert(a[i]);
      if (pre == suf && i + 1 < n) {
        return true;
      }
      if (i && pre > tar && s.count(pre - tar)) {
          return true;
      }
    }
    return false;
  };

  bool ok = check();
  std::reverse(a.begin(), a.end());
  ok |= check();
  puts(ok ? "YES" : "NO");
}