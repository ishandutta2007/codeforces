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

  vector<int> sizes(n);

  for (int i = 0; i < n; i++) cin >> sizes[i];

  int result = INF;

  for (int i = 0; i < n; i++) {
    int res = 0;
    for (int j = 0; j < sizes[i]; j++) {
      int nitem;
      cin >> nitem;
      res += 5 * nitem + 15;
    }
    result = min(result, res);
  }

  cout << result << endl;

  return 0;
}