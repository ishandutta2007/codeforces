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
  int n, k;
  
  cin >> n >> k;

  int good = 0;

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    if (v + k <= 5) good++;
  }

  cout << good / 3 << endl;

  return 0;
}