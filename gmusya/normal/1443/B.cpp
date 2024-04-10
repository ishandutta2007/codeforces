#include <iostream>
#include <vector>
#include <string>

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    ll last = -1e9;
    ll ans = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] == '0')
        continue;
      ans += min(a, b * (i - last - 1));
      last = i;
    }
    cout << ans << '\n';
  }
  return 0;
}