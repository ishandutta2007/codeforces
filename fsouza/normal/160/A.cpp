#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> v(n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  int sum = accumulate(v.begin(), v.end(), 0);
  sort(v.begin(), v.end());
  int have = 0;
  int ret = 0;
  for (int i = n-1; i >= 0; i--)
    if (have <= sum-have) {
      have += v[i];
      ret++;
    }

  printf("%d\n", ret);

  return 0;
}