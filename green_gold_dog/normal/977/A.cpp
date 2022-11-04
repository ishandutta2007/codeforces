#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	for (ll _ = 0; _ < k; _++) {
	  if (n % 10 != 0) {
	    n--;
	  } else {
	    n /= 10;
	  }
	}
	cout << n;
}

/*
















*/