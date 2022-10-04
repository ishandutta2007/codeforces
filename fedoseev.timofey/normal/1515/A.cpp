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
    int n, x;
    cin >> n >> x;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    auto ok = [&] () {
      int sum = 0;
      for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (sum == x) return false;
      }
      return true;
    };
    if (ok()) {
      cout << "YES\n";
      for (auto x : a) cout << x << ' ';
      cout << '\n';
    } else {
      int sum = 0;
      for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (sum == x) {
          if (i + 1 < n) {
            swap(a[i], a[i + 1]);
            break;
          }
        }
      }
      if (ok()) {
        cout << "YES\n";
        for (auto x : a) cout << x << ' ';
        cout << '\n';
      } else {
        cout << "NO\n";
      }
    }
  }
}