#include <bits/stdc++.h>
using namespace std;
constexpr int N = 101010;
int n, a[N], cnt[2];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    ++cnt[a[i] & 1];
  }
  if (cnt[0] and cnt[1]) {
    sort(a, a + n);
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", a[i], " \n"[i + 1 == n]);
  }
}