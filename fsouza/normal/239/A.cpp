#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
  int y, k, n;

  cin >> y >> k >> n;

  int first = y+1;
  if (first%k)
    first += k - first%k;

  for (int tot = first; tot <= n; tot += k) {
    if (tot != first) cout << " ";
    cout << tot - y;
  }
  if (first > n) cout << -1;

  cout << endl;

  return 0;
}