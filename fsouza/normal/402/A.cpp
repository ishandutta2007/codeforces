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
  int k, a, b, v;

  cin >> k >> a >> b >> v;

  int need = (a + v-1) / v;

  int nfullbox = b / (k-1);
  int next = 1 + b % (k-1);
  
  int ret = 0;
  int use;

  if (need < nfullbox * k) {
    ret = (need + k-1) / k;
  } else {
    ret = nfullbox;

    need -= nfullbox * k;
    if (need > 0) {
      ret++;
      need -= min(need, next);
      if (need > 0) {
	ret += need;
      }
    }
  }

  cout << ret << endl;

  return 0;
}