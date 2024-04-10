#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)
#define MAXN 100000

typedef long long lint;

using namespace std;

int v[MAXN], u[MAXN];
lint sumv[MAXN+1], sumu[MAXN+1];

int main(int argc, char ** argv)
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);

  for (int i = 0; i < n; i++) u[i] = v[i];
  sort(u, u+n);

  sumv[0] = sumu[0] = 0;
  for (int i = 0; i < n; i++) {
    sumv[i+1] = sumv[i] + v[i];
    sumu[i+1] = sumu[i] + u[i];
  }

  int nq;

  scanf("%d", &nq);

  for (int q = 0; q < nq; q++) {
    int type, l, r;
    scanf("%d %d %d", &type, &l, &r);
    lint *sum = (type == 1) ? sumv : sumu;
    printf("%I64d\n", sum[r] - sum[l-1]);
  }

  return 0;
}