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
  int n = s.size();
  int p = find(s.begin(), s.end(), '^') - s.begin();

  lint val = 0;

  for (int i = 0; i < n; i++)
    if ('0'<= s[i] && s[i] <= '9') {
      int x = s[i] - '0';
      val += (lint)x * (i - p);
    }

  if (val == 0) cout << "balance" << endl;
  else if (val < 0) cout << "left" << endl;
  else cout << "right" << endl;

  return 0;
}