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
  vector<int> v(m);
  for (int i = 0; i < m; i++) cin >> v[i];
  sort(v.begin(), v.end());

  int ret = INF;
  for (int i = 0; i+n-1 < m; i++)
    ret = min(ret, v[i+n-1] - v[i]);

  cout << ret << endl;

  return 0;
}