#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll p, f;
    cin >> p >> f;
    ll cnts, cntw, s, w;
    cin >> cnts >> cntw >> s >> w;
    if (s > w) {
      swap(cnts, cntw);
      swap(s, w);
    }
    ll ans = 0;
    for (int i = 0; i <= cnts; i++) {
      if (i * s > p)
        break;
      ll newcnts = i, newcntw = (p - i * s) / w;
      ll k = min(f / s, (cnts - i));
      ll m = min((f - s * k) / w, (cntw - newcntw));
      ans = max(ans, newcnts + k + newcntw + m);
    }
    cout << ans << '\n';
  }
  return 0;
}