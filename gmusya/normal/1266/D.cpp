#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <ll> balance(n);
	for (int i = 0; i < m; i++) {
		ll u, v, val;
		cin >> u >> v >> val;
		balance[u - 1] -= val;
		balance[v - 1] += val;
	}
	vector <pair <ll, ll>> owe;
	vector <pair <ll, ll>> not_owe;
	for (int i = 0; i < n; i++) {
		if (balance[i] > 0)
			not_owe.push_back({ i + 1, abs(balance[i]) });
		if (balance[i] < 0)
			owe.push_back({ i + 1, abs(balance[i]) });
	}
	vector < pair <pair <ll, ll>, ll>> answer;
	int uk1 = 0, uk2 = 0;
	while (uk1 < not_owe.size() && uk2 < owe.size()) {
		if (not_owe[uk1].second > owe[uk2].second) {
			answer.push_back({ {owe[uk2].first, not_owe[uk1].first}, owe[uk2].second });
			not_owe[uk1].second -= owe[uk2].second;
			uk2++;
			continue;
		}
		if (not_owe[uk1].second < owe[uk2].second) {
			answer.push_back({ {owe[uk2].first, not_owe[uk1].first}, not_owe[uk1].second });
			owe[uk2].second -= not_owe[uk1].second;
			uk1++;
			continue;
		}
		if (not_owe[uk1].second == owe[uk2].second) {
			answer.push_back({ {owe[uk2].first, not_owe[uk1].first}, not_owe[uk1].second });
			uk1++;
			uk2++;
		}
	}
	cout << answer.size() << endl;
	for (auto now : answer)
		cout << now.first.first << " " << now.first.second << " " << now.second << endl;
	return 0;
}