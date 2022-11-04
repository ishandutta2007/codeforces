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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	deque<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ll a1 = 0, a2 = 0;
	for (ll i = 0; i < n; i++) {
		if (arr.front() > arr.back()) {
			if (i % 2 == 0) {
				a1 += arr.front();
				arr.pop_front();
			} else {
				a2 += arr.front();
				arr.pop_front();
			}
		} else {
			if (i % 2 == 0) {
				a1 += arr.back();
				arr.pop_back();
			} else {
				a2 += arr.back();
				arr.pop_back();
			}
		}
	}
	cout << a1 << ' ' << a2;

}
/*
















*/