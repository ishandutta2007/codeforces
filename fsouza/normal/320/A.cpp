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
  bool ok = true;
  if (s[0] == '4') ok = false;
  int n4 = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == '1') n4 = 0;
    else if (s[i] == '4') {
      n4++;
      if (n4 > 2) ok = false;
    } else
      ok = false;
  }

  if (ok) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}