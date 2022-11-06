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
  vector<int> h(n);

  vector<int> res(n, 0);

  for (int i = 0; i < n; i++) cin >> h[i];

  for (int v = 100; v >= 1; v--) {
    int many = 0;
    for (int i = 0; i < n; i++) many += (h[i] >= v);
    for (int j = n-many; j < n; j++) res[j]++;
  }

  for (int i = 0; i < n; i++) {
    if (i-1 >= 0) cout << " ";
    cout << res[i];
  }
  cout << endl;

  return 0;
}