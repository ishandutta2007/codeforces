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
  string s;
  cin >> n >> s;

  int ret = 0;
  for (int i = n-1; i+1 < (int)s.size(); i += n)
    ret += (s[i] == s[i-1] && s[i-1] == s[i-2]);

  cout << ret << endl;

  return 0;
}