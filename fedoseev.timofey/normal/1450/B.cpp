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
    int n, k;
    cin >> n >> k;
    vector <int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i];
    }
    int ok = 0;
    for (int i = 0; i < n; ++i) {
      int good = 1;
      for (int j = 0; j < n; ++j) {
        good &= ((abs(x[i] - x[j]) + abs(y[i] - y[j])) <= k);
      }
      ok |= good;
    }
    if (ok) cout << "1\n";
    else cout << "-1\n";
  }
}