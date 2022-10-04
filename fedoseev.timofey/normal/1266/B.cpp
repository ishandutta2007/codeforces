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
    ll x;
    cin >> x;
    bool fl = false;
    for (int delta = 1; delta <= 6; ++delta) {
    ll nx = x + delta - 21;
    if (nx < 0 || nx % 14) continue;
      fl = true;
    }
    cout << (fl ? "YES" : "NO") << '\n';
  }
}