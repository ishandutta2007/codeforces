#include<bits/stdc++.h>
 
using namespace std;

template<class Fun>
class yRes {
  Fun fun_;
  public:
  template<class T>
  explicit yRes(T &&fun): fun_(std::forward<T>(fun)) {}

  template<class ...Args>
  decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template<class Fun>
decltype(auto) yRec(Fun &&fun) {
  return yRes<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
 
int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(z + 1, vector<long long>(2, -1)));
    auto DP = yRec([&](auto DP, int ind, int left, bool last) -> long long {
      if (ind + (z - left) * 2 == k) return 0ll;
      if (dp[ind][left][last] != -1) return dp[ind][left][last];
      auto& p = dp[ind][left][last];
      p = DP(ind + 1, left, false) + a[ind + 1];
      if (!last && ind && left) p = max(p, DP(ind - 1, left - 1, true) + a[ind - 1]);
      return p;
    });
    cout << DP(0, z, false) + a.front() << '\n';
  }
}