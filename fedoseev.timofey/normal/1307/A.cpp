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
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = a[0];
    for (int i = 1; i < n; ++i) {
      int dst = i;
      int cur = min(a[i], d / dst);
      ans += cur;
      d -= dst * cur;
    }
    cout << ans << '\n';
  }
}