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
  const int C = 1e5 + 7;
  vector <vector <int>> pr(C);
  for (int i = 2; i < C; ++i) {
    if (pr[i].empty()) {
      for (int j = i; j < C; j += i) {
        pr[j].push_back(i);
      }
    }
  }
  int n, q;
  cin >> n >> q;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  const int K = 20;
  vector <vector <int>> go(K, vector <int> (n + 1, n));
  int r = n;
  vector <int> where(C, n);
  for (int l = n - 1; l >= 0; --l) {
    for (auto p : pr[a[l]]) {
      r = min(r, where[p]);
    }
    for (auto p : pr[a[l]]) {
      where[p] = l;
    }
    go[0][l] = r;
  }
  for (int i = 1; i < K; ++i) {
    for (int j = 0; j <= n; ++j) {
      go[i][j] = go[i - 1][go[i - 1][j]];
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    int ans = 0;
    for (int i = K - 1; i >= 0; --i) {
      if (go[i][l] <= r) {
        ans += (1 << i);
        l = go[i][l];
      }
    }
    ++ans;
    cout << ans << '\n';
  }
}