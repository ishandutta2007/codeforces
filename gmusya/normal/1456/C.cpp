#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector <ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.rbegin(), a.rend());
  ll c = 0;
  ll ans = 0;
  int pos = 0;
  while (pos < n && c >= 0) {
    ans += c;
    c += a[pos++];
  }
  if (pos + k >= n) {
    cout << ans;
    return 0;
  }
  vector <vector <int>> b(k + 1);
  int hehe = 1 % (k + 1);
  for (int i = pos; i < (int)a.size(); i++, hehe = (hehe + 1) % (k + 1))
    b[hehe].push_back(a[i]);
  for (auto &now : b[0]) {
    ans += c;
    c += now;
  }
  for (int i = 1; i <= k; i++) {
    c = 0;
    for (auto &now : b[i]) {
      ans += c;
      c += now;
    }
  }
  cout << ans;
  return 0;
}