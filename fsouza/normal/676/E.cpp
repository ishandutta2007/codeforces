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

lint eval(vector<int> &poly, int x) {
  lint res = 0;
  for (int i = (int)poly.size()-1; i >= 0; --i) {
    res = res * x + poly[i];
    if (abs(res) > 2000000000) {
      res = -1;
      break;
    }
  }
  return res;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<bool> set(n+1);
  vector<int> val(n+1);

  int totmove = n+1, nset = 0;

  for (int i = 0; i <= n; ++i) {
    char c;
    scanf(" %c", &c);
    if (c == '?') set[i] = false;
    else {
      ungetc(c, stdin);
      scanf("%d", &val[i]);
      set[i] = true;
      ++nset;
    }
  }

  bool result;
  if (k == 0) {
    if (set[0]) {
      result = (val[0] == 0);
    } else {
      result = (nset%2 == 1);
    }
  } else if (nset != totmove) {
    result = (totmove%2 == 0);
  } else {
    int res = eval(val, k);
    result = (res == 0);
  }

  if (result) printf("Yes\n");
  else printf("No\n");

  return 0;
}