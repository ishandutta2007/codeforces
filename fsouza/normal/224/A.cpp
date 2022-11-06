#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int main() {
  int a, b, c;

  cin >> a >> b >> c;

  cout << 4 * (int)(sqrt(a*b/c) + sqrt(a*c/b) + sqrt(b*c/a)) << endl;

  return 0;
}