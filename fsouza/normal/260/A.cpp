#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>

typedef long long lint;

using namespace std;

int main() {
  int a, b, n;

  cin >> a >> b >> n;

  int a2 = -1;

  for (int d = 0; d < 10; d++)
    if ((a*10 + d) % b == 0)
      a2 = a*10 + d;

  if (a2 == -1) {
    cout << -1 << endl;
    return 0;
  } else {
    cout << a2;
    for (int nop = 1; nop < n; nop++)
      cout << 0;
    cout << endl;
  }

  return 0;
}