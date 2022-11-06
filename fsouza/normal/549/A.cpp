#include <algorithm>
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
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<string> table(n, string(m, ' '));
  for (string &line : table)
    scanf("%s", &line[0]);

  int result = 0;
  int many[26] = {};
  for (int y = 0; y+1 < n; ++y)
    for (int x = 0; x+1 < m; ++x) {
      for (int dy = 0; dy < 2; ++dy)
	for (int dx = 0; dx < 2; ++dx)
	  ++many[table[y+dy][x+dx]-'a'];

      int nhave = 0;
      for (char c : {'f', 'a', 'c', 'e'})
	if (many[c-'a'] > 0)
	  ++nhave;
      if (nhave == 4) ++result;

      for (int dy = 0; dy < 2; ++dy)
	for (int dx = 0; dx < 2; ++dx)
	  --many[table[y+dy][x+dx]-'a'];
    }

  printf("%d\n", result);

  return 0;
}