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
  int n, k, p;

  cin >> n >> k >> p;
  int o = k-p;

  vector <vector<int> > ret(k, vector<int>());

  int laste = k;
  int nexto = 0;
  bool another = false;

  for (int i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    if (ai%2) {
      ret[nexto%k].push_back(ai);
      if (nexto < o) {
	nexto++;
      } else {
	if (another) {
	  nexto++;
	  another = false;
	} else {
	  another = true;
	}
      }
    } else {
      ret[--laste].push_back(ai);
      if (laste == 0) laste += k;
    }
  }

  bool ok = true;
  if (another || nexto < o) ok = false;
  for (int i = 0; i < k; i++) if (ret[i].empty()) ok = false;

  if (ok) {
    cout << "YES" << endl;
    for (int i = 0; i < k; i++) {
      cout << ret[i].size();
      for (int j = 0; j < (int)ret[i].size(); j++) cout << " " << ret[i][j];
      cout << endl;
    }
  } else {
    cout << "NO" << endl;
  }
  
  return 0;
}