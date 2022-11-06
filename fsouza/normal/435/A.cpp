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
  int n, m;

  cin >> n >> m;

  int result = 0;
  int current = 0;

  for (int i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    if (current+ai > m) {
      result++;
      current = 0;
    }
    current += ai;
  }

  if (current > 0) {
    result++;
    current = 0;
  }

  cout << result << endl;

  return 0;
}