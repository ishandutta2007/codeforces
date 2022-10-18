#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

const int MAXN = 100005;
const int inf = 1000000000;

int a[MAXN];
int dp[MAXN];
multiset< int > dps;
multiset< int > qs;
queue< int > q;

int main(void)
{
  int n, s, l;
  scanf("%d%d%d", &n, &s, &l);

  REP(i, n) scanf("%d", a + i);

  for (int i = n - 1; i >= 0; --i) {
    q.push(a[i]);
    qs.insert(a[i]);

    if (i + l <= n && i + l <= i + q.size()) 
      dps.insert(dp[i + l]);

    while (*--qs.end() - *qs.begin() > s) {
      if (i + l <= i + q.size()) dps.erase(dps.find(dp[i + q.size()]));
      qs.erase(qs.find(q.front()));
      q.pop();
    }

    dp[i] = dps.empty() ? inf : *dps.begin() + 1;
  }

  if (dp[0] >= inf)
    puts("-1");
  else
    printf("%d\n", dp[0]);

  return 0;
}