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

  int delta = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'X') delta++;
    else delta--;
  }

  int ret = 0;

  for (int i = 0; i < n; i++)
    if (delta < 0 && s[i] == 'x') {
      s[i] = 'X';
      delta += 2;
      ret++;
    } else if (delta > 0 && s[i] == 'X') {
      s[i] = 'x';
      delta -= 2;
      ret++;
    }
    
  cout << ret << endl << s << endl;

  return 0;
}