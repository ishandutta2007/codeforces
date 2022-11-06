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
  int ret = 0;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    bool ok[10];
    for (int j = 0; j < 10; j++) ok[j] = false;
    for (int j = 0; j < (int)s.size(); j++)
      ok[s[j]-'0'] = true;
    bool ok2 = true;
    for (int j = 0; j <= k; j++) ok2 &= ok[j];
    ret += ok2;
  }

  cout << ret << endl;

  return 0;
}