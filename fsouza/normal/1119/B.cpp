#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

bool fits(vector<int> sizes, int h) {
  sort(sizes.rbegin(), sizes.rend());
  lint sum = 0LL;
  for (int i = 0; i < (int)sizes.size(); i += 2)
    sum += sizes[i];
  return sum <= h;
}

int main() {
  int n, h;
  scanf("%d %d", &n, &h);
  vector<int> sizes(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &sizes[i]);

  int l = 1, r = n;
  while (l < r) {
    int m = l + (r - l + 1) / 2;
    if (fits(vector<int>(sizes.begin(), sizes.begin() + m), h)) l = m;
    else r = m - 1;
  }
  printf("%d\n", l);

  return 0;
}