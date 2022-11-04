#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll a, b;
	cin >> a >> b;
	ll ans = 0;
	while (a <= b) {
	  a *= 3;
	  b *= 2;
	  ans++;
	}
	cout << ans;
}

/*
















*/