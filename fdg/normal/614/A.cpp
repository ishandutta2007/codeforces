#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  long long l, r, k;
  cin >> l >> r >> k;
  vector<long long> v;
  long long p = 1;
  while (p <= r) {
    if (p >= l) v.push_back(p);
    if (p <= r / k + 22) p *= k;
    else break;
  }
  if (v.size() == 0) cout << -1 << endl;
  else {
    for (long long x : v) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}