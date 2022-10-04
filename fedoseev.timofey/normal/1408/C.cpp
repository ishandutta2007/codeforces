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
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n, l;
    cin >> n >> l;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    double L = 0, R = 2e9;
    for (int it = 0; it < 200; ++it) {
      double M = (L + R) / 2;
      double x1 = 0;
      double v = 1;
      double rem = M;
      for (int i = 0; i < n; ++i) {
        double need = a[i] - x1; 
        double t = need / v;
        if (rem >= t) {
          rem -= t;
          x1 = a[i];
          ++v;
        } else {
          x1 += rem * v;
          rem = 0;
          break;
        }
      }
      x1 += v * rem;
      double x2 = l;
      v = 1;
      rem = M;
      for (int i = n - 1; i >= 0; --i) {
        double need = x2 - a[i];
        double t = need / v;
        if (rem >= t) {
          rem -= t;
          x2 = a[i];
          ++v;
        } else {
          x2 -= rem * v;
          rem = 0;
          break;
        }
      }
      x2 -= v * rem;
      if (x1 >= x2) R = M;
      else L = M;
    }
    cout << fixed << setprecision(20) << R << '\n';
  }
}