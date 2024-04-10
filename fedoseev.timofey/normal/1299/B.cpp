#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <random>
#include <complex>
#include <iomanip>
#include <cassert>
 
using namespace std;

typedef long long ll;


int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  if (n % 2 == 1) {
    cout << "NO\n";
    return 0;
  }
  for (int i = 0; i + 1 < n / 2; ++i) {
    int j = i + n / 2;
    if (x[i + 1] - x[i] != -(x[j + 1] - x[j])) {
      cout << "NO\n";
      return 0;
    }
    if (y[i + 1] - y[i] != -(y[j + 1] - y[j])) {
      cout << "NO\n";
      return 0;
    }
  } 
  cout << "YES\n";
}