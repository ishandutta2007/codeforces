#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <climits>

#define INF (INT_MAX/2)

typedef long long lint;

using namespace std;

int main() {
  int n, m;

  scanf("%d %d", &n, &m);
  vector<int> v(n, 0);

  for (int i = 0; i < n; i++) scanf("%d", &v[i]);

  int result = 0;

  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b); a--, b--;
    result += min(v[a], v[b]);
  }

  printf("%d\n", result);

  return 0;
}