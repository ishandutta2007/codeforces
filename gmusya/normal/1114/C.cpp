#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ll n, b;
  cin >> n >> b;
  vector <pair <int, ll>> fact;
  for (ll i = 2; i * i <= b; i++) {
    if (b % i)
      continue;
    int cnt = 0;
    while (b % i == 0) {
      b /= i;
      cnt++;
    }
    fact.push_back({cnt, i});
  }
  ll ans = 3e18;
  if (b > 1)
    fact.push_back({1, b});
  for (auto &now : fact) {
    b = now.second;
    ll sum = 0;
    ll k = b;
    while (k <= n) {
      sum += n / k;
      if (n / k < b)
        break;
      k *= b;
    }
    ans = min(ans, sum / now.first);
  }
  cout << ans;
  return 0;
}