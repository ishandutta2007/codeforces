#include <bits/stdc++.h>

#define sz(x) ((int) (x).size())
typedef long long ll;
typedef long double ld;

using namespace std;

int n, s[1000100], r, cs[1000100], dpd[500100];
vector<int> e[1000100];
ll res;
bitset<500100> dp;

void solveDP() {
  int X = 100;
  dp[0] = true;
  for (int i : e[r])
    if (s[i] > X)
      dp |= dp << s[i];
    else
      cs[s[i]]++;
  for (int x = 1; x <= X; x++)
    if (cs[x] > 0) {
      for (int i = 0; i < x; i++)
        dpd[i] = dp[i] ? 0 : cs[x] + 1;
      for (int i = x; i <= (n - 1) / 2; i++)
        dpd[i] = dp[i] ? 0 : dpd[i - x] + 1, dp[i] = dpd[i] <= cs[x];
    }
  ll x = n / 2;
  while (!dp[x])
    x--;
  res += x * (n - 1 - x);
}

void dfss(int i, int p = -1) {
  s[i] = 1;
  int ms = 0;
  for (int j : e[i])
    if (j != p)
      dfss(j, i), s[i] += s[j], ms = max(ms, s[j]);
  ms = max(ms, n - s[i]);
  if (2 * ms <= n)
    r = i;
}

void dfsp(int i, int p = -1) {
  res += s[i];
  for (int j : e[i])
    if (j != p)
      dfsp(j, i);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p, p--;
    e[i].push_back(p);
    e[p].push_back(i);
  }
  dfss(0);
  dfss(r);
  dfsp(r);
  solveDP();
  cout << res << "\n";
}