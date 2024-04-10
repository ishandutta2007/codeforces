#include <iostream>
#include <vector>

using namespace std;

int main () {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    if (k > n) {
      ans += k - n;
      n = k;
    }
    if ((n + k) % 2) ans++;
    cout << ans << '\n';
  }
  return 0;
}