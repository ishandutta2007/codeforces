#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (ll i = 0; i < 5; i++) {
	  for (ll j = 0; j < 5; j++) {
	    ll a;
	    cin >> a;
	    if (a == 1) {
	      cout << abs(i - 2) + abs(j - 2);
	    }
	  }
	}
}

/*
















*/