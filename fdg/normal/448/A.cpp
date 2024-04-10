#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  int a1, a2, a3, b1, b2, b3, n;
  cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
  if ((a1 + a2 + a3 + 4) / 5 + (b1 + b2 + b3 + 9) / 10 <= n) puts("YES");
  else puts("NO");
  return 0;
}