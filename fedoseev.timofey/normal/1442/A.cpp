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
    vector <int> a(n);
    for (int &x : a) cin >> x;
    int f = a[0], s = 0;
    bool bad = false;
    for (int i = 1; i < n; ++i) {
      if (f + s > a[i]) {
        f -= (f + s - a[i]);
        if (f < 0) {
          bad = true;
        }
      } else if (f + s < a[i]) {
        s += a[i] - (f + s);
      }
    }
    if (!bad) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}