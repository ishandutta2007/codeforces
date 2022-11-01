#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

const ll MOD = 998244353;

ll binp (ll a, ll p) {
  if (p == 0) return 1;
  if (p % 2) return a * binp(a, p - 1) % MOD;
  ll x = binp(a, p / 2);
  return x * x % MOD;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> cnt(1e6 + 1);
  ll sum = 0;
  vector <vector <int>> k(n);
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    k[i].resize(m);
    for (int j = 0; j < m; j++) {
      cin >> k[i][j];
      cnt[k[i][j]]++;
    }
    sum += m;
  }
  ll obrn = binp(n, MOD - 2);
  ll prob = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < k[i].size(); j++)
      prob = (prob + obrn * binp(k[i].size(), MOD - 2) % MOD * cnt[k[i][j]] % MOD * obrn) % MOD;
  cout << prob;
  return 0;
}