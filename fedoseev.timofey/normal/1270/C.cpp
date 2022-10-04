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
    int n;
    cin >> n;
    vector <int> a(n);
    ll sum = 0, xr = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
      xr ^= a[i];
    }
    vector <ll> ans;
    ans.push_back(xr);
    sum += xr;
    ans.push_back(sum);
    cout << ans.size() << '\n';
    for (auto x : ans) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}