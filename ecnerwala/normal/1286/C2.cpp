#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	int R = N / 3;
	int L = N - R;

	assert(L >= 1);
	cout << '?' << ' ' << 1 << ' ' << L << '\n';
	if (L >= 2) {
		cout << '?' << ' ' << 2 << ' ' << L << '\n';
	}
	cout << flush;

	multiset<string> subs;
	for (int i = 0; i < L * (L+1) / 2; i++) {
		string s; cin >> s;
		sort(s.begin(), s.end());
		subs.insert(s);
	}
	for (int i = 0; i < L * (L-1) / 2; i++) {
		string s; cin >> s;
		sort(s.begin(), s.end());
		subs.erase(subs.find(s));
	}

	vector<string> prefs(subs.begin(), subs.end());
	sort(prefs.begin(), prefs.end(), [](const string& a, const string& b) { return a.size() < b.size(); });
	string ans;
	for (int i = 0; i < L; i++) {
		assert(int(prefs[i].size()) == i+1);
		multiset<char> chars(prefs[i].begin(), prefs[i].end());
		for (char c : ans) {
			chars.erase(chars.find(c));
		}
		ans += *chars.begin();
	}

	if (R) {
		cout << '?' << ' ' << (L - (R-1)) + 1 << ' ' << N << '\n';
		cout << flush;
		vector<multiset<char>> mp(R);
		for (int i = 0; i < (2*R-1) * (2*R) / 2; i++) {
			string s; cin >> s;
			if (int(s.size()) <= R) {
				for (char c : s) {
					mp[int(s.size()) - 1].insert(c);
				}
			}
		}
		for (int i = R-1; i > 0; i--) {
			for (char c : mp[i-1]) {
				mp[i].erase(mp[i].find(c));
			}
		}
		for (int i = 1; i <= R-1; i++) {
			for (char c : mp[i]) {
				mp[i-1].erase(mp[i-1].find(c));
			}
		}
		for (int i = 0; i < R-1; i++) {
			mp[i].erase(mp[i].find(ans[L-(R-1) + i]));
		}
		for (int i = R-1; i >= 0; i--) {
			assert(mp[i].size() == 1);
			ans += *mp[i].begin();
		}
	}

	cout << '!' << ' ' << ans << '\n';

	return 0;
}