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
  string s;
  cin >> s;

  map <char, int> c;

  for (int i = 0; i < (int)s.size(); i++)
    c[s[i]]++;

  int ret = INF;

  ret = min(ret, c['e'] / 3);
  ret = min(ret, c['i'] / 1);
  ret = min(ret, c['t'] / 1);

  int maxn = 0;
  int n = c['n'];

  if (n >= 3) {
    maxn = 1 + (n-3) / 2;
  }

  ret = min(ret, maxn);

  cout << ret << endl;

  return 0;
}