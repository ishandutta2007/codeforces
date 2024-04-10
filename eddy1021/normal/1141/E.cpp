#include <bits/stdc++.h>
using namespace std;
constexpr int N = 202020;
typedef long long LL;
LL h, ih, n, d[N], ans;
void died() {
  printf("%lld\n", ans);
  exit(0);
}
void sim() {
  for (int i = 0; i < n; ++i) {
    h += d[i];
    ++ ans;
    if (h <= 0) {
      died();
    }
  }
}
int main() {
  scanf("%lld%lld", &h, &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &d[i]);
  }
  ih = h;
  sim();
  if (h >= ih) {
    ans = -1;
    died();
  }
  LL sumd = 0, max_diff = 0;
  for (int i = 0; i < n; ++i) {
    sumd += d[i];
    max_diff = min(max_diff, sumd);
  }
  LL bl = 0, br = 1e12, ba = 0;
  while (bl <= br) {
    LL bmid = (bl + br) >> 1;
    if (bmid >= 1e15 / -sumd or
        h + bmid * sumd + max_diff <= 0) {
      br = bmid - 1;
    } else {
      ba = bmid;
      bl = bmid + 1;
    }
  }
  h += ba * sumd;
  ans += ba * n;
  while (true) {
    sim();
  }
}