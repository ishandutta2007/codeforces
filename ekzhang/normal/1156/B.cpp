#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

string solve(string S) {
	sort(S.begin(), S.end());
	map<char, int> m;
	for (char c : S)
		m[c]++;

	int k = m.size();
	vector<pair<char, int> > v;
	for (auto p : m)
		v.push_back(p);

	if (k == 1)
		return S;
	if (k == 2) {
		if (v[0].first + 1 != v[1].first) {
			return S;
		}
		return "No answer";
	}
	if (k == 3) {
		if (v[0].first + 1 != v[1].first) {
			return string(v[1].second, v[1].first) + string(v[0].second, v[0].first) + string(v[2].second, v[2].first);
		}
		if (v[1].first + 1 != v[2].first) {
			return string(v[1].second, v[1].first) + string(v[2].second, v[2].first) + string(v[0].second, v[0].first);
		}
		return "No answer";
	}

	string ret;
	int x = k / 2;
	for (int i = 0; i < (k + 1) / 2; i++) {
		ret += string(v[i + x].second, v[i + x].first);
		if (i < x)
			ret += string(v[i].second, v[i].first);
	}
	return ret;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	int N; cin >> N;
	while (N--) {
		string s; cin >> s;
		s = solve(s);
		cout << s << '\n';
	}

	cout.flush();
	return 0;
}