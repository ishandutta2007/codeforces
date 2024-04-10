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

const int mod = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int result = 0;
  int bcount = 0;
  for (int i = (int)s.size() - 1; i >= 0; --i) {
    if (s[i] == 'b') {
      ++bcount;
      if (bcount == mod) bcount = 0;
    } else {
      result += bcount;
      if (result >= mod) result -= mod;
      bcount *= 2;
      if (bcount >= mod) bcount -= mod;
    }
  }
  printf("%d\n", result);
  return 0;
}