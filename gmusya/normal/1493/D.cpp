#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 2e5;
const ll MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector <int> lp(MAXN + 1), pr;
  for (int i = 2; i <= MAXN; i++) {
    if (!lp[i]) lp[i] = i, pr.push_back(i);
    for (int j = 0; j < (int) pr.size() && pr[j] <= lp[i] && pr[j] * i <= MAXN; j++)
      lp[pr[j] * i] = pr[j];
  }
  int n, q;
  cin >> n >> q;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector <multiset <int>> vms(2e5 + 1);
  vector <map <int, int>> vmi(n);
  for (int i = 0; i < n; i++) {
    int x = a[i];
    while (x != 1) {
      vmi[i][lp[x]]++;
      x /= lp[x];
    }
    for (auto &[p, pow] : vmi[i])
      vms[p].insert(pow);
  }
  ll ans = 1;
  for (int i = 2; i <= MAXN; i++)
    if (vms[i].size() == n)
      for (int it = 0; it < *vms[i].begin(); it++)
        ans = (ans * i) % MOD;
  while (q--) {
    int i, x;
    cin >> i >> x;
    i--;
    while (x != 1) {
      int d = lp[x];
      int vhod_old = (vms[d].size() == n ? *vms[d].begin() : 0);
      if (vmi[i].find(d) != vmi[i].end())
        vms[d].erase(vms[d].find(vmi[i][d]));
      vmi[i][d]++;
      vms[d].insert(vmi[i][d]);
      int vhod_new = (vms[d].size() == n ? *vms[d].begin() : 0);
      if (vhod_old != vhod_new)
        ans = ans * lp[x] % MOD;
      x /= lp[x];
    }
    cout << ans << '\n';
  }
  return 0;
}