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
  int n, m, k;
  cin >> n >> m >> k;
  int ret = 0;

  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      if (m > 0)
	m--;
      else ret++;
    } else {
      if (k > 0)
	k--;
      else if (m > 0)
	m--;
      else
	ret++;
    }
  }

  cout << ret << endl;

  return 0;
}