#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;
typedef complex<lint> point;

lint sqdist(const point &a, const point &b) { return norm(a-b); }

point read() {
  int x, y;
  cin >> x >> y;
  return point(x, y);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  point p1 = read(), p2 = read();

  set<pair<lint, int>, greater<pair<lint, int>>> d1s;
  vector<lint> sqdist2(n);

  for (int i = 0; i < n; ++i) {
    point p = read();
    d1s.insert({sqdist(p, p1), i});
    sqdist2[i] = sqdist(p, p2);
  }

  lint result = LLONG_MAX;
  lint worst2 = 0;
  for (auto &it : d1s) {
    result = min(result, it.first + worst2);
    worst2 = max(worst2, sqdist2[it.second]);
  }
  result = min(result, worst2);

  cout << result << endl;
  
  return 0;
}