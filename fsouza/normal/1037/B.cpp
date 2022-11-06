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

int main() {
  int n, s;
  scanf("%d %d", &n, &s);
  vector<int> values(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &values[i]);
  sort(values.begin(), values.end());
  int mid = values.size() / 2;

  lint result = 0LL;
  for (int i = 0; i < mid; ++i)
    result += max(values[i] - s, 0);
  result += abs(values[mid] - s);
  for (int i = mid + 1; i < (int)values.size(); ++i)
    result += max(s - values[i], 0);

  printf("%lld\n", result);

  return 0;
}