#include <bits/stdc++.h>
using namespace std;
constexpr int N = 303030;
int n, m, a[N];
bool okay(int dlt) {
  int pre = 0;
  for (int i = 0; i < n; ++i) {
    int cand = m;
    {
      int lb = a[i], rb = min(a[i] + dlt, m - 1);
      if (rb >= pre) {
        cand = min(cand, max(lb, pre));
      }
    }
    if (a[i] + dlt >= m) {
      int lb = 0, rb = (a[i] + dlt) % m;
      if (rb >= pre) {
        cand = min(cand, max(lb, pre));
      }
    }
    if (cand == m) {
      return false;
    }
    pre = cand;
  }
  return true;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int bl = 0, br = m - 1, ba = 0;
  while (bl <= br) {
    int bmid = (bl + br) >> 1;
    if (okay(bmid))
      ba = bmid, br = bmid - 1;
    else
      bl = bmid + 1;
  }
  printf("%d\n", ba);
}