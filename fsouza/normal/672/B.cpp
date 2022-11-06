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
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n > 26) cout << "-1\n";
  else {
    sort(s.begin(), s.end());
    int ndiff = unique(s.begin(), s.end()) - s.begin();
    cout << n - ndiff << "\n";
  }

  return 0;
}