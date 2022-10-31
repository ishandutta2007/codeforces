#include <bits/stdc++.h>
using namespace std;
constexpr int N = 404040;
int n, a[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    a[n + i] = a[i];
  }
  n <<= 1;
  for (int i = 1; i < n; ++i) {
    if (a[i]) {
      a[i] += a[i - 1];
    }
  }
  printf("%d\n", *max_element(a, a + n));
}