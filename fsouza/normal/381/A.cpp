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
  vector<int> l(n);
  for (int i = 0; i < n; i++) cin >> l[i];

  int a = 0, b = n-1;

  int ret[2] = {0, 0};

  for (int i = 0; i < n; i++) {
    ret[i%2] += max(l[a], l[b]);
    if (l[a] > l[b]) a++;
    else b--;
  }

  cout << ret[0] << " " << ret[1] << endl;

  return 0;
}