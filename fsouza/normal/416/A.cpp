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
  int mi = -INF, ma = INF;
  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    string op;
    int v;
    string ret;
    cin >> op >> v >> ret;
    if (op == ">") {
      op = ">=";
      v++;
    }
    if (op == "<") {
      op = "<=";
      v--;
    }
    if (ret == "N") {
      if (op == "<=") {
	op = ">=";
	v++;
      } else {
	op = "<=";
	v--;
      }
      ret = "Y";
    }
    if (op == "<=") ma = min(ma, v);
    if (op == ">=") mi = max(mi, v);
  }

  if (mi > ma) cout << "Impossible" << endl;
  else cout << mi << endl;
  
  return 0;
}