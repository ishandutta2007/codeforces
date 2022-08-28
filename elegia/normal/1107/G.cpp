#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 300010;

int n, a;
ll ans;
int l[N], r[N], d[N];
ll p[N], s[N], sum[N];
pair<int, int> ed[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d", &n, &a);
  for (int i = 1; i <= n; ++i) {
    int c;
    scanf("%d%d", &d[i], &c);
    ans = max(ans, sum[i] = s[i] = p[i] = a - c);
  }
  for (int i = 1; i < n; ++i)
    ed[i] = make_pair(d[i + 1] - d[i], i);
  sort(ed + 1, ed + n);
  iota(l + 1, l + n + 1, 1);
  iota(r + 1, r + n + 1, 1);
  for (int j = 1; j < n; ++j) {
    int i = ed[j].second;
    int ll = l[i], rl = i + 1;
    r[ll] = r[rl];
    l[r[rl]] = ll;
//    LOG("%d-%d %d %lld %lld\n", i, i + 1, ed[j].first, s[ll], p[rl]);
    ans = max(ans, s[ll] - ed[j].first * (long long)ed[j].first + p[rl]);
    s[ll] = max(s[rl], sum[rl] + s[ll]);
    p[ll] = max(p[ll], sum[ll] + p[rl]);
    sum[ll] += sum[rl];
  }
  printf("%lld\n", ans);

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}