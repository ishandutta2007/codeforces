#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
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
  int m, n;

  cin >> m >> n;

  double ret = 0.0;

  double last = 0.0;
  for (int ma = 1; ma <= m; ma++) {
    double now = pow(1.0*ma/m, n);

    ret += (now - last) * ma;
    
    last = now;
  }

  cout << setprecision(12) << ret << endl;

  return 0;
}