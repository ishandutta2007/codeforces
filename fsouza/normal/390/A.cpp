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

  set<int> x, y;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    x.insert(a);
    y.insert(b);
  }

  int ret = min(x.size(), y.size());

  cout << ret << endl;

  return 0;
}