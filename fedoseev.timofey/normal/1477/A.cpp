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

ll gcd(ll a, ll b) {
  return (b == 0 ? a : gcd(b, a % b));
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n; ll k;
    cin >> n >> k;
    vector <ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    k -= a[0];
    ll g = 0;
    for (int i = 0; i + 1 < n; ++i) g = gcd(g, a[i + 1] - a[i]);
    if (k % g == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}