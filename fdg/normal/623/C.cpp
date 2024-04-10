#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int x[100005], y[100005];

long long calc(int n, int i, int m, const vector<pair<int, int>> &v, const vector<pair<int, int>> &pref, const vector<pair<int, int>> &suf) {
  int minx = v[i].first, maxx = v[m].first;
  long long v1 = 1e+18;
  if (i > 0 || m + 1 < n) {
    int miny = 1e+9, maxy = -1e+9;
    if (i > 0) {
      miny = min(miny, pref[i - 1].first);
      maxy = max(maxy, pref[i - 1].second);
    }
    if (m + 1 < n) {
      miny = min(miny, suf[m + 1].first);
      maxy = max(maxy, suf[m + 1].second);
    }
    v1 = max(maxx - minx, maxy - miny);
    v1 = v1 * v1;

    long long mx = max(abs(maxx), abs(minx)), my = max(abs(maxy), abs(miny));
    v1 = max(v1, 1LL * mx * mx + 1LL * my * my);
  } else {
    v1 = 1LL * (maxx - minx) * (maxx - minx);
  }

  return v1;
}

long long solve(int n) {
  vector<pair<int, int>> v;
  for (int i = 0; i < n; ++i)
    v.push_back({x[i], y[i]});
  sort(v.begin(), v.end());

  vector<pair<int, int>> pref(n), suf(n);

  pref[0] = {v[0].second, v[0].second};
  for (int i = 1; i < n; ++i) {
    pref[i] = {min(pref[i - 1].first, v[i].second), max(pref[i - 1].second, v[i].second)};
  }

  suf[n - 1] = {v[n - 1].second, v[n - 1].second};
  for (int i = n - 2; i >= 0; --i) {
    suf[i] = {min(suf[i + 1].first, v[i].second), max(suf[i + 1].second, v[i].second)};
  }

  // for (int l = 0; l < n; ++l)
  //   for (int r = l; r < n; ++r)
  //     cout << l << "  " << r << " " << calc(n, l, r, v, pref, suf) << endl;

  long long l = -1, r = 1e+18;
  while (r - l > 1) {
    long long m = (l + r) / 2;

    bool ok = false;

    for (int i = 0; i < n; ++i) {
      int l2 = i, r2 = n;
      while (r2 - l2 > 1) {
        int m2 = (l2 + r2) / 2;
        if (1LL * (v[m2].first - v[i].first) * (v[m2].first - v[i].first) <= m
          && abs(v[m2].first) <= abs(v[i].first)) l2 = m2;
        else r2 = m2;
      }

      // cout << m << "  " << i << " " << l2 << "  " << calc(n, i, l2, v, pref, suf) << endl;

      if (calc(n, i, l2, v, pref, suf) <= m) {
        ok = true;
        break;
      }
    }

    if (ok) r = m;
    else l = m;
  }

  return r;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
  }

  long long ret = solve(n);
  for (int i = 0; i < n; ++i)
    x[i] *= -1;
  ret = min(ret, solve(n));
  for (int i = 0; i < n; ++i)
    swap(x[i], y[i]);
  ret = min(ret, solve(n));
  for (int i = 0; i < n; ++i)
    x[i] *= -1;
  ret = min(ret, solve(n));
  cout << ret << endl;
  return 0;
}