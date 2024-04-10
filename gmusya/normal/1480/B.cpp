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
    ll A, B, n;
    cin >> A >> B >> n;
    vector <ll> a(n), b(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    vector <int> p(n);
    for (int i = 0; i < n; i++)
      p[i] = i;
    sort(p.begin(), p.end(), [&](int i, int j) {
      return a[i] < a[j];
    });
    int killed = 0;
    for (int id : p) {
      if (B <= 0)
        break;
      int cnt1 = (b[id] + A - 1) / A;
      int cnt2 = (B + a[id] - 1) / a[id];
      int cnt = min(cnt1, cnt2);
      b[id] -= cnt * 1ll * A;
      B -= cnt * 1ll * a[id];
      if (b[id] <= 0)
        killed++;
    }
    if (killed == n)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}