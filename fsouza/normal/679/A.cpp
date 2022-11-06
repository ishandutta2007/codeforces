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
  vector<int> small = {2, 3, 5, 7};
  vector<bool> smallres(small.size());
  vector<int> mid = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
  vector<bool> midres(mid.size());

  for (int i = 0; i < (int)small.size(); ++i) {
    printf("%d\n", small[i]);
    fflush(stdout);
    static char result[4];
    scanf("%s", result);
    smallres[i] = (result[0] == 'y');
  }

  int nsmall = 0;
  for (int i = 0; i < (int)small.size(); ++i)
    if (smallres[i])
      ++nsmall;

  bool prime;

  if (nsmall == 0) prime = true;
  else if (nsmall >= 2) prime = false;
  else {
    int guy = -1;
    for (int i = 0; i < (int)small.size(); ++i)
      if (smallres[i]) {
	guy = small[i];
	break;
      }
    assert(guy != -1);

    prime = true;
    for (int i = 0; i < (int)mid.size(); ++i)
      if (mid[i] * guy <= 100) {
	printf("%d\n", mid[i] * guy);
	fflush(stdout);
	static char result[4];
	scanf("%s", result);
	if (result[0] == 'y') {
	  prime = false;
	  break;
	}
      }
  }

  if (prime) printf("prime\n");
  else printf("composite\n");
  fflush(stdout);

  return 0;
}