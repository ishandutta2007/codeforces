#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

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
	ll cnt = 0;
	while (n != 0) {
	  cnt += (n % 10 == 4) || (n % 10 == 7);
	  n /= 10;
	}
	cout << ((cnt == 4 || cnt == 7) ? "YES" : "NO");
}

/*
















*/