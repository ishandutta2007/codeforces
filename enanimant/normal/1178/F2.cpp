// July 20, 2019
// https://codeforces.com/contest/1178/problem/F

/*

*/


#include <bits/stdc++.h>;

using namespace std;


const int MOD = 998244353;
const int MAXN = 502;


int N, M;
vector<int> c;
vector<int> occ[MAXN];
vector< vector<long long> > dp;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> N >> M;
  c.push_back(-1);
  while (M--) {
    int x;
    cin >> x;
    x--;
    if (c.empty() || x != c.back()) {
      occ[x].push_back(c.size());
      c.push_back(x);
    }
  }
  M = c.size() - 1;
  if (M > 2 * N) {
    cout << "0\n";
    return 0; // keep time/memory complexity low
  }
  dp.resize(M + 2, vector<long long>(M + 2, 0));
  for (int l = 1; l <= M + 1; l++) {
    for (int r = 0; r < l; r++) {
      dp[l][r] = 1;
    }
    if (l <= M && occ[c[l]].size() == 1) {
      dp[l][l] = 1;
    }
  }
  for (int sz = 2; sz <= M; sz++) {
    for (int l = 1; l + sz - 1 <= M; l++) {
      int r = l + sz - 1;
      int lm = l, rm = l;
      for (int i = l; i <= r; i++) {
        if (c[i] < c[lm]) {
          lm = rm = i;
        } else if (c[i] == c[lm]) {
          rm = i;
        }
      }
      const auto &occs = occ[c[lm]];
      if (occs[0] != lm || occs.back() != rm) {
        dp[l][r] = 0;
        continue;
      }
      long long left = 0;
      for (int a = l; a <= lm; a++) {
        // colour [a, b] with colour c[m]
        left += dp[l][a - 1] * dp[a][lm - 1] % MOD;
        left %= MOD;
      }
      long long right = 0;
      for (int b = rm; b <= r; b++) {
        right += 1LL * dp[rm + 1][b] * dp[b + 1][r] % MOD;
        right %= MOD;
      }
      dp[l][r] = left * right % MOD;
      for (int i = 0; i < occs.size() - 1; i++) {
        dp[l][r] *= dp[occs[i] + 1][occs[i + 1] - 1];
        dp[l][r] %= MOD;
      }
    }
  }
  cout << dp[1][M] << '\n';


  return 0;
}