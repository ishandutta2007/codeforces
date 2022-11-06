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
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  
  int sum = 0;
  for (int i = 0; i < n; i++) sum += v[i];
  
  int delta = -INF;

  for (int i = 0; i < n; i++) {
    int s = 0;
    for (int j = i; j < n; j++) {
      s += v[j];
      delta = max(delta, ((j-i+1) - s) - s);
    }
  }
  sum += delta;

  cout << sum << endl;

  return 0;
}