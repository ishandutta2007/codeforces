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
  int nt;
  
  cin >> nt;

  for (int t = 0; t < nt; t++) {
    vector<string> field(8);
    for (int i = 0; i < 8; i++) cin >> field[i];

    vector<pair <int, int> > k;

    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
	if (field[i][j] == 'K')
	  k.push_back(make_pair(i, j));

    bool ret = false;

    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
	if (field[i][j] != '#') {
	  int par = 3;

	  for (int x = 0; x < 2; x++) {
	    int di = abs(i - k[x].first);
	    int dj = abs(j - k[x].second);
	    if (di%2 || dj%2) par = 0;
	    int a = di/2, b = dj/2;
	    par &= (1<<(a%2));
	    par &= (1<<(b%2));
	  }

	  if (par) ret = true;
	}

    if (ret) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}