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
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> rowmany(n, 0), colmany(n, 0);
  
  for (int y = 0; y < n; ++y) {
    string line(n+1, ' ');
    scanf("%s", &line[0]);
    for (int x = 0; x < n; ++x)
      if (line[x] == 'C')
	++rowmany[y], ++colmany[x];
  }

  int result = 0;
  for (vector<int> &many : {ref(rowmany), ref(colmany)})
    for (int i = 0; i < n; ++i)
      if (many[i] >= 2)
	result += many[i] * (many[i]-1) / 2;
  printf("%d\n", result);
  
  return 0;
}