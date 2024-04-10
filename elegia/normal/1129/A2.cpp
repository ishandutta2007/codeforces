#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 5010;
int cnt[N], lead[N];

int main() {
#ifdef CAI_WEI_HAN
	freopen("test.in", "r", stdin);
#endif

  int n, m;
  scanf("%d%d", &n, &m);
  fill(lead + 1, lead + n + 1, 100000);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    ++cnt[a];
    if (b < a)
      b += n;
    lead[a] = min(lead[a], b);
  }
  for (int i = 1; i <= n; ++i)
    if (lead[i] > n)
      lead[i] -= n;
  //for (int i = 1; i <= n; ++i)
    //LOG("%d: %d\n", i, lead[i]);
  int mex = *max_element(cnt + 1, cnt + n + 1);
  for (int i = 1; i <= n; ++i) {
    int ans = n * (mex - 1), cur = 0;
    for (int j = 1; j <= n; ++j) {
      int th = 0;
      if (cnt[j] == mex) {
        if (lead[j] > j) {
          th = lead[j] - 1;
        } else {
          th = n + lead[j] - 1;
        }
      } else if (cnt[j] == mex - 1 && cnt[j] != 0) {
        if (lead[j] <= j)
          th = lead[j] - 1;
      }
      cur = max(cur, th);
     // LOG("%d: %d\n", j, th);
    }
  //  LOG("%d +%d\n", ans, cur);
    ans += cur;
    printf("%d ", ans);
    int tc = cnt[1], tl = lead[1];
    memmove(cnt + 1, cnt + 2, sizeof(int) * (n - 1));
    memmove(lead + 1, lead + 2, sizeof(int) * (n - 1));
    cnt[n] = tc;
    lead[n] = tl;
    for (int j = 1; j <= n; ++j)
      if (--lead[j] == 0)
        lead[j] = n;
  }

  return 0;
}