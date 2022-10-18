#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[200005];
long long sa[200005];

long double s[200005];

long double dp[55][200005];
int wh[55][200005];

long double get(int l, int r) {
  long double ret = dp[1][r];
  if (l) {
    ret -= dp[1][l - 1];
    ret -= 1.0 * sa[l - 1] * (s[r] - s[l - 1]);
  }
  return ret;
}


struct pt {
  double x, y;
  int id;
};

bool cmp (const pt &a, const pt &b) {
  return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (const pt &a, const pt &b, const pt &c) {
  return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (const pt &a, const pt &b, const pt &c) {
  return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

int main() {
  int n = 200, k = 10;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    // arr[i] = rand() % 100 + 1;
    sa[i] = arr[i];
    if (i) sa[i] += sa[i - 1];
  }

  for (int i = 0; i < n; ++i) {
    s[i] = 1.0 / arr[i];
    if (i) s[i] += s[i - 1];
  }

  memset(wh, -1, sizeof(wh));
  for (int i = 0; i < n; ++i) {
    dp[1][i] = 1.0 * sa[i] / arr[i];
    if (i) dp[1][i] += dp[1][i - 1];
  }

  // cout << get(0, 2) << endl;
  // cout << get(3, 5) << endl;

  for (int j = 2; j <= k; ++j) {
    int p = 0;
    vector<pt> v;
    for (int i = 0; i < n; ++i) {
      dp[j][i] = 1e+20;
      if (i + 1 < j) {
        continue;
      }
      // pt a = {(double) (sa[n - 1] - (i ? sa[i - 1] : 0)), (double) dp[j - 1][i], i};
      pt a = {(double) -sa[i], double(-dp[1][i] + sa[i] * s[i] + dp[j - 1][i]), i};
      while (v.size() > 1 && !cw(v[v.size() - 2], v.back(), a)) v.pop_back();
      v.push_back(a);

      p = min(p, (int) v.size() - 1);
      double X = s[i];
      while (p + 1 < v.size() && v[p].x * X + v[p].y > v[p + 1].x * X + v[p + 1].y) ++p;
      
      for (int t = max(v[p].id - 5, 0); t <= v[p].id + 5 && t < i; ++t) {
        long double val = dp[j - 1][t] + get(t + 1, i);
        // cout << j << "  " << i << " " << val << endl;
        if (dp[j][i] > val) {
          dp[j][i] = val;
          // wh[j][i] = t;
        }
      }
      // cout << j << "  " << i << " " << dp[j][i] << endl;
    }
  }
  printf("%.10lf\n", (double) dp[k][n - 1]);

  // long double ans = 1e+20;

  // long double l = 0, r = 1e+17;
  // for (int it = 0; it < 100; ++it) {
  //   long double m = (l + r) / 2; 
  //   long double curA = 0, cur = 0, sum = 0;
  //   int cnt = 1;
  //   for (int i = 0; i < n; ++i) {
  //     long double v = cur + (sum + arr[i]) / arr[i];
  //     if (v < m) {
  //       cur = v;
  //       sum += arr[i];
  //     } else {
  //       curA += cur;
  //       cur = 1;
  //       sum = arr[i];
  //       ++cnt;
  //     }
  //   }
  //   curA += cur;

  //   if (cnt <= k) ans = min(ans, curA);

  //   if (cnt <= k) r = m;
  //   else l = m;
  // } 
  // printf("%.10lf\n", (double) ans);

  return 0;
}