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
  bool ok = true;
  char last = 'a' - 1;
  for (char c : s) {
    if (c > last) {
      if (c == last + 1) last = c;
      else {
        ok = false;
        break;
      }
    }
  }
  if (ok) printf("YES\n");
  else printf("NO\n");
  return 0;
}