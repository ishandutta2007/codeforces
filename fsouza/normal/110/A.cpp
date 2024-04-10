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

typedef long long lint;

int main() {
  lint v;
  cin >> v;

  int ml = 0;

  for (lint v2 = v; v2; v2 /= 10) {
    int d = v2%10;
    if (d == 4 || d == 7)
      ml++;
  }

  bool ok = true;

  if (ml == 0) ok = false;
  else {
    for (lint ml2 = ml; ml2; ml2 /= 10) {
      int d = ml2%10;
      if (d != 4 && d != 7)
	ok = false;
    }
  }

  if (ok) printf("YES\n");
  else printf("NO\n");

  return 0;
}