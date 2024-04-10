// July 16, 2019
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int MOD = 998244353;
const int MAXN = 100000;


long long pow10[30];
int N;
vector<int> v[MAXN];
int len[11]; // 10^9 has 10 digits

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  pow10[0] = 1;
  for (int i = 1; i < 30; i++) {
    pow10[i] = pow10[i - 1] * 10 % MOD;
  }

  cin >> N;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a; // a >= 1
    while (a > 0) {
      v[i].push_back(a % 10);
      a /= 10;
    }
    len[v[i].size()]++;
  }
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      for (int k = 1; k <= 10; k++) {
        // other num has length k
        int p = j + min(j + 1, k);
        ans += 1LL * v[i][j] * pow10[p] * len[k] % MOD;
        ans %= MOD;
        p = j + min(j, k);
        ans += 1LL * v[i][j] * pow10[p] * len[k] % MOD;
        ans %= MOD;
        // overcounted f(i, i)
        // lol nvm, didn't overcount
      }
    }
  }
  cout << ans << '\n';


  return 0;
}