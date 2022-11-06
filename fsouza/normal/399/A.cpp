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

string conv(int i) {
  static char bla[128];
  snprintf(bla, 128, "%d", i);
  return string(bla);
}

int main(int argc, char ** argv)
{
  int n, p, k;

  cin >> n >> p >> k;

  vector<string> nav;

  if (p-k > 1) nav.push_back("<<");
  for (int i = p-k; i <= p+k; i++) {
    if (i == p) nav.push_back(string("(") + conv(i) + ")");
    else if (1 <= i && i <= n) nav.push_back(string("") + conv(i));
  }
  if (p+k < n) nav.push_back(">>");

  cout << nav[0];
  for (int i = 1; i < (int)nav.size(); i++) cout << " " << nav[i];
  cout << endl;

  return 0;
}