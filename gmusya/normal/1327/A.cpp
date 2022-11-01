#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    if ((n + k) % 2) {
      cout << "NO\n";
      continue;
    }
    if (k * k > n)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}