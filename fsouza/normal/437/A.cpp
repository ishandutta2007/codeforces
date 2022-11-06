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
  vector <string> s(4);
  for (int i = 0; i < 4; i++) cin >> s[i];

  vector <string> good;
  for (int i = 0; i < 4; i++) {
    int li = s[i].size()-2;
    bool big = true;
    bool small = true;

    for (int j = 0; j < 4; j++) {
      int lj = s[j].size()-2;
      if (i != j) {
	big &= (li >= 2*lj);
	small &= (lj >= 2*li);
      }
    }

    if (big || small) good.push_back(s[i]);
  }

  if (good.size() == 1) cout << good.front()[0] << endl;
  else cout << "C" << endl;

  return 0;
}