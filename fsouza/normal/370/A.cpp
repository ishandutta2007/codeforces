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
  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;

  cout << (r1 != r2) + (c1 != c2) << " ";
  int b = 0;
  if ((r1+c1)%2 == (r2+c2)%2)
    b = ((r1+c1) != (r2+c2)) + ((r1-c1) != (r2-c2));
  cout << b << " ";
  cout << max(abs(r1-r2), abs(c1-c2)) << endl;

  return 0;
}