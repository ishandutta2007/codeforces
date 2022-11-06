#include <algorithm>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;

lint divdown(lint a, lint b) {
  if (a >= 0) return a/b;
  else return -(-a+b-1)/b;
}

int main() {
  lint n, a, b, c;
  cin >> n >> a >> b >> c;
  lint result;
  if (a < b-c) result = n / a;
  else {
    lint delta = b-c;
    lint maxglass = max(divdown((n-b),delta)+1, 0LL);
    result = maxglass + (n - maxglass*delta) / a;
  }
  cout << result << "\n";
  
  return 0;
}