#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, s;
    cin >> n >> s;
    ll pos = n / 2 + 1;
    ll L = 0, R = 1e9;
    while (L != R) {
      ll M = (L + R + 1) / 2;
      if (M * pos <= s) {
        L = M;
      } else {
        R = M - 1;
      }
    }
    cout << L << '\n';
  }
  return 0;
}