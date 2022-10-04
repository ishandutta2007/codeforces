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
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int sum = 0;
    for (int i = 0; i + 1 < n; ++i) {
      int tk = min(a[i], k - sum);
      a[i] -= tk;
      sum += tk;
    }
    a[n - 1] += sum;
    for (int i = 0; i < n; ++i) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }
}