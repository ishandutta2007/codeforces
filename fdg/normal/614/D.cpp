#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int val[100005];

int main() {
  ios::sync_with_stdio(false);
  long long n, A, cf, cm, have;
  cin >> n >> A >> cf >> cm >> have;
  vector<pair<long long, int>> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first;
    v[i].second = i;
    val[i] = v[i].first;
  }
  sort(v.begin(), v.end());
  vector<long long> pref(n, 0);
  for (int i = 0; i < n; ++i) {
    pref[i] = v[i].first;
    if (i) pref[i] += pref[i - 1];
  }

  // if (1LL * A * n - pref[n - 1] <= have) {
  //   cout << 1LL * A * cm + 1LL * n * cf << endl;
  //   for (int i = 0; i < n; ++i)
  //     cout << A << " ";
  //   cout << endl;
  //   return 0;
  // }

  long long ans = 0, mv = -1, bcnt = -1, mx = -1, tp = -1;
  for (int i = n; i >= 0; --i) {
    long long need = 0;
    if (i < n) {
      need = 1LL * A * (n - i) - (pref[n - 1] - (i > 0 ? pref[i - 1] : 0));
    }
    // cout << i << "  " << need << endl;
    if (need > have) break;

    int l = 0, r = A + 1;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      int pos = upper_bound(v.begin(), v.end(), make_pair((long long) m, -1)) - v.begin();
      pos = min(pos - 1, i - 1);

      long long cs = 0;
      if (pos >= 0) {
        cs += pref[pos];
      }

      if ((have - need) >= 1LL * m * (pos + 1) - cs) l = m;
      else r = m;
    }

    long long curP = 1LL * l * cm + 1LL * (n - i) * cf;
    // cout << curP << " " << l << " " << n - i << endl;
    if (curP > ans) {
      ans = curP;
      mv = l;
      mx = n - i;
    }
  }
  // vector<long long> suf(n + 1, 0);
  // for (int i = n - 1; i >= 0; --i) {
  //   suf[i] = suf[i + 1] + A - v[i].first;
  // }

  // long long need = 0, cnt = 0;
  // for (int i = 0; i < v.size(); ++i) {
  //   if (i) {
  //     need += 1LL * cnt * (v[i].first - v[i - 1].first);
  //   }
  //   if (need > have) break;
  //   ++cnt;
  //   int l = i, r = n;
  //   while (r - l > 1) {
  //     int m = (l + r) >> 1;
  //     if (suf[m] <= have - need) r = m;
  //     else l = m;
  //   }

  //   long long add = min((i + 1 < n ? v[i + 1].first : A) - v[i].first, (have - need - suf[r]) / cnt);

  //   long long left = have - need - 1LL * add * cnt - suf[r];
  //   if (r == i + 1) {
  //     while (r > 0 && left && v[i].first + add == A - 1) {
  //       --left;
  //       --r;
  //     }
  //   }

  //   long long curP = 1LL * (v[i].first + add) * cm + 1LL * (n - r) * cf;
  //   if (curP > ans) {
  //     ans = curP;
  //     mv = v[i].first + add;
  //     bcnt = cnt;
  //     mx = n - r;
  //     tp = 1;
  //   }
  //   // cout << need << " " << curP << "  " << n - r << endl;
  // }

  // need = 0, cnt = 0;
  // for (int i = 0; i < v.size(); ++i) {
  //   if (i) {
  //     need += 1LL * cnt * (v[i].first - v[i - 1].first);
  //   }
  //   if (need > have) break;
  //   ++cnt;
  //   long long add = min((i + 1 < n ? v[i + 1].first : A) - v[i].first, (have - need) / cnt);

  //   long long tmpNeed = need + 1LL * add * cnt;

  //   int l = i, r = n;
  //   while (r - l > 1) {
  //     int m = (l + r) >> 1;
  //     if (suf[m] <= have - tmpNeed) r = m;
  //     else l = m;
  //   }

  //   long long left = have - tmpNeed - suf[r];
  //   if (r == i + 1) {
  //     while (r > 0 && left && v[i].first + add == A - 1) {
  //       --left;
  //       --r;
  //     }
  //   }

  //   long long curP = 1LL * (v[i].first + add) * cm + 1LL * (n - r) * cf;
  //   if (curP > ans) {
  //     ans = curP;
  //     mv = v[i].first + add;
  //     bcnt = cnt;
  //     mx = n - r;
  //     tp = 2;
  //   }
  //   // cout << need << " " << curP << "  " << n - r << endl;
  // }
  cout << ans << endl;
  for (int i = 0; i < n; ++i) {
    if (v[i].first < mv)
      val[v[i].second] = mv;
  }
  for (int i = 0; i < mx; ++i) {
    val[v[n - 1 - i].second] = A;
  }
  for (int i = 0; i < n; ++i) {
    cout << val[i] << " ";
  }
  cout << endl;
  return 0;
}