#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>

#define ll long long
#define endl '\n'

using namespace std;

ll n, t, X;
vector <ll> a, answer, state(1e6 + 1);
vector <pair <pair <ll, ll>, ll>> query;

bool cmp(pair <pair <ll, ll>, ll> a, pair <pair <ll, ll>, ll> b) {
	return (a.first.first / X > b.first.first / X) || 
	(a.first.first / X == b.first.first / X && a.first.second < b.first.second);
}

ll count(ll l, ll r, ll prev_l, ll prev_r, ll prev_ans) {
	for (ll i = l; i < prev_l; i++) {
		state[a[i]]++;
		prev_ans += (state[a[i]] * 2 - 1) * a[i];
	}
	for (ll i = prev_l; i < l; i++) {
		prev_ans -= (state[a[i]] * 2 - 1) * a[i];
		state[a[i]]--;
	}
	for (ll i = r + 1; i <= prev_r; i++) {
		prev_ans -= (state[a[i]] * 2 - 1) * a[i];
		state[a[i]]--;
	}
	for (ll i = prev_r + 1; i <= r; i++) {
		state[a[i]]++;
		prev_ans += (state[a[i]] * 2 - 1) * a[i];
	}
	return prev_ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> t;
	X = ceil(sqrt(n));
	a.resize(n), query.resize(t), answer.resize(t);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	for (ll i = 0; i < t; i++) {
		cin >> query[i].first.first >> query[i].first.second;
		query[i].second = i;
	}
	sort(query.begin(), query.end(), cmp);
	ll ans = a[0], prev_l = 0, prev_r = 0;
	state[a[0]]++;
	for (ll i = 0; i < t; i++) {
		ll l, r;
		l = query[i].first.first;
		r = query[i].first.second;
		ans = count(l - 1, r - 1, prev_l, prev_r, ans);
		answer[query[i].second] = ans;
		prev_l = l - 1;
		prev_r = r - 1;
	}
	for (auto now : answer)
		cout << now << endl;
	return 0;
}