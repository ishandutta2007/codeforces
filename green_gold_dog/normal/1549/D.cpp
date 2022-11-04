#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll gcd(ll a, ll b) {
	if (min(a, b) == 0) {
		return max(a, b);
	}
	return gcd(max(a, b)%min(a, b), min(a, b));
}

struct nstack {
	stack<ll> s1, s2;
	nstack() {
		s2.push(0);
	}
	void push(ll x) {
		s2.push(gcd(s2.top(), x));
		s1.push(x);
	}
	void pop() {
		s1.pop();
		s2.pop();
	}
	ll get() {
		return s2.top();
	}
	ll top() {
		return s1.top();
	}
	ll size() {
		return s1.size();
	}
};

struct nqueue {
	nstack s1, s2;
	nqueue() {
	}
	void push(ll x) {
		s1.push(x);
	}
	void pop() {
		if (s2.size() == 0) {
			while (s1.size() != 0) {
				s2.push(s1.top());
				s1.pop();
			}
		}
		s2.pop();
	}
	ll get() {
		return gcd(s1.get(), s2.get());
	}
};

bool check(vector<ll>& arr, ll now) {
	nqueue q;
	for (ll i = 1; i < now; i++) {
		q.push(abs(arr[i-1]-arr[i]));
	}
	if (q.get() > 1) {
		return true;
	}
	for (ll i = now; i < arr.size(); i++) {
		q.push(abs(arr[i-1]-arr[i]));
		q.pop();
		if (q.get() > 1) {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll n;
		cin >> n;
		vector<ll> arr(n, 0);
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
		}
		ll l = 1, r = n+1;
		while (r - l > 1) {
			ll mid = (l+r)/2;
			if (check(arr, mid)) {
				l = mid;
			} else {
				r = mid;
			}
		}
		cout << l << '\n';
	}
}