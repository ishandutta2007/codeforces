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
  int nzero;
  scanf("%d", &nzero);

  vector<int> nfive = {0};
  for (int v = 1; nfive.back() <= nzero; ++v)
    nfive.push_back(v/5 + nfive[v/5]);

  int res = count(nfive.begin(), nfive.end(), nzero);
  printf("%d\n", res);
  if (res > 0) {
    int many = 0;
    for (int v = 0; v < (int)nfive.size(); ++v)
      if (nfive[v] == nzero) {
	if (many > 0) printf(" ");
	printf("%d", v);
	++many;
      }
    printf("\n");
  }

  return 0;
}