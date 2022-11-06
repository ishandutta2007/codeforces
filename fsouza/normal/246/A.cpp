#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>

typedef long long lint;

using namespace std;

int main() {
  int n;

  cin >> n;
  
  if (n <= 2) cout << -1 << endl;
  else {
    cout << n-1 << " " << n;
    for (int v = 1; v < n-1; v++)
      cout << " " << v;
    cout << endl;
  }

  return 0;
}