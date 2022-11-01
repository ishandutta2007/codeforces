#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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
    vector <ll> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    vector <int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j){
      return a[i] < a[j];
    });
    vector <ll> b(n), pre(n);
    for (int i = 0; i < n; i++)
      b[i] = a[p[i]];
    pre[0] = b[0];
    for (int i = 1; i < n; i++)
      pre[i] = b[i] + pre[i - 1];
    vector <int> ans;
    for (int i = 0; i < n; i++) {
      int pos = upper_bound(b.begin(), b.end(), b[i]) - b.begin() - 1;
      while (pos != n - 1) {
        int newpos = upper_bound(b.begin(), b.end(), pre[pos]) - b.begin() - 1;
        if (newpos == pos)
          break;
        pos = newpos;
      }
      if (pos == n - 1)
        ans.push_back(p[i]);
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (int id : ans)
      cout << id + 1 << ' ';
    cout << '\n';
  }
  return 0;
}