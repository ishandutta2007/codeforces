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
  
  cin >> n;

  vector<string> field(n);

  for (int i = 0; i < n; i++) cin >> field[i];

  vector<char> chars[2];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      bool diag = (i == j || i == (n-1-j));
      char c = field[i][j];
      chars[diag].push_back(c);
    }

  bool bla[2];

  for (int k = 0; k < 2; k++) {
    sort(chars[k].begin(), chars[k].end());
    bla[k] = (chars[k].front() == chars[k].back());
  }
  bool hey = chars[0].front() == chars[1].front();

  cout << ((bla[0] && bla[1] && !hey) ? "YES" : "NO") << endl;

  return 0;
}