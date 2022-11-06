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
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

string canonize(string s) {
  if ((int)s.size()%2 == 1) return s;
  else {
    string left = canonize(s.substr(0, s.size()/2));
    string right = canonize(s.substr(s.size()/2, s.size()/2));
    if (left > right) swap(left, right);
    return left + right;
  }
}

int main() {
  string a, b;
  cin >> a >> b;
  if (canonize(a) == canonize(b)) printf("YES\n");
  else printf("NO\n");

  return 0;
}