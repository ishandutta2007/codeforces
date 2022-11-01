#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll l, r;
    cin >> l >> r;
    for (int i = 0; i < 62; i++) {
      if (l & (1ll << i))
        continue;
      if ((l ^ (1ll << i)) <= r)
        l += (1ll << i);
    }
    cout << l << '\n';
  }
  return 0;
}