// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  
  vector<int> p(N);
  for (int i = 0; i < N; ++i) {
    p[i] = __builtin_popcountll(A[i]);
  }

  debug(p);	

  vector<pair<long long, int>> mx;
  vector<pair<long long, int>> mn;
  mx.emplace_back(-1, -1);
  mn.emplace_back((long long) 1e18 + 5, -1);
  array<vector<array<int, 3>>, 62> mx_pref;
  array<vector<array<int, 3>>, 62> mn_pref;
  /*
  for (int i = 0; i < 62; ++i) {
    mx_pref[i].push_back({-1, 0, 0});
    mn_pref[i].push_back({-1, 0, 0});
  }
  */

  auto SumOne = [&](int x, auto& pref) -> int {
    debug(x, pref);
    auto it = lower_bound(pref.begin(), pref.end(), array{x + 1, -1, -1});
    int res = (it == pref.begin() ? 0 : (*prev(it))[1]);
    if (it != pref.end()) {
      res += max(0, x - (*it)[2]);
    }
    return res;
  };
   
  auto Range = [&](int l, int r, auto& pref) -> int {
    return SumOne(r, pref) - SumOne(l, pref);
  };

  long long ans = 0;
  int cur = 0;
  for (int i = 0; i < N; ++i) {
    while (mx.back().first > A[i]) {
      auto[x, ind] = mx.back();
      mx.pop_back();
      mx_pref[p[ind]].pop_back();
      cur -= Range(mx.back().second, ind, mn_pref[p[ind]]);
    }

    while (mn.back().first < A[i]) {
      auto[x, ind] = mn.back();
      mn.pop_back();
      mn_pref[p[ind]].pop_back();
      cur -= Range(mn.back().second, ind, mx_pref[p[ind]]);
    }

    debug("dec", cur);

    {
      int pre = mx.back().second;
      debug("add mx", pre, i, mn_pref[p[i]]);
      cur += Range(pre, i, mn_pref[p[i]]);
      mx.emplace_back(A[i], i);
      int prev = (mx_pref[p[i]].empty() ? 0 : mx_pref[p[i]].back()[1]);
      mx_pref[p[i]].push_back({i, prev + (i - pre), pre});
    }

    {
      int pre = mn.back().second;
      debug("add mn", pre, i, mx_pref[p[i]]);      
      cur += Range(pre, i, mx_pref[p[i]]);
      mn.emplace_back(A[i], i);
      int prev = (mn_pref[p[i]].empty() ? 0 : mn_pref[p[i]].back()[1]);
      mn_pref[p[i]].push_back({i, prev + (i - pre), pre});
    }

    debug(mx, mx_pref[p[i]]);
    debug(mn, mn_pref[p[i]]);
    debug(i, cur);
    ans += cur;
  }
  cout << ans << '\n';
}