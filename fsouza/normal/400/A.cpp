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
    vector <pair <int, int> > sol;
    string s;

    cin >> s;

    for (int a = 1; a <= 12; a++)
      if (12%a == 0) {
	int b = 12/a;
	bool ok = false;
	for (int i = 0; i < b; i++) {
	  bool ok2 = true;
	  for (int j = i; j < 12; j += b)
	    ok2 &= (s[j] == 'X');
	  ok |= ok2;
	}
	if (ok) sol.push_back(make_pair(a, b));
      }

    cout << sol.size();
    for (int i = 0; i < (int)sol.size(); i++) cout << " " << sol[i].first << "x" << sol[i].second;
    cout << endl;
  }

  return 0;
}