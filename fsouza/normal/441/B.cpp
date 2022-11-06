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
  int n, v;

  cin >> n >> v;

  int maxday = 3005;
  vector<int> many0(maxday, 0), many1(maxday, 0);

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    many0[a] += b;
  }

  int ret = 0;

  for (int d = 0; d < maxday; d++) {
    int get1 = min(v, many1[d]);
    ret += get1;
    many1[d] -= ret;
    int get0 = min(v - get1, many0[d]);
    ret += get0;
    many0[d] -= get0;
    many1[d+1] += many0[d];
    many0[d] = 0;
  }

  cout << ret << endl;

  return 0;
}