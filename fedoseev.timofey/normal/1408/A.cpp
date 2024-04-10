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
    int n;
    cin >> n;
    vector <int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> c[i];
    }
    vector <int> p(n, -1);
    for (int i = 0; i < n; ++i) {
      int j = p[(i - 1 + n) % n];
      int k = p[(i + 1) % n];
      for (int x : {a[i], b[i], c[i]}) {
        if (x != j && x != k) {
          p[i] = x;
          break;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << p[i] << ' ';
    }
    cout << '\n';
  }
}