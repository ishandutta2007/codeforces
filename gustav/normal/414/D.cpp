#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <unordered_set>
#include <map>
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

#define pb push_back

#define MAX 100005

int m, k, p;
int a, b;

int dep[MAX];
llint _sum[MAX]; llint *sum = _sum + 1;
vector< int > T[MAX];

void dfs(int n, int dad = -1, int d = 0) {
  dep[n] = d;
  for (int i = 0; i < T[n].size(); ++i) {
    int c = T[n][i];
    if (c == dad) continue;
    dfs(c, n, d + 1);
  }
}

int main(void)
{
  scanf("%d%d%d", &m, &k, &p);

  for (int i = 0; i < m - 1; ++i) {
    scanf("%d%d", &a, &b); --a; --b;
    T[a].pb(b);
    T[b].pb(a);
  }

  dfs(0);

  sort(dep, dep + m);
  
  for (int i = 0; i < m; ++i)
    sum[i] = sum[i - 1] + dep[i];

  int sol = 0;
  for (int i = 1; i < m; ++i) {
    int lo = 1, hi = min(i, k), mid;
    while (lo < hi) {
      mid = (lo + hi + 1) / 2;
      if ((llint)mid * dep[i] - sum[i] + sum[i - mid] <= p)
        lo = mid;
      else
        hi = mid - 1;
    }
    sol = max(sol, lo);
  }

  printf("%d\n", sol);

  return 0;
}