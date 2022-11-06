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

  int ret = 1 + (n-1) + (m-1);

  cout << ret << endl;
  cout << "1 1" << endl;

  for (int j = 2; j <= m; j++)
    cout << "1 " << j << endl;
  for (int i = 2; i <= n; i++)
    cout << i << " 1" << endl;

  return 0;
}