#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int mod = 1000000007;

int dv[1000005];
int cnt[1000006];

inline void add(int &r, int a) {
  r += a;
  if (r >= mod) r -= mod;
}

int mPow(int a, int x) {
  int ret = 1;
  while (x > 0) {
    if (x & 1) ret = 1LL * ret * a % mod;
    a = 1LL * a * a % mod;
    x >>= 1;
  }
  return ret;
}

int fact[200006], rfact[200006], C[200006];

int _C(int n, int k) {
  if (k > n || k < 0) return 0;
  return 1LL * fact[n] * rfact[k] % mod * rfact[n - k] % mod;
}

int dp[1000006], n, k, q;//, dvs[1000006], sz, psz;
int rem[55] = {0}, base;

// int a[1000006], b[1000006];

// inline void go2(const vector<pair<int, int>> &v, int pos, int num) {
//   if (pos == v.size()) {
//     if (base != num) {
//       // a[psz] = base;
//       // b[psz] = num;
//       // ++psz;
//       add(dp[base], mod - dp[num]);
//       // cout << base << " " << num << " " << dp[base] << "  " << dp[num] << endl;
//     }
//     return;
//   }
//   for (int i = 0; i <= rem[pos]; ++i) {
//     go2(v, pos + 1, num);
//     num *= v[pos].first;
//   }
// }

int p[1000006];
int ans = 0, old[1000006];

inline void go3(const vector<pair<int, int>> &v, int pos, int num) {
  if (pos == v.size()) {
    ++cnt[num];
    add(ans, mod - 1LL * p[num] * (old[num] - C[cnt[num]] + mod) % mod);
    old[num] = C[cnt[num]];

    // base = num;
    // go2(v, 0, base);
    // if (dp[base])
    //   add(ans, 1LL * base * dp[base] % mod);
    return;
  }
  vector<int> tmp(v[pos].second + 1);
  for (int i = 0; i <= v[pos].second; ++i) {
    tmp[i] = num;
    num *= v[pos].first;
  }
  rem[pos] = 0;
  for (int i = v[pos].second; i >= 0; --i) {
    go3(v, pos + 1, tmp[i]);
    ++rem[pos];
  }
}

void go1(const vector<pair<int, int>> &v, int pos, int num) {
  if (pos == v.size()) {
    if (base != num) {
      p[base] -= p[num];
    }
    return;
  }
  for (int i = 0; i <= v[pos].second; ++i) {
    go1(v, pos + 1, num);
    num *= v[pos].first;
  }
}

int main() {
  scanf("%d%d%d", &n, &k, &q);

  fact[0] = rfact[0] = 1;
  for (int i = 1; i <= n + q; ++i) {
    fact[i] = 1LL * fact[i - 1] * i % mod;
    rfact[i] = mPow(fact[i], mod - 2);
  }
  for (int i = 0; i <= n + q; ++i) {
    C[i] = _C(i, k);
  }

  for (int i = 2; i <= 1000000; ++i) {
    if (dv[i] == 0) {
      for (int j = i; j <= 1000000; j += i) {
        if (dv[j] == 0) dv[j] = i;
      }
    }
  }

  for (int i = 1; i <= 1000000; ++i) {
    p[i] = i;
    int aa = i;
    vector<pair<int, int>> v;
    while (aa > 1) {
      int d = dv[aa], cnt = 0;
      while (aa % d == 0) {
        aa /= d;
        ++cnt;
      }
      v.emplace_back(make_pair(d, cnt));
    }
    base = i;
    go1(v, 0, 1);
  }

  // for (int i = 0; i < 10; ++i)
  //   cout << p[i] << " ";
  // cout << endl;

  for (int i = 0; i < n + q; ++i) {
    int aa;
    scanf("%d", &aa);
    vector<pair<int, int>> v;
    while (aa > 1) {
      int d = dv[aa], cnt = 0;
      while (aa % d == 0) {
        aa /= d;
        ++cnt;
      }
      v.emplace_back(make_pair(d, cnt));
    }

    go3(v, 0, 1);

    if (i >= n) {
      printf("%d\n", ans);
    }
  }

  return 0;
}