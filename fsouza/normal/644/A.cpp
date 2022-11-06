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
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);

  if (n > a*b) printf("-1\n");
  else {
    int nexteven = 0, nextodd = 1;
    for (int y = 0; y < a; ++y) {
      for (int x = 0; x < b; ++x) {
	if (x > 0) printf(" ");
	if ((y+x)%2 == 0) {
	  if (nexteven < n) {
	    printf("%d", nexteven+1);
	    nexteven += 2;
	  } else printf("0");
	} else {
	  if (nextodd < n) {
	    printf("%d", nextodd+1);
	    nextodd += 2;
	  } else printf("0");
	}
      }
      printf("\n");
    }
  }
  
  return 0;
}