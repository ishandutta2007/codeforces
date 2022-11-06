#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)

typedef long long lint;

using namespace std;

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b%a, a);
}

int main(int argc, char ** argv)
{
  int x, y, a, b;
  cin >> x >> y >> a >> b;
  int m = x/gcd(x,y) * y;

  cout << b/m - (a-1)/m << endl;

  return 0;
}