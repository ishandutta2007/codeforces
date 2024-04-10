#include <algorithm>
#include <array>
#include <bitset>
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
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  string a, b;
  cin >> a >> b;
  cout << a << " " << b << "\n";
  int nq;
  cin >> nq;
  for (int q = 0; q < nq; ++q) {
    string c, d;
    cin >> c >> d;
    if (c == a) a = d;
    else b = d;
    cout << a << " " << b << "\n";
  }

  return 0;
}