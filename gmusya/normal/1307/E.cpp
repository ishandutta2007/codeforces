#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	vector <ll> s(n + 1);
	for (ll i = 1; i <= n; i++)
		cin >> s[i];
	vector <vector <ll>> cows(n + 1);
	for (ll i = 1; i <= m; i++) {
		ll f, h;
		cin >> f >> h;
		cows[f].push_back(h);
	}
	for (ll i = 1; i <= n; i++)
		sort(cows[i].begin(), cows[i].end());
	vector <vector <ll>> grass(n + 2, vector<ll>(n + 2));
	for (ll i = 1; i <= n; i++) {
		grass[i] = grass[i - 1];
		grass[i][s[i]]++;
	}
	vector <bool> can(n + 1);
	vector <ll> answer(n + 1);
	ll kekw = -1, lulw = -1;
	for (ll border = 0; border <= n; border++) {
		ll sum = 0, mus = 0;
		ll variations = 1, cnt = 0;
		vector <ll> left(n + 1), right(n + 1);
		for (ll i = 1; i <= n; i++)
			left[i] = grass[border][i];
		for (ll i = 1; i <= n; i++)
			right[i] = grass[n][i] - left[i];
		bool tf = false;
		ll x;
		for (ll i = 0; i <= n; i++) {
			if (cows[i].size() == 0)
				continue;
			ll left_pos, right_pos;
			ll l = 0, r = cows[i].size() - 1;
			while (l != r) {
				ll m = (l + r + 1) / 2;
				if (cows[i][m] <= left[i])
					l = m;
				else
					r = m - 1;
			}
			left_pos = l;
			l = 0, r = cows[i].size() - 1;
			while (l != r) {
				ll m = (l + r + 1) / 2;
				if (cows[i][m] <= right[i])
					l = m;
				else
					r = m - 1;
			}
			right_pos = r;
			ll a = min(left_pos, right_pos);
			ll b = max(left_pos, right_pos);
			if ((cows[i][left_pos] == left[i] && grass[border][i] - grass[border - 1][i] == 1) || border == 0) {
				tf = true;
				if (cows[i][0] > right[i]) {
					if (cows[i][0] <= left[i])
						cnt++;
					continue;
				}
				if (cows[i][0] <= right[i] && cows[i][0] > left[i]) {
					cnt++;
					variations = (variations * (right_pos + 1)) % MOD;
					continue;
				}
				if (a == b && a == 0) {
					cnt++;
					continue;
				}
				cnt += 2;
				variations = (variations * (right_pos + 1 - (left_pos <= right_pos))) % MOD;
				continue;
			}
			if (cows[i][0] > max(left[i], right[i]))
				continue;
			if (cows[i][0] > min(left[i], right[i])) {
				cnt++;
				variations = variations * (b + 1) % MOD;
				continue;
			}
			if (a == b && a == 0) {
				cnt++;
				variations = 2 * variations % MOD;
				continue;
			}
			cnt += 2;
			variations = variations * (a + 1) * b % MOD;
		}
		if (!tf)
			continue;
		can[cnt] = true;
		answer[cnt] = (answer[cnt] + variations) % MOD;
	}
	pair <ll, ll> ans = { 0, 0 };
	for (ll i = 0; i <= n; i++)
		if (can[i])
			ans = { i, answer[i] };
	cout << ans.first << " " << ans.second;
	return 0;
}