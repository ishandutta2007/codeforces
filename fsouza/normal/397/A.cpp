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

  vector<int> ok(100, 0);

  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    for (int j = l; j < r; j++)
      if (i == 0) ok[j] = 1;
      else ok[j] = 0;
  }

  cout << accumulate(ok.begin(), ok.end(), 0) << endl;

  return 0;
}