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
  int now, left, right;
  scanf("%d %d %d", &now, &left, &right);
  int n;
  scanf("%d", &n);
  int result = 0;
  for (int i = 0; i < n; ++i) {
    int pos;
    scanf("%d", &pos);
    if (left < pos && pos < right)
      ++result;
  }
  printf("%d\n", result);

  return 0;
}