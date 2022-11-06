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
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n, nq;
  scanf("%d %d", &n, &nq);

  vector<int> many(n, 0);
  vector<int> manyread(n, 0);
  int maxt = 0;
  vector<int> nots;
  int nid = -1;
  int result = 0;

  vector<int> until(n, 0);

  for (int q = 0; q < nq; ++q) {
    int kind;
    scanf("%d", &kind);
    if (kind == 1) {
      int x;
      scanf("%d", &x), --x;
      nots.push_back(x);
      ++many[x];
    } else if (kind == 2) {
      int x;
      scanf("%d", &x), --x;
      int diff = many[x] - manyread[x];
      result += diff;
      manyread[x] = many[x];
    } else {
      int t;
      scanf("%d", &t);
      maxt = max(maxt, t);
      while (nid+1 < maxt) {
	++nid;
	int x = nots[nid];
	++until[x];
	if (until[x] > manyread[x]) {
	  int diff = until[x] - manyread[x];
	  manyread[x] = until[x];
	  result += diff;
	}
      }
    }

    printf("%d\n", (int)nots.size() - result);
  }

  return 0;
}