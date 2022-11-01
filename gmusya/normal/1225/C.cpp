#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
  ll n, p;
  cin >> n >> p;
  int ans = 100;
  for (int k = 1; k <= 32; k++) {
    ll newn = n - k * p;
    if (newn < k)
      continue;
    int cnt = 0;
    while (newn) {
      cnt += newn % 2;
      newn /= 2;
    }
    if (k >= cnt) {
      cout << k;
      return 0;
    }
  }
  cout << -1;
  return 0;
}