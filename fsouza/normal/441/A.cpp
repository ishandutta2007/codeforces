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

  vector<int> ret;

  for (int i = 0; i < n; i++) {
    bool ok = false;
    int ki;
    cin >> ki;

    for (int j = 0; j < ki; j++) {
      int cost;
      cin >> cost;
      if (cost < v) ok = true;
    }

    if (ok) ret.push_back(i);
  }

  cout << ret.size() << endl;
  for (int k = 0; k < (int)ret.size(); k++) {
    if (k-1 >= 0) cout << " ";
    cout << ret[k] + 1;
  }
  cout << endl;

  return 0;
}