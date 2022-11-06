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
  for (int p = 0; p < 4; p++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (min(a,b) + min(c,d) <= n) {
      cout << p+1 << " " << min(a,b) << " " << n-min(a,b) << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}