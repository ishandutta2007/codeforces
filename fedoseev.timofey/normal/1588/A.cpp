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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    bool bad = false;
    while (!a.empty()) {
      if (a[0] == b[0]) {
        a.erase(a.begin());
        b.erase(b.begin());
      } else {
        auto it = find(b.begin(), b.end(), *a.begin() + 1);
        if (it != b.end()) {
          a.erase(a.begin());
          b.erase(it);
        } else {
          bad = true;
          break;
        }
      }
    }
    cout << (!bad ? "YES" : "NO") << '\n';
  }
}