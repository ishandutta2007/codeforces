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
  int nfilter, need, have;

  cin >> nfilter >> need >> have;

  vector<int> filter(nfilter);

  for (int i = 0; i < nfilter; i++)
    cin >> filter[i];

  sort(filter.rbegin(), filter.rend());

  int nuse = 0;

  for (int i = 0; i < nfilter; i++) {
    if (have < need && filter[i] > 1 && have >= 1) {
      have += filter[i] - 1;
      nuse++;
    }
  }

  if (have >= need) cout << nuse << endl;
  else cout << -1 << endl;

  return 0;
}