#include <bits/stdc++.h>
using namespace std;
const int N = 202020;
int n, a[N], k;
char ans[N];
int main() {
  scanf("%d", &n);
  for (int i=0; i<n; ++i) {
    scanf("%d", &a[i]);
  }
  int l=0, r=n-1, pre=-1;
  while (l <= r) {
    if (a[l] < a[r] and a[l] > pre) {
      pre = a[l];
      ans[k ++]='L';
      ++l;
      continue;
    }
    if (a[r] < a[l] and a[r] > pre) {
      pre = a[r];
      ans[k ++]='R';
      --r;
      continue;
    }
    break;
  }
  int lans=0, rans=0;
  for (int i=l, tpre = pre; i<=r; ++i) {
    if (a[i] <= tpre) break;
    ++lans;
    tpre = a[i];
  }
  for (int i=r, tpre = pre; i>=l; --i) {
    if (a[i] <= tpre) break;
    ++rans;
    tpre = a[i];
  }
  if (lans >= rans) {
    while (lans --) ans[k ++] = 'L';
  } else {
    while (rans --) ans[k ++] = 'R';
  }
  printf("%d\n", k);
  puts(ans);
}