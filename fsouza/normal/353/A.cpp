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
  int n;
  cin >> n;

  int sum0 = 0, sum1 = 0;
  int sum = 0;
  bool canswap = false;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    sum0 += x;
    sum1 += y;
    if ((x%2) != (y%2))
      canswap = true;
    sum += x + y;
  }

  if ((sum%2) || (!canswap && (sum0%2 || sum1%2))) cout << -1 << endl;
  else if ((sum0%2 || sum1%2)) cout << 1 << endl;
  else cout << 0 << endl;

  return 0;
}