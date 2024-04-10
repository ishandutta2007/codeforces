#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int N, A, B, K, F; cin >> N >> A >> B >> K >> F;
	map<pair<string, string>, int> mp;
	string prv = "";
	for (int i = 0; i < N; i++) {
		string l, r; cin >> l >> r;
		int cost = (l == prv) ? B : A;
		prv = r;

		if (l > r) swap(l, r);
		mp[pair<string, string>(l, r)] += cost;
	}
	vector<int> costs;
	for (auto it : mp) costs.push_back(it.second);
	sort(costs.begin(), costs.end());
	reverse(costs.begin(), costs.end());
	for (int i = 0; i < K && i < int(costs.size()); i++) {
		costs[i] = min(costs[i], F);
	}
	int res = 0;
	for (int i : costs) res += i;
	cout << res << '\n';

	return 0;
}