// author: erray
#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
  #include "/home/eagle/debug.h"
#else
  #define debug(...) void(37)
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(1 << N);
  for (int i = 0; i < (1 << N); ++i) {
    cin >> A[i];
  } 
  function<vector<array<long long, 4>>(int, int)> Solve = [&](int ll, int rr) {
    if (ll + 1 == rr) {
      array<long long, 4> r = {};
      r[0] = A[ll];
      if (A[ll] > 0) {
        r[1] = r[2] = r[3] = A[ll];
      }
      return vector{r};
    }
    int mid = (ll + rr) >> 1;
    auto a = array{Solve(ll, mid), Solve(mid, rr)};
    int s = int(a[0].size());
    vector<array<long long, 4>> res(s * 2);
    for (int i = 0; i < s; ++i) {
      for (int j = 0; j < 2; ++j) {
        int n = s * j + i;
        auto& l = a[j][i];
        auto& r = a[j ^ 1][i];
        auto& m = res[n];
        m[0] = l[0] + r[0];
        m[1] = max({l[1], r[1], l[3] + r[2]});
        m[2] = max(l[2], l[0] + r[2]);
        m[3] = max(r[3], r[0] + l[3]);
      }
    }
    return res;
  };
  auto ans = Solve(0, 1 << N);
  int mask = 0;
  int Q;
  cin >> Q;
  while (Q--) {
    int X;
    cin >> X;
    mask ^= 1 << X;
    cout << ans[mask][1] << '\n';
  }
}