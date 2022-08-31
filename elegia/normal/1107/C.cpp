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

const int N = 200010;

int n;
int a[N];
char s[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  ll ans = 0;
  int k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  scanf("%s", s + 1);
  char cur = s[1];
  vector<int> buf;
  buf.push_back(a[1]);
  for (int i = 2; i <= n + 1; ++i) {
    if (cur != s[i]) {
      if (buf.size() <= k)
        ans += accumulate(buf.begin(), buf.end(), 0LL);
      else
        ans += accumulate(buf.begin(), (nth_element(buf.begin(), buf.begin() + k, buf.end(), greater<int>()), (buf.begin() + k)), 0LL);
      buf.clear();
      cur = s[i];
    }
    buf.push_back(a[i]);
  }
  printf("%lld\n", ans);

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}