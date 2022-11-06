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
  cin >> n;
  cin >> s;
  int ret = 1;

  for (int i = 1; i < n; i++) {
    string s2;
    cin >> s2;
    if (s2[0] == s[1]) ret++;
    s = s2;
  }

  cout << ret << endl;

  return 0;
}