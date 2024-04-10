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
    vector<string> field(n, string(m, ' '));
    bool ok0 = true, ok1 = true;

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        scanf(" %c", &field[i][j]);
        if (field[i][j] == '.') continue;
        if ((i + j) % 2 == (field[i][j] == 'R')) ok0 = false;
        else ok1 = false;
      }

    if (!ok0 && !ok1) {
      printf("NO\n");
    } else {
      printf("YES\n");
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          char let;
          if (ok1) {
            let = ((i + j) % 2 == 1) ? 'R' : 'W';
          } else {
            let = ((i + j) % 2 == 1) ? 'W' : 'R';
          }
          printf("%c", let);
        }
        printf("\n");
      }
    }
  }
  return 0;
}