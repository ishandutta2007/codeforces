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

  bool ok = true;
  map <int, int> many;

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    int m = (++many[v]);
    if (m > (n+1)/2) ok = false;
  }

  cout << (ok ? "YES" : "NO") << endl;

  return 0;
}