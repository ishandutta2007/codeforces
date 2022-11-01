#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    vector <int> c1, c2;
    for (int i = 0; i < n; i++) {
      if (b[i] == 1)
        c1.push_back(a[i]);
      else
        c2.push_back(a[i]);
    }
    sort(c1.rbegin(), c1.rend());
    sort(c2.rbegin(), c2.rend());
    vector <ll> pref1(c1.size() + 1), pref2(c2.size() + 1);
    for (int i = 0; i < (int) c1.size(); i++)
      pref1[i + 1] = pref1[i] + c1[i];
    for (int i = 0; i < (int) c2.size(); i++)
      pref2[i + 1] = pref2[i] + c2[i];
    int ans = INF;
    for (int i = 0; i < (int) pref1.size(); i++) {
      int pos = lower_bound(pref2.begin(), pref2.end(), m - pref1[i]) - pref2.begin();
      if (pos == (int) pref2.size())
        continue;
      ans = min(ans, i + 2 * pos);
    }
    if (ans == INF)
      ans = -1;
    cout << ans << '\n';
  }
  return 0;
}