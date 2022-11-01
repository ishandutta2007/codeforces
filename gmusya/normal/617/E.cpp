#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define endl '\n'
#define ll long long

using namespace std;

ll n, q, k, L;

bool cmp(pair <pair <ll, ll>, ll> a, pair <pair <ll, ll>, ll> b) {
	return (a.first.first / L < b.first.first / L) || (a.first.first / L == b.first.first / L && a.first.second < b.first.second);
}

vector <ll> state(2e6 + 1), a, pref;

void count(ll l, ll r, ll prev_l, ll prev_r, ll &ans) {
	for (ll i = prev_l - 1; i >= l; i--) {
		ans += state[pref[i] ^ k];
		state[pref[i]]++;
	}
	for (ll i = prev_r + 1; i <= r; i++) {
		ans += state[pref[i] ^ k];
		state[pref[i]]++;
	}
	for (ll i = prev_l; i < l; i++) {
		state[pref[i]]--;
		ans -= state[pref[i] ^ k];
	}
	for (ll i = prev_r; i > r; i--) {
		state[pref[i]]--;
		ans -= state[pref[i] ^ k];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q >> k;
	L = ceil(sqrt(n));
	a.resize(n + 1), pref.resize(n + 1);
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	for (ll i = 1; i <= n; i++)
		pref[i] = pref[i - 1] ^ a[i];
	vector <pair <pair <ll, ll>, ll>> query(q);
	for (ll i = 0; i < q; i++) {
		cin >> query[i].first.first >> query[i].first.second;
		query[i].second = i;
	}
	vector <ll> answer(q);
	sort(query.begin(), query.end(), cmp);
	ll prev_l = 0, prev_r = 0, ans = 0;
	state[0] = 1;
	for (ll i = 0; i < q; i++) {
		ll l = query[i].first.first - 1;
		ll r = query[i].first.second;
		count(l, r, prev_l, prev_r, ans);
		prev_l = l, prev_r = r;
		answer[query[i].second] = ans;
	}
	for (ll x : answer)
		cout << x << endl;
	return 0;
}