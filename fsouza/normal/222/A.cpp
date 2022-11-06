#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int main() {
  int n, k;

  scanf("%d %d", &n, &k), k--;

  vector<int> a(n);

  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  
  int ret = 0;

  for (int i = 0; i < k; i++)
    if (a[i] != a[k])
      ret = i+1;

  for (int i = k+1; i < n; i++)
    if (a[i] != a[k])
      ret = -1;

  printf("%d\n", ret);

  return 0;
}