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

const int N = 1e6 + 7;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  vector<int> pr(N, 1);
  pr[1] = 0;
  for (int i = 2; i < N; ++i) {
    if (pr[i]) {
      for (int j = i + i; j < N; j += i) {
        pr[j] = 0;
      }
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n, e;
    cin >> n >> e;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll ans = 0;
    for (int rem = 0; rem < e; ++rem) {
      vector<pair<int, int>> num;
      for (int i = rem; i < n; i += e) {
        int x = -1;
        if (a[i] == 1) {
          x = 1;
        } else if (pr[a[i]]) {
          x = 2;
        } else {
          x = 3;
        }
        if (num.empty() || num.back().first != x) num.push_back({x, 0});
        ++num.back().second;
      }
      for (int i = 0; i < (int)num.size(); ++i) {
        if (num[i].first != 2) continue;
        int have_left = 0;
        int have_right = 0;
        if (i > 0 && num[i - 1].first == 1) have_left = num[i - 1].second;
        if (i + 1 < (int)num.size() && num[i + 1].first == 1) have_right = num[i + 1].second;
        if (num[i].second == 1) {
          ans += (ll)(have_left + 1) * (have_right + 1);
          --ans;
        } else {
          ans += have_left;
          ans += have_right;
        }
      }
    }
    cout << ans << '\n';
  }
}