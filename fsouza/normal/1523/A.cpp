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
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n, m;
    scanf("%d %d", &n, &m);
    string s(n, ' ');
    scanf(" %s", &s[0]);
    string s2 = s;
    for (int j = 0, i = j; i != n; i = j) {
      while (j != n && s[j] == s[i]) ++j;
      int val = s[i] - '0';
      if (val == 0) {
        bool left_corner = (i == 0);
        bool right_corner = (j == n);
        if (left_corner && right_corner) {
        } else if (left_corner && !right_corner) {
          for (int k = j - 1; k >= i && ((j - 1) - k) < m; --k)
            s2[k] = '1';
        } else if (!left_corner && right_corner) {
          for (int k = i; k < j && (k - i) < m; ++k)
            s2[k] = '1';
        } else {
          for (int k = i; k < j && (k - i) < m; ++k)
            s2[k] = '1';
          for (int k = j - 1; k >= i && ((j - 1) - k) < m; --k)
            s2[k] = '1';
          int size = j - i;
          if (size % 2 == 1) {
            int mid = i + size / 2;
            s2[mid] = '0';
          }
        }
      }
    }
    printf("%s\n", s2.c_str());
  }
  return 0;
}