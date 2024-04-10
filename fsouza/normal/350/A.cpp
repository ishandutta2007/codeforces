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
  int tl;
  vector<int> t(n);
  for (int i = 0; i < n; i++) cin >> t[i];
  tl = max(2*(*min_element(t.begin(), t.end())), *max_element(t.begin(), t.end()));
  bool ok = true;
  for (int i = 0; i < m; i++) {
    int t2;
    cin >> t2;
    if (t2 <= tl) ok = false;
  }

  if (!ok) cout << -1 << endl;
  else cout << tl << endl;

  return 0;
}