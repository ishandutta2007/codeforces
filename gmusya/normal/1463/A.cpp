#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll a, b, c;
    cin >> a >> b >> c;
    ll cnt = (a + b + c);
    if (cnt % 9) {
      cout << "NO\n";
      continue;
    }
    cnt /= 9;
    if (a < cnt || b < cnt || c < cnt)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}