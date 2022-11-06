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
  int n, m;

  cin >> n >> m;

  bool side = false;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int v;
      cin >> v;
      if (v && (i == 0 || i == n-1 || j == 0 || j == m-1)) side = true;
    }

  cout << (side ? 2 : 4) << endl;

  return 0;
}