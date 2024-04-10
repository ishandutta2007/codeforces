#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  int v[7];
  for (int i = 0; i < 7; i++) scanf("%d", &v[i]);
  
  int ans;

  for (int rep = 0;; rep++) {
    for (int i = 0; i < 7; i++) {
      n -= v[i];
      if (n <= 0) {
	ans = i;
	goto done;
      }
    }
  }

 done:

  printf("%d\n", ans+1);

  return 0;
}