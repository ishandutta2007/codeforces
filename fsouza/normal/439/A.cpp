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

int main(int argc, char ** argv) {
  int n, d;
  int total = 0;

  cin >> n >> d;
  
  for (int i = 0; i < n; i++) {
    int ti;
    cin >> ti;
    total += ti;
  }

  if (total + (n-1) * 10 > d) cout << -1 << endl;
  else cout << (d - total)/5 << endl;

  return 0;
}