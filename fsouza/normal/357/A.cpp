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
  int m;
  cin >> m;
  vector<int> cnt(m);
  for (int i = 0; i < m; i++) cin >> cnt[i];
  int x, y;
  cin >> x >> y;

  int sum = accumulate(cnt.begin(), cnt.end(), 0);

  int g1 = sum, g2 = 0;
  for (int i = 0; i < m; i++) {
    g1 -= cnt[i];
    g2 += cnt[i];
    if (x <= min(g1, g2) && max(g1, g2) <= y) {
      cout << i+2 << endl;
      return 0;
    }
  }

  cout << 0 << endl;

  return 0;
}