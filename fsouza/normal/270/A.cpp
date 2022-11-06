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
  set<int> angs;

  for (int n = 3; n <= 360; n++) {
    int up = (n-2) * 180;
    if (up%n == 0)
      angs.insert(up / n);
  }

  int nt;

  cin >> nt;

  for (int t = 0; t < nt; t++) {
    int a;
    cin >> a;
    if (angs.find(a) == angs.end()) cout << "NO" << endl;
    else cout << "YES" << endl;
  }

  return 0;
}