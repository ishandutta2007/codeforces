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
  string s;
  cin >> s;
  int na = 0;
  for (char c : s)
    if (c == 'a')
      ++na;
  int result = na + min(na - 1, (int)s.size() - na);
  printf("%d\n", result);
  return 0;
}