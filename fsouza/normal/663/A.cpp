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
  vector<int> signs;
  int final;

  signs.push_back(+1);
  char c;
  scanf(" %*c");
  while (scanf(" %c", &c), c != '=') {
    if (c == '+') signs.push_back(+1);
    else signs.push_back(-1);
    scanf(" %c", &c);
  }
  scanf("%d", &final);

  int npos = count(signs.begin(), signs.end(), +1);
  int nneg = count(signs.begin(), signs.end(), -1);

  int minv = npos * 1 - nneg * final;
  int maxv = npos * final - nneg * 1;

  if (minv <= final && final <= maxv) {
    vector<int> result(signs.size());
    int have = 0;
    for (int i = 0; i < (int)signs.size(); ++i) {
      if (signs[i] == +1) result[i] = 1, have += 1;
      else result[i] = final, have -= final;
    }
    for (int i = 0; i < (int)signs.size(); ++i) {
      int need = final - have;
      if (signs[i] == +1) {
	int canadd = final - result[i];
	int change = min(need, canadd);
	result[i] += change;
	have += change;
      } else {
	int candel = result[i] - 1;
	int change = min(need, candel);
	result[i] -= change;
	have += change;
      }
    }

    printf("Possible\n");
    printf("%d", result[0]);
    for (int i = 1; i < (int)result.size(); ++i) {
      if (signs[i] == +1) printf(" + %d", result[i]);
      else printf(" - %d", result[i]);
    }
    printf(" = %d\n", final);
  } else printf("Impossible\n");

  return 0;
}