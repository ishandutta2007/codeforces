#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

const ll MOD = 998244353;

int main() {
  int n;
  cin >> n;
  vector <int> deg(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    deg[u]++, deg[v]++;
  }
  vector <ll> fact(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; i++)
    fact[i] = (fact[i - 1] * i) % MOD;
  ll ans = n;
  for (int v = 0; v < n; v++)
    ans = (ans * fact[deg[v]]) % MOD;
  cout << ans;
  return 0;
}