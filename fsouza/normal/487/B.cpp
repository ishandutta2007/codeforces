#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define MAXN 100000
#define INF 1000000000

using namespace std;

int a[MAXN], dp[MAXN+1];

int main() {
  int n, s, l;

  scanf("%d %d %d", &n, &s, &l);

  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  set <pair <int, int> > as;
  set <pair <int, int> > dps;

  dp[0] = 0;

  int i = 0;
  for (int j = 1; j <= n; j++) {
    if (j - l >= i)
      dps.insert(make_pair(dp[j - l], j - l));

    as.insert(make_pair(a[j-1], j-1));
    while (!as.empty() && (as.rbegin() -> first - as.begin() -> first) > s) {
      if (i <= j - l)
	dps.erase(make_pair(dp[i], i));
      as.erase(make_pair(a[i], i));
      i++;
    }
    
    if (dps.empty()) dp[j] = INF;
    else dp[j] = min(dps.begin() -> first + 1, INF);
  }

  if (dp[n] == INF) printf("-1\n");
  else printf("%d\n", dp[n]);

  return 0;
}