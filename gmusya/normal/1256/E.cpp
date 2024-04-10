#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int

using namespace std;

ll INF = 1000000000000;

ll min(ll a, ll b, ll c) {
	ll k = a;
	if (k > b)
		k = b;
	if (k > c)
		k = c;
	return k;
}

bool cmp(pair <ll, ll> &a, pair <ll, ll> &b) {
	return (a.first < b.first);
}

bool uncmp(pair <ll, ll> &a, pair <ll, ll> &b) {
	return (a.second < b.second);
}

int main() {
	ll n;
	cin >> n;
	vector <pair <ll, ll>> stud;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		stud.push_back({ x, i });
	}
	sort(stud.begin(), stud.end(), cmp);
	vector <vector <ll>> dyn(n);
	for (ll i = 0; i < n; i++)
		dyn[i].resize(3);
	dyn[0][0] = INF;
	dyn[0][1] = INF;
	dyn[0][2] = INF;
	dyn[1][0] = INF;
	dyn[1][1] = INF;
	dyn[1][2] = INF;
	dyn[2][0] = stud[2].first - stud[0].first;
	dyn[2][1] = INF;
	dyn[2][2] = INF;
	dyn[3][0] = INF;
	dyn[3][1] = stud[3].first - stud[0].first;
	dyn[3][2] = INF;
	dyn[4][0] = INF;
	dyn[4][1] = INF;
	dyn[4][2] = stud[4].first - stud[0].first;
	for (ll i = 5; i < n; i++) {
		dyn[i][0] = min(dyn[i - 3][0], dyn[i - 3][1], dyn[i - 3][2]) + stud[i].first - stud[i - 2].first;
		dyn[i][1] = min(dyn[i - 4][0], dyn[i - 4][1], dyn[i - 4][2]) + stud[i].first - stud[i - 3].first;
		dyn[i][2] = min(dyn[i - 5][0], dyn[i - 5][1], dyn[i - 5][2]) + stud[i].first - stud[i - 4].first;
	}
	ll cnt = 0;
	cout << min(dyn[n - 1][0], dyn[n - 1][1], dyn[n - 1][2]) << " ";
	ll i = n - 1;
	while (i >= 0) {
		cnt++;
		if (dyn[i][0] <= dyn[i][1] && dyn[i][0] <= dyn[i][2]) {
			for (ll x = i; x >= i - 2; x--)
				stud[x].first = cnt;
			i = i - 3;
			continue;
		}
		if (dyn[i][1] <= dyn[i][0] && dyn[i][1] <= dyn[i][2]) {
			for (ll x = i; x >= i - 3; x--)
				stud[x].first = cnt;
			i = i - 4;
			continue;
		}
		if (dyn[i][2] <= dyn[i][0] && dyn[i][2] <= dyn[i][1]) {
			for (ll x = i; x >= i - 4; x--)
				stud[x].first = cnt;
			i = i - 5;
			continue;
		}
	}
	cout << cnt << " " << endl;
	sort(stud.begin(), stud.end(), uncmp);
	for (auto now : stud)
		cout << now.first << " ";
	return 0;
}