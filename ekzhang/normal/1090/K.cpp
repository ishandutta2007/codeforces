#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
int N;
map<pair<string, string>, vector<int> > ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s, t;
		cin >> s >> t;
		sort(t.begin(), t.end());
		t.resize(unique(t.begin(), t.end()) - t.begin());
		set<char> alpha(t.begin(), t.end());
		while (s.size() && alpha.count(s.back()))
			s.pop_back();
		ans[{ s, t }].push_back(i + 1);
	}

	cout << ans.size() << '\n';
	for (const auto& p : ans) {
		const vector<int>& v = p.second;
		cout << v.size();
		for (int x : v)
			cout << ' ' << x;
		cout << '\n';
	}

	cout.flush();
	return 0;
}