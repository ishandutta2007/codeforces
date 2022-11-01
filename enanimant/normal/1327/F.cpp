// March 23, 2020
// https://codeforces.com/contest/1327/problem/F

/*

*/


#include <bits/stdc++.h>

using namespace std;


constexpr int MOD = 998244353;
constexpr int N = 500005;
constexpr int K = 30;

vector<tuple<int, int, int>> conds;
vector<pair<int, int>> cond[N];
long long dp[N];
long long psa[N];

int get_sum(int ll, int rr) {
  long long res = 0;
  if (ll == -1) {
    res++;
    ll = 0;
  }
  res += psa[rr + 1] - psa[ll];
  res %= MOD;
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n, k, m;
  cin >> n >> k >> m;
  for (int i = 0; i < m; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    l--;
    r--;
    cond[r].emplace_back(l, x);
    conds.emplace_back(l, r, x);
  }
  long long ans = 1;
  for (int b = 0; b < k; b++) {
    // cerr << "solving bit " << b << '\n';
    vector<pair<int, int>> ones;
    for (const auto &t : conds) {
      int l, r, x;
      tie(l, r, x) = t;
      if (x & (1 << b)) {
        ones.emplace_back(l, r);
      }
    }
    sort(ones.begin(), ones.end());
    vector<pair<int, int>> oness;
    for (int i = 0; i < (int) ones.size(); i++) {
      if (i == 0 || ones[i].first > oness.back().second) {
        oness.emplace_back(ones[i]);
      } else {
        oness.back().second = max(oness.back().second, ones[i].second);
      }
    }
    vector<bool> is1(n, false);
    for (const auto &p : oness) {
      for (int i = p.first; i <= p.second; i++) {
        is1[i] = true;
      }
    }
    psa[0] = 0;
    int r = -1;
    // cerr << "dp: ";
    for (int i = 0; i < n; i++) {
      if (is1[i]) {
        dp[i] = 0;
      } else {
        dp[i] = get_sum(r, i - 1);
      }
      psa[i + 1] = (psa[i] + dp[i]) % MOD;
      for (const auto &p : cond[i]) {
        if (!(p.second & (1 << b))) {
          r = max(r, p.first);
        }
      }
    }
    ans *= get_sum(r, n - 1);
    ans %= MOD;
  }
  if (ans < 0) {
    ans += MOD;
  }
  cout << ans << '\n';


  return 0;
}