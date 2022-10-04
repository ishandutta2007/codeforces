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
    string s;
    cin >> s;
    int n = s.size();
    int mn = 0;
    int cur = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '-') --cur;
      else ++cur;
      if (cur < mn) {
        int delta = mn - cur;
        ans += (ll)delta * (i + 1);
        mn = cur;
      }
    }
    cout << ans + n << '\n';
  }
}