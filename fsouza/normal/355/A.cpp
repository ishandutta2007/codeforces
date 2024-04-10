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
  int k, d;

  cin >> k >> d;

  if (d == 0 && k != 1) cout << "No solution" << endl;
  else cout << string(1, '0'+d) + string(k-1, '0') << endl;

  return 0;
}