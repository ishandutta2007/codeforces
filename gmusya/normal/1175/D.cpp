#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector <ll> a(n);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ans += a[i];
  }
  vector <ll> suf(n);
  suf[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--)
    suf[i] = suf[i + 1] + a[i];
  suf[0] = -1e18;
  sort(suf.rbegin(), suf.rend());
  for (int i = 0; i + 1 < k; i++)
    ans += suf[i];
  cout << ans;
  return 0;
}