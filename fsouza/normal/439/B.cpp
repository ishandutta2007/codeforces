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
  int n, x;

  cin >> n >> x;

  lint result = 0;

  vector <int> cis(n, -1);

  for (int i = 0; i < n; i++) cin >> cis[i];
  sort(cis.begin(), cis.end());

  for (int i = 0; i < n; i++) {
    result += (lint)x * cis[i];
    x = max(x-1, 1);
  }

  cout << result << endl;

  return 0;
}