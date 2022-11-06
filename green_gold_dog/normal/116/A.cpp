#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

template<typename T>
bool assign_max(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	ll ans = 0, now = 0;
	for (ll i = 0; i < n; i++) {
	  ll a, b;
	  cin >> a >> b;
	  now -= a;
	  now += b;
	  assign_max(ans, now);
	}
	cout << ans;
}

/*
















*/