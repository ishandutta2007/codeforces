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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, p;
  cin >> n >> p;
  vector<string> kind(n);
  for (string &s : kind) cin >> s;

  lint many = 0;
  for (int i = n-1; i >= 0; --i) {
    many *= 2;
    if (kind[i] == string("halfplus")) ++many;
  }

  lint result = 0;
  while (many > 0) {
    result += many * p/2;
    many /= 2;
  }

  cout << result << endl;

  return 0;
}