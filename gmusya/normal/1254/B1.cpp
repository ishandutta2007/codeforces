#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <ll> a(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum == 1) {
    cout << -1;
    return 0;
  }
  vector <ll> d;
  ll MAXN = 1e6;
  vector <ll> lp(MAXN + 1), pr;
  for (int i = 2; i <= MAXN; i++) {
    if (!lp[i]) lp[i] = i, pr.push_back(i);
    for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && pr[j] * i <= MAXN; j++)
      lp[pr[j] * i] = pr[j];
  }
  for (ll p : pr) {
    if (sum % p)
      continue;
    d.push_back(p);
    while (sum % p == 0) {
      sum /= p;
      continue;
    }
  }
  if (sum > 1)
    d.push_back(sum);
  ll ans = 1e18;
  for (ll del : d) {
    ll cursum = 0;
    ll curans = 0;
    for (int i = 0; i < n; i++) {
      cursum += a[i];
      curans += min(cursum % del, del - (cursum % del));
    }
    ans = min(ans, curans);
  }
  cout << ans;
  return 0;
}