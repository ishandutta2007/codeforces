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
  int n, d;
  cin >> n >> d;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int m;
  cin >> m;
  sort(v.begin(), v.end());

  int ret = 0;

  if (m <= (int)v.size()) ret = accumulate(v.begin(), v.begin() + m, 0);
  else ret = accumulate(v.begin(), v.end(), 0) - d * (m - (int)v.size());

  cout << ret << endl;

  return 0;
}