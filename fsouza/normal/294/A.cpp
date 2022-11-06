#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <set>

typedef long long lint;

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> many(n);
  for (int i = 0; i < n; i++) cin >> many[i];
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y; x--, y--;
    if (x+1 < n) many[x+1] += many[x] - y - 1;
    if (x-1 >= 0) many[x-1] += y;
    many[x] = 0;
  }
  for (int x = 0; x < n; x++) cout << many[x] << endl;

  return 0;
}