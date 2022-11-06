#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

const int maxn = 16, maxmaxsave = maxn * (maxn - 1) / 2;
int dp[1 << maxn][maxmaxsave + 1];
char color[maxn];
int needr[maxn], needb[maxn];

int main() {
  int n;
  scanf("%d", &n);
  const int maxsave = n * (n - 1) / 2;
  for (int i = 0; i < n; ++i)
    scanf(" %c %d %d", &color[i], &needr[i], &needb[i]);

  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (int s = 0; s < ((1<<n)-1); ++s)
    for (int saver = 0; saver <= maxsave; ++saver) {
      const int saveb = dp[s][saver];
      if (saveb == -1) continue;

      int nr = 0, nb = 0;
      for (int i = 0; i < n; ++i)
        if (s & (1<<i)) {
          if (color[i] == 'R') ++nr;
          else ++nb;
        }

      for (int i = 0; i < n; ++i)
        if (!(s & (1<<i))) {
          int extracostr = max(needr[i] - nr, 0);
          int extracostb = max(needb[i] - nb, 0);
          int extrasaver = needr[i] - extracostr;
          int extrasaveb = needb[i] - extracostb;

          int news = s + (1<<i);
          int newsaver = saver + extrasaver;
          int newsaveb = saveb + extrasaveb;
          assert(newsaver <= maxsave);
          assert(newsaveb <= maxsave);
          dp[news][newsaver] = max(dp[news][newsaver], newsaveb);
        }
    }

  int result = INT_MAX;
  int sumneedr = accumulate(needr, needr + n, 0);
  int sumneedb = accumulate(needb, needb + n, 0);

  for (int saver = 0; saver <= maxsave; ++saver) {
    const int saveb = dp[(1<<n)-1][saver];
    if (saveb == -1) continue;

    result = min(result,
                 max(sumneedr - saver, sumneedb - saveb) + n);
  }

  printf("%d\n", result);

  return 0;
}