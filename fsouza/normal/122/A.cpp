#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <numeric>

using namespace std;

int main() {
  int n;

  scanf("%d", &n);

  bool ret = false;
  
  for (int v = 1; v <= n; v++)
    if (n % v == 0) {
      bool lucky = true;
      for (int x = v; x; x /= 10)
	if (x%10 != 7 && x%10 != 4)
	  lucky = false;
      if (lucky)
	ret = true;
    }

  if (ret) printf("YES\n");
  else printf("NO\n");

  return 0;
}