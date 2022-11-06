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

int main(int argc, char ** argv)
{
  int x, y;
  cin >> x >> y;
  int m = abs(x) + abs(y);
  
  int x0 = 0, y0 = m;
  int x1 = m, y1 = 0;

  if (x < 0) {
    x0 *= -1;
    x1 *= -1;
  }
  if (y < 0) {
    y0 *= -1;
    y1 *= -1;
  }
  if (x0 > x1) {
    swap(x0, x1);
    swap(y0, y1);
  }

  cout << x0 << " " << y0 << " " << x1 << " " << y1 << endl;

  return 0;
}