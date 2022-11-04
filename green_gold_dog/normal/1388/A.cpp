#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1000000000000000;

template<typename T>
bool assign_min(T& a, T b) {
	if (a >= b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_max(T& a, T b) {
	if (a <= b) {
		a = b;
		return true;
	}
	return false;
}

struct block {
	vector<ll> arr;
	ll sum;
	block(vector<ll> arr): arr(arr) {
		sum = 0;
		for (auto i : arr) {
			sum += i;
		}
	}
	ll get(ll l, ll r) {
		if (assign_max(l, 0ll) + assign_min(r, (ll)arr.size()) == 2) {
			return sum;
		}
		ll ans = 0;
		for (ll i = l; i < r; i++) {
			ans += arr[i];
		}
		return ans;
	}
	ll size() {
		return arr.size();
	}
};

struct sqrt_sum {
	vector<block> arr;
	ll k = 10;
	sqrt_sum(vector<ll> a) {
		vector<ll> now;
		for (ll i = 0; i < a.size(); i++) {
			now.push_back(a[i]);
			if ((i + 1) % k == 0) {
				arr.emplace_back(now);
				now.clear();
			}
		}
		if (!now.empty()) {
			arr.emplace_back(now);
		}
	}
	ll get(ll l, ll r) {
		ll ans = 0;
		for (auto& i : arr) {
			ans += i.get(l, r);
			l -= i.size();
			r -= i.size();
		}
		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll x;
		cin >> x;
		if (x <= 30) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			if (x - 30 != 6 && x - 30 != 10 && x - 30 != 14) {
				cout << 14 << ' ' << 10 << ' ' << 6 << ' ' << x - 30 << '\n';
			} else {
				cout << 15 << ' ' << 10 << ' ' << 6 << ' ' << x - 31 << '\n';
			}
		}
	}
}