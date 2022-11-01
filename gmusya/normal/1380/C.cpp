#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ll x;
    cin >> x;
    vector <ll> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a.rbegin(), a.rend());
    int cnt = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
      cur++;
      if (cur * 1ll * a[i] >= x) {
        cur = 0;
        cnt++;
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}