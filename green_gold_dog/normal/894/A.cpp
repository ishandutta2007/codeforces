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

bool is_sorted(vector<ll>& arr) {
	for (ll i = 1; i < arr.size(); i++) {
		if (arr[i] < arr[i - 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	ll q1 = 0, a = 0, q2 = 0;
	for (auto i : s) {
		if (i == 'Q') {
			q1++;
			q2 += a;
		}
		if (i == 'A') {
			a += q1;
		}
	}
	cout << q2;
}
/*
















*/