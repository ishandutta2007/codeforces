#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	cout << '?' << ' ' << 1 << ' ' << N << '\n';
	if (N >= 2) {
		cout << '?' << ' ' << 2 << ' ' << N << '\n';
	}
	cout << flush;

	multiset<string> subs;
	for (int i = 0; i < N * (N+1) / 2; i++) {
		string s; cin >> s;
		sort(s.begin(), s.end());
		subs.insert(s);
	}
	for (int i = 0; i < N * (N-1) / 2; i++) {
		string s; cin >> s;
		sort(s.begin(), s.end());
		subs.erase(subs.find(s));
	}

	vector<string> prefs(subs.begin(), subs.end());
	sort(prefs.begin(), prefs.end(), [](const string& a, const string& b) { return a.size() < b.size(); });
	string ans;
	for (int i = 0; i < N; i++) {
		assert(int(prefs[i].size()) == i+1);
		multiset<char> chars(prefs[i].begin(), prefs[i].end());
		for (char c : ans) {
			chars.erase(chars.find(c));
		}
		ans += *chars.begin();
	}
	cout << '!' << ' ' << ans << '\n';

	return 0;
}