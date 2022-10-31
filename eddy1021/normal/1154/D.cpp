#include <bits/stdc++.h>
using namespace std;
constexpr int N = 202020;
int n, b, a, c[N], ca;
int main() {
  scanf("%d%d%d", &n, &b, &a);
  ca = a;
  for (int i=0; i<n; ++i) {
    scanf("%d", &c[i]);
  }
  int ans = 0;
  for (int i=0; i<n; ++i) {
    if (c[i] and b and a < ca) {
      ++ ans;
      -- b;
      ++ a;
      continue;
    }
    if (a) {
      ++ ans;
      -- a;
    } else if (b) {
      ++ ans;
      -- b;
    } else {
      break;
    }
  }
  cout << ans << endl;
}