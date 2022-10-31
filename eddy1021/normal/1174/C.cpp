#include <bits/stdc++.h>
using namespace std;
constexpr int N = 101010;
int n, a[N];
int main() {
  scanf("%d", &n);
  for (int i = 2, k = 0; i <= n; ++i) {
    if (a[i]) {
      continue;
    }
    ++ k;
    for (int j = i; j <= n; j += i) {
      a[j] = k;
    }
  }
  for (int i = 2; i <= n; ++i) {
    printf("%d%c", a[i], " \n"[i == n]);
  }
}