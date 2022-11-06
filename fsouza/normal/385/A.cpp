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
  int n, c;
  
  cin >> n >> c;
  vector<int> cost(n, 0);

  for (int i = 0; i < n; i++) cin >> cost[i];
  
  int ret = 0;

  for (int i = 0; i+1 < n; i++) {
    ret = max(ret, cost[i] - cost[i+1] - c);
  }

  cout << ret << endl;

  return 0;
}