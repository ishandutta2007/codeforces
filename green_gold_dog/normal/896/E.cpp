#pragma GCC target("sse,sse2,sse3,avx,avx2,popcnt,abm,mmx,sse4")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<map>
#include<deque>

using namespace std;

typedef int ll;

template<typename T>
bool assign_min(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_max(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	ll arr[100000];
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (ll i = 0; i < m; i++) {
		ll t, l, r, x;
		cin >> t >> l >> r >> x;
		l--;
		if (t == 1) {
			for (ll i = l; i < r; i++) {
				if (arr[i] > x) {
					arr[i] -= x;
				}
			}
		} else {
			ll ans = 0;
			for (ll i = l; i < r; i++) {
				ans += arr[i] == x;
			}
			cout << ans << '\n';
		}
	}
}

int main() {
	cin.tie(0)->ios_base::sync_with_stdio(false);
	solve();
}