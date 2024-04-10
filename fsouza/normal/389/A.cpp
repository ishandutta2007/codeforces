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

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b%a, a);
}

int main(int argc, char ** argv)
{
  int n;
  cin >> n;
  int g = 0;

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    g = gcd(g, v);
  }

  cout << n * g << endl;

  return 0;
}