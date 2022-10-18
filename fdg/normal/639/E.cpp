#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int p[150005], t[150005];

int arr[150005];

bool cmp(int i, int j) {
  return 1LL * p[i] * t[j] > 1LL * p[j] * t[i];
}

double mn[150005], mx[150005];

int main() {
  int n;
  long long T = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &p[i]);
  for (int i = 0; i < n; ++i)
    scanf("%d", &t[i]), arr[i] = i, T += t[i];

  sort(arr, arr + n, cmp);

  vector<pair<int, int>> v;
  for (int i = 0; i < n; ++i) {
    v.push_back({p[i], i});
  }
  sort(v.begin(), v.end());

  double l = 0, r = 1;
  for (int it = 0; it < 78; ++it) {
    double m = (l + r) / 2;

    long long tm = 0;
    for (int i = 0; i < n; ) {
      int st = i;
      long long total = 0;
      while (i < n && !cmp(arr[st], arr[i]) && !cmp(arr[i], arr[st])) total += t[arr[i]], ++i;
      for (int j = st; j < i; ++j) {
        mx[arr[j]] = 1.0 * p[arr[j]] * (1 - 1.0 * m * (tm + t[arr[j]]) / T);
        mn[arr[j]] = 1.0 * p[arr[j]] * (1 - 1.0 * m * (tm + total) / T);
      }
      tm += total;
    }

    // cout << m << endl;
    // for (int i = 0; i < n; ++i)
    //   cout << p[i] << " " << mn[i] << "  " << mx[i] << endl;

    bool ok = false;
    double mxt = 0;
    for (int i = 0; i < n && !ok; ) {
      int st = i;
      while (i < n && v[i].first == v[st].first) ++i;

      for (int j = st; j < i && !ok; ++j) {
        if (mn[v[j].second] < mxt) {
          ok = true;
        }
      }
      for (int j = st; j < i; ++j)
        mxt = max(mxt, mx[v[j].second]);
    }

    if (ok) r = m;
    else l = m;
  }
  printf("%.11lf\n", (l + r) / 2);

  return 0;
}