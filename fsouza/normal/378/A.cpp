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
  int a, b;

  cin >> a >> b;

  vector<int> r(3, 0);

  for (int rr = 1; rr <= 6; rr++) {
    int da = abs(rr - a), db = abs(rr - b);
    if (da < db) r[0]++;
    else if (da == db) r[1]++;
    else r[2]++;
  }

  cout << r[0] << " " << r[1] << " " << r[2] << endl;

  return 0;
}