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

  vector<int> ans(n, -1);
  int first = n;

  for (int i = 0; i < m; i++) {
    int bi;
    cin >> bi;
    bi--;
    for (int j = bi; j < first; j++) ans[j] = bi;
    first = min(bi, first);
  }
  
  for (int i = 0; i < n; i++) {
    if (i-1 >= 0) cout << " ";
    cout << ans[i] + 1;
  }
  cout << endl;

  return 0;
}