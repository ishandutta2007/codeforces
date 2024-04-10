#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  int n;
  ll p, k;
  cin >> n >> p >> k;
  vector <ll> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i] * a[i] % p;
    b[i] = b[i] * b[i] % p;
    b[i] = (b[i] - k * a[i]) % p;
    if (b[i] < 0)
      b[i] += p;
  }
  sort(b.begin(), b.end());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int r = i;
    while (r < n && b[r] == b[i])
      r++;
    r--;
    ans += (r - i) * (r - i + 1) / 2;
    i = r;
  }
  cout << ans;
  return 0;
}