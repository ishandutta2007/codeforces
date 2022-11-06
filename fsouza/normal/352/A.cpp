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
  int n0 = 0, n5 = 0;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    if (v == 0) n0++;
    else n5++;
  }

  if (n0 == 0) cout << -1 << endl;
  else {
    int put5 = (n5/9)*9;
    if (!put5) cout << "0" << endl;
    else {
      int put0 = n0;
      cout << string(put5, '5') + string(put0, '0') << endl;
    }
  }

  return 0;
}