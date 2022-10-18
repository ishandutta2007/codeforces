#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <cmath>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> p(n);
  for (int i = 0; i < n; ++i)
    cin >> p[i];

  double ans = 0;
  int cnt[102] = {0};
  double loser[102] = {0};
  for (int i = 0; i < n; ++i) loser[i] = 1.0;
  for (int i = 1; i < n; ++i) {
    ++cnt[i];
    loser[i] *= 1.0 - p[i] / 100.0;
  }

  for (int st = n; st <= 300004; ++st) {
    int bi = -1; double pw = 0;
    
    double win[102] = {0}, pref[102] = {0}, suf[102] = {0};
    for (int i = 0; i < n; ++i) {
      win[i] = 1.0 - loser[i];
    }
    pref[0] = win[0];
    for (int i = 1; i < n; ++i)
      pref[i] = pref[i - 1] * win[i];
    suf[n - 1] = win[n - 1];
    for (int i = n - 2; i >= 0; --i)
      suf[i] = suf[i + 1] * win[i];

    for (int i = 0; i < n; ++i) {
      double curP = 1.0 * p[i] / 100 * loser[i];
      if (i) curP *= pref[i - 1];
      if (i + 1 < n) curP *= suf[i + 1];

      if (curP > pw) {
        pw = curP;
        bi = i;
      }
    }

    ans += st * pw;
    cnt[bi]++;
    loser[bi] *= 1.0 - p[bi] / 100.0;
  }

  printf("%.10lf\n", ans);

  return 0;
}