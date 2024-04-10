#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, d, m, l;
  cin >> n >> d >> m >> l;
  ll pos = 0;
  int cnt = 0;
  while (true) {
    ll platform = pos / m;
    if (platform >= n)
      break;
    if (pos % m > l)
      break;
    ll r = platform * m + l;
    pos += (r - pos) / d * d;
    pos += d;
    cnt++;
  }
  cout << pos;
  return 0;
}