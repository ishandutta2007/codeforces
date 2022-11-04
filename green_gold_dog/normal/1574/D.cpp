#include <bits/stdc++.h>
typedef int ll;
using namespace std;

const ll INF = 1'000'000'000;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	set<pair<vector<ll>, ll>> be;
	set<pair<ll, pair<vector<ll>, ll>>> now;
	set<vector<ll>> no;
	vector<vector<ll>> arr(n);
	vector<ll> ma(n);
	ll sum = 0, maa = INF;
	for (ll i = 0; i < n; i++) {
		ll c;
		cin >> c;
		arr[i].resize(c);
		for (ll j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
		ma[i] = c - 1;
		sum += arr[i].back();
		assign_min(maa, arr[i].back());
	}
	ll m;
	cin >> m;
	for (ll i = 0; i < m; i++) {
		vector<ll> nn(n, 0);
		for (ll j = 0; j < n; j++) {
			cin >> nn[j];
			nn[j]--;
		}
		no.insert(nn);
	}
	now.insert({-sum, {ma, 0}});
	while (no.count(ma) != 0) {
		if (be.count(now.begin()->second) != 0) {
			now.erase(now.begin());
			continue;
		}
		ma = now.begin()->second.first;
		ll nn = now.begin()->first, col = now.begin()->second.second;
		be.insert({ma, col});
		now.erase(now.begin());
		vector<pair<ll, ll>> mi;
		for (ll i = 0; i < n; i++) {
			ma[i]--;
			if (ma[i] >= 0) {
				mi.push_back({arr[i][ma[i] + 1] - arr[i][ma[i]], i});
			}
			ma[i]++;
		}
		sort(mi.begin(), mi.end());
		for (ll i = 0; i < mi.size(); i++) {
			ma[mi[i].second]--;
			if (be.count(make_pair(ma, 0)) != 0) {
				ma[mi[i].second]++;
				continue;
			}
			now.insert(make_pair(nn + mi[i].first, make_pair(ma, 0)));
			ma[mi[i].second]++;
		}
	}
	for (auto i : ma) {
		cout << i + 1 << ' ';
	}
}

/*
















*/