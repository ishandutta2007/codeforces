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
    vector<ll> a(n);
    ll cur = 1;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      while (a[i] % 2 == 0) {
        a[i] /= 2;
        cur *= 2;
      }
    }
    int id = 0;
    for (int i = 1; i < n; ++i) if (a[i] > a[id]) id = i;
    a[id] *= cur;
    ll sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];
    cout << sum << '\n';
  }
}