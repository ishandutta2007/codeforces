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

bool is_sq(int x) {
  ll l = 1, r = 1e9;
  while (r - l > 1) {
    ll m = (l + r) / 2;
    if (m * m <= x) l = m;
    else r = m;
  }
  return l * l == x;
}
 
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
    if (n % 2 == 0 && is_sq(n / 2)) {
      cout << "YES\n";
    } else if (n % 4 == 0 && is_sq(n / 4)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}