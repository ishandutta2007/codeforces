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
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int result = 0;

  int n = s.size();
  for (int i = 0; i < n; ++i)
    for (int j = i; j < n; ++j) {
      string sub(s.begin() + i, s.begin() + j + 1);
      string rev_sub = sub;
      reverse(rev_sub.begin(), rev_sub.end());
      if (sub != rev_sub)
        result = max(result, j - i + 1);
    }

  printf("%d\n", result);

  return 0;
}