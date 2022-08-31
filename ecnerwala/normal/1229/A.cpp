#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 8000;
int N;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	vector<pair<ll, ll>> V(N);
	for (int i = 0; i < N; i++) {
		cin >> V[i].first;
	}
	for (int i = 0; i < N; i++) {
		cin >> V[i].second;
	}
	map<ll, vector<ll>, greater<ll>> mp;
	for (auto it : V) {
		mp[it.first].push_back(it.second);
	}
	vector<ll> usedSet;
	ll tot = 0;
	for (const auto& it : mp) {
		ll a = it.first;
		bool take = false;
		if (it.second.size() >= 2) {
			take = true;
		} else {
			for (auto b : usedSet) {
				if ((a & b) == a) {
					take = true;
					break;
				}
			}
		}
		if (take) {
			usedSet.push_back(a);
			for (ll v : it.second) tot += v;
		}
	}

	cout << tot << '\n';

	return 0;
}