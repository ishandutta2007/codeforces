#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#define ll long long
#define endl '\n'

using namespace std;

bool cmp(pair <pair <ll, ll>, ll> a, pair <pair <ll, ll>, ll> b) {
	return (a.first.second < b.first.second);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector <ll> a(n + 1);
	ll x = ceil(sqrt(n + 1));
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	ll q;
	cin >> q;
	vector <pair <pair <ll, ll>, ll>> queries(q);
	for (ll i = 0; i < q; i++) {
		cin >> queries[i].first.first >> queries[i].first.second;
		queries[i].second = i;
	}
	vector <ll> answer(q);
	sort(queries.begin(), queries.end(), cmp);
	vector <ll> dp(n + 1);
	for (ll i = 0; i < q; i++) {
		if (queries[i].first.second > x) {
			ll ans = 0;
			while (queries[i].first.first <= n) {
				ans += a[queries[i].first.first];
				queries[i].first.first += queries[i].first.second;
			}
			answer[queries[i].second] = ans;
			continue;
		}
		if (i == 0 || queries[i].first.second != queries[i - 1].first.second) {
			for (ll j = n; j >= 1; j--) {
				if (j + queries[i].first.second > n)
					dp[j] = a[j];
				else
					dp[j] = a[j] + dp[j + queries[i].first.second];
			}
		}
		answer[queries[i].second] = dp[queries[i].first.first];
	}
	for (ll now : answer)
		cout << now << endl;
	return 0;
}