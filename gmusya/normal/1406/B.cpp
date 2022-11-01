#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <ll> a, b, c;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x > 0)
        a.push_back(x);
      else
        b.push_back(x);
      c.push_back(x);
    }
    sort(c.begin(), c.end());
    ll ans1 = 1;
    for (int i = 0; i < 5; i++)
      ans1 *= c[i];
    ll ans2 = 1;
    sort(c.rbegin(), c.rend());
    for (int i = 0; i < 5; i++)
      ans2 *= c[i];
    ll ans = max(ans1, ans2);
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    for (int cnt = 0; cnt <= b.size() && cnt < 5; cnt += 2) {
      ll cur_p = 1;
      for (int i = 0; i < cnt; i++)
        cur_p *= b[i];
      if (a.size() + cnt < 5) continue;
      for (int i = 0; i < 5 - cnt; i++)
        cur_p *= a[i];
      ans = max(ans, cur_p);
    }
    cout << ans << '\n';
  }
  return 0;
}