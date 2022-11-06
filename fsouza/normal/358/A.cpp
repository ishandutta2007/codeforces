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
  vector <int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  
  bool ok = true;

  for (int i = 0; i+1 < n; i++)
    for (int j = i+2; j+1 < n; j++) {
      int a = x[i], b = x[i+1];
      if (a > b) swap(a, b);
      int c = x[j], d = x[j+1];
      if (c > d) swap(c, d);
      if (a <= c && c <= b && b <= d) ok = false;
      if (c <= a && a <= d && d <= b) ok = false;
    }

  if (!ok) cout << "yes" << endl;
  else cout << "no" << endl;

  return 0;
}