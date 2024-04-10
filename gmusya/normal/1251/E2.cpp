#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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
    vector <int> m(n), p(n);
    for (int i = 0; i < n; i++)
      cin >> m[i] >> p[i];
    vector <int> per(n);
    for (int i = 0; i < n; i++)
      per[i] = i;
    sort(per.begin(), per.end(), [&](int i, int j) {
      return m[i] < m[j];
    });
    multiset <int> ms;
    ll ans = 0;
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
      int id = per[i];
      ms.insert(p[id]);
      while (cnt + i < m[id]) {
        ans += *ms.begin();
        ms.erase(ms.begin());
        cnt++;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}