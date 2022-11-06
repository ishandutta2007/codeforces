#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long lint;

int main() {
  int n;

  cin >> n;
  
  for (int i = 0; i < n; i++) {
    lint l, r;

    cin >> l >> r; r++;

    lint result = 0;

    for (int b = 62; b >= 0; b--) {
      int x = (l & (1LL<<b)) != 0;
      int y = (r & (1LL<<b)) != 0;
      if (x == y) result |= (l & (1LL<<b));
      else {
	result |= ((1LL<<b)-1);
      }
    }

    cout << result << endl;
  }

  return 0;
}