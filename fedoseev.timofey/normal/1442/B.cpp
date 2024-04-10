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

const int md = 998244353;

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
    vector <int> b(k);    
    vector <int> id(n + 1, -1);
    for (int i = 0; i < k; ++i) {
      cin >> b[i];
      id[b[i]] = i;
    }
    int ans = 1;
    for (int i = 0; i < n; ++i) {
      if (id[a[i]] != -1) {
        int cnt = 0;
        int good = 0;
        for (int d : {-1, 1}) {
          if (0 <= i + d && i + d < n) {
            if (id[a[i + d]] < id[a[i]]) {
              ++good;
            } 
          }
        }
        ans *= good;
        ans %= md;
      }
    }
    cout << ans << '\n';
  }
}