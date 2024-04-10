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

  cout << (n*n+1)/2 << endl;

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++)
      cout << "C."[(y+x)%2];
    cout << endl;
  }

  return 0;
}