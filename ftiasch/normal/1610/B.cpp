#include <bits/stdc++.h>

bool check(const std::vector<int> &a, int l, int r, int x) {
  while (l < r && (a[l] == x || a[r - 1] == x || a[l] == a[r - 1])) {
    if (a[l] == x) {
      l++;
    } else if (a[r - 1] == x) {
      r--;
    } else if (a[l] == a[r - 1]) {
      l++;
      r--;
    }
  }
  return l >= r;
}

bool check(int n, const std::vector<int> &a) {
  int l = 0;
  int r = n;
  while (l < r && a[l] == a[r - 1]) {
    l++;
    r--;
  }
  if (l >= r) {
    return true;
  }
  return check(a, l, r, a[l]) || check(a, l, r, a[r - 1]);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    puts(check(n, a) ? "YES" : "NO");
  }
}