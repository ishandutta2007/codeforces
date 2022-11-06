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
  string a;
  int n, k;

  cin >> a >> k;
  n = a.length();

  for (int i = 0; i < n; i++) {
    for (int d = 9; d >= 0; d--) {
      int next = find(a.begin()+i, a.end(), '0'+d) - a.begin();
      if (next != n && next-i <= k) {
	for (int j = next-1; j >= i; j--) {
	  swap(a[j], a[j+1]);
	  k--;
	}
	break;
      }
    }
  }

  cout << a << endl;
  
  return 0;
}