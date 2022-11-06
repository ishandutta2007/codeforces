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

template<typename T>
T square(T& a) {
	return a * a;
}

ll nod(ll a, ll b) {
	if (min(a, b) == 0) {
		return max(a, b);
	}
	return nod(max(a, b) % min(a, b), min(a, b));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll a, b;
	cin >> a >> b;
	ll col = 6 - max(a, b) + 1;
	cout << col / nod(col, 6) << '/' << 6 / nod(col, 6) << '\n';
}
/*
















*/