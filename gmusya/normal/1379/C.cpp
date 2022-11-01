#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll k;
    int n;
    cin >> k >> n;
    vector <pair <ll, ll>> arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    vector <ll> suf(n);
    suf[n - 1] = arr[n - 1].first;
    for (int i = n - 2; i >= 0; i--)
      suf[i] = suf[i + 1] + arr[i].first;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      pair <ll, ll> tmp = {arr[i].second, 1e9 + 1};
      ll val = 0;
      int pos = upper_bound(arr.begin(), arr.end(), tmp) - arr.begin();
      if (pos == n) {
        val = max(val, arr[i].first + arr[i].second * (k - 1));
        ans = max(ans, val);
        continue;
      }
      if (pos <= i) {
        ll len = n - pos;
        if (len >= k)
          val = max(val, suf[n - k]);
        else
          val = max(val, suf[pos] + arr[i].second * (k - len));
        ans = max(ans, val);
        continue;
      }
      ll len = n - pos;
      if (len >= k)
        val = max(val, suf[n - k]);
      else
        val = max(val, suf[pos] + arr[i].first + arr[i].second * (k - len - 1));
      ans = max(ans, val);
    }
    cout << ans << '\n';
  }
  return 0;
}