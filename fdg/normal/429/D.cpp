#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

const int MAXN = 100005;

struct pt {
  int x, y, id;
};
 
inline bool cmp_x (const pt & a, const pt & b) {
  return a.x < b.x || a.x == b.x && a.y < b.y;
}
 
inline bool cmp_y (const pt & a, const pt & b) {
  return a.y < b.y;
}
 
pt a[MAXN];


long long mindist;

inline void upd_ans (const pt & a, const pt & b) {
  long long dist = 1LL * (a.x-b.x)*(a.x-b.x) + 1LL * (a.y-b.y)*(a.y-b.y);
  if (dist < mindist)
    mindist = dist;
}

void rec (int l, int r) {
  if (r - l <= 3) {
    for (int i=l; i<=r; ++i)
      for (int j=i+1; j<=r; ++j)
        upd_ans (a[i], a[j]);
    sort (a+l, a+r+1, &cmp_y);
    return;
  }
 
  int m = (l + r) >> 1;
  int midx = a[m].x;
  rec (l, m),  rec (m+1, r);
  static pt t[MAXN];
  merge (a+l, a+m+1, a+m+1, a+r+1, t, &cmp_y);
  copy (t, t+r-l+1, a+l);
 
  int tsz = 0;
  for (int i=l; i<=r; ++i)
    if (1LL * abs (a[i].x - midx) * abs (a[i].x - midx)  < mindist) {
      for (int j=tsz-1; j>=0 && 1LL * (a[i].y - t[j].y) * (a[i].y - t[j].y) < mindist; --j)
        upd_ans (a[i], t[j]);
      t[tsz++] = a[i];
    }
}

int main() {
  int n;
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    sum += x;
    a[i].x = i;
    a[i].y = sum;
  }
  sort (a, a+n, &cmp_x);
  mindist = 3000000002;
  mindist *= mindist;
  rec (0, n-1);
  cout << mindist << endl;
  return 0;
}