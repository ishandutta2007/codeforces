#include <cmath>
#include <cstring>

#include <algorithm>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

using ull = unsigned long long;
using ll = long long;

const int P = 1000000007;

int norm(int x) {
  return x >= P ? x - P : x;
}
void add(int& a, int b) {
  if ((a += b) >= P) {
    a -= P;
  }
}
void sub(int& a, int b) {
  if ((a -= b) < 0) {
    a += P;
  }
}
void fam(int& a, int b, int c) {
  a = (a + b * (ull)c) % P;
}
int mpow(int a, int k) {
  if (k == 0) {
    return 1;
  }
  int ret = mpow(a * (ull)a % P, k >> 1);
  if (k & 1) {
    ret = ret * (ull)a % P;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    vector<vector<int>> ch(n);
    for (int i = 1; i != n; ++i) {
      int p; cin >> p; --p;
      ch[p].push_back(i);
    }
    vector<ll> L(n), R(n);
    for (int i = 0; i != n; ++i) cin >> L[i] >> R[i];
    int ans = 0;
    function<ll(int)> dfs = [&](int u) {
      ll r = 0;
      for (int v : ch[u]) {
        r += dfs(v);
      }
      if (r >= L[u]) {
        return min(r, R[u]);
      }
      ++ans; return R[u];
    };
    dfs(0);
    cout << ans << '\n';
  }

  return 0;
}