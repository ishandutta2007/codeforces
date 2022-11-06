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

int parity(int a) { return (a%2+2)%2; }

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int neven = 0, nodd = 0;
  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    if (v%2 == 0) ++neven;
    else ++nodd;
  }

  int winner = -1;
  int nmove = n-k, nmove0 = nmove/2, nmove1 = (nmove+1)/2;
  if (nmove0 >= neven) {
    int res = parity(nodd - (nmove0 - neven) - nmove1);
    if (res == 0)
      winner = 0;
  }
  if (nmove0 >= nodd) {
    winner = 0;
  }
  if (nmove1 >= neven) {
    int res = parity(nodd - (nmove1 - neven) - nmove0);
    if (res == 1) winner = 1;
  }
  if (nmove1 >= nodd) {
  }

  if (winner == -1) {
    if (n == k) winner = nodd%2;
    else {
      if (nmove1 > nmove0) winner = 1;
      else winner = 0;
    }
  }

  if (winner == 0) printf("Daenerys\n");
  else printf("Stannis\n");

  return 0;
}