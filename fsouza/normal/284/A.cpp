#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <set>

typedef long long lint;

using namespace std;

int main() {
  int p;

  cin >> p;

  int ret = 0;
  for (int x = 1; x < p; x++) {
    bool ok = true;
    for (int exp = 1, xe = x; exp <= p-2; xe = (xe * x) % p, exp++)
      if (xe == 1)
        ok = false;
    if (ok) ret++;
  }

  cout << ret;
  cout << endl;

  return 0;
}