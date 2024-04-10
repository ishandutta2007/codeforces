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
  int n, q, k;
  cin >> n >> q >> k;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    cout << 2 * (a[r] - a[l] - (r - l)) + (a[l] - 1) + (k - a[r])  << '\n';
  }
}