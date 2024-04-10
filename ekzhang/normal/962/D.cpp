#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 150013
#define MAX (MAXN*1000000013LL)
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	set<pair<LL, int> > s;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		s.emplace(x, i);
	}

	while (s.begin()->first < MAX) {
		auto it = s.begin();
		auto it2 = ++s.begin();

		if (it->first == it2->first) {
			s.emplace(it2->first << 1, it2->second);
			s.erase(it);
			s.erase(it2);
		}
		else {
			s.emplace(it->first + MAX, it->second);
			s.erase(it);
		}
	}

	vector<pair<int, LL> > v;
	for (auto p : s) {
		v.emplace_back(p.second, p.first);
	}
	sort(v.begin(), v.end());

	cout << v.size() << '\n';
	for (auto p : v) {
		cout << p.second - MAX << ' ';
	}

	cout << endl;
	return 0;
}