#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <memory.h>

using namespace std;

int solve(int k) {
  ++k;
  int ret = 0;
  for (int mask = 1; mask < (1<<k); ++mask) {
    bool ok = true;
    for (int i = 0; i < k; ++i)
      if (mask & (1<<i))
      for (int j = 0; j < k; ++j)
        if (mask & (1<<j)) {
          if (mask & (1LL<<(i ^ j)));
          else ok = false;
        }
    ret += ok;
    if (ok) {
      for (int i = 0; i < k; ++i)
        if (mask & (1<<i)) cout << i << " ";
      cout << endl;
    }
  }
  return ret;
}

int res[1000002] = {0};
int mod = 1000000007;

int sum(int x) {
  if (x == 0) return 1;
  int bit = 1;
  while (2 * bit <= x) {
    bit <<= 1;
  }
  int ret = sum(bit - 1) + sum(x - bit);
  if (ret >= mod) {
    ret -= mod;
  }
  return ret;
}

map<pair<int, int>, int> f;

int go(int x, int k) {
  if (x == 0) return k == 1;
  if (f.count(make_pair(x, k))) {
    return f[make_pair(x, k)];
  }
  int bit = 1;
  while (2 * bit <= x) {
    bit <<= 1;
  }
  

  return 0;
}

//----- new solution -------

int dp[32][32][32];

void update(int& r, int a) {
  r += a;
  if (r >= mod) r-= mod;
}

int main() {
  int k;
  scanf("%d", &k);
  vector<int> v;
  while (k > 0) {
    v.push_back(k & 1);
    k >>= 1;
  }
  reverse(v.begin(), v.end());
  dp[0][0][0] = 1;
  for (int bit = 0; bit < v.size(); ++bit) {
    dp[bit + 1][0][1] = 1;
    for (int cnt = 0; cnt <= v.size(); ++cnt) {
      for (int ls = 0; ls < 2; ++ls) {
        if (dp[bit][cnt][ls]) {
          if (ls || v[bit] == 1)
            update(dp[bit + 1][cnt + 1][ls], dp[bit][cnt][ls]);
          if (cnt > 0) {
            update(dp[bit + 1][cnt][ls || (v[bit] == 1)], 1LL * dp[bit][cnt][ls] * (1<<(cnt - 1)) % mod);
            if (ls || v[bit] == 1)
              update(dp[bit + 1][cnt][ls], 1LL * dp[bit][cnt][ls] * (1<<(cnt - 1)) % mod);
          }
        }
      }
    }
  }
  int ans = 0;
  for (int cnt = 0; cnt <= v.size(); ++cnt) {
    update(ans, dp[v.size()][cnt][0]);
    update(ans, dp[v.size()][cnt][1]);
  }
  printf("%d\n", ans);

  // res[0] = 1;
  // int bit = 0;
  // for (int i = 1; i <= 1000000; ++i) {
  //   if (i >= (1<<(bit + 1))) ++bit;
  //   res[i] = res[i - 1] + res[i - (1<<bit)];
  //   if (res[i] >= mod) res[i] -= mod;
  // }

  // for (int i = 0; i <= 20; ++i) {
  //   puts("---------------------");
  //   solve(i);
  // }

  // solve(20);

  // for (int i = 0; i <= 15; ++i)
  //   cout << i << "  " << solve(i) << "  " << res[i] << "  " << go(i) << endl;

  return 0;
}