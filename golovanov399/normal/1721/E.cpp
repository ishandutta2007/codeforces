#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

const int K = 26;

void solve() {
	string s;
	cin >> s;
	const int n = s.length();
	vector<int> p(n + 1);
	for (int i = 2; i <= n; ++i) {
		p[i] = p[i - 1];
		while (p[i] > 0 && s[i - 1] != s[p[i]]) {
			p[i] = p[p[i]];
		}
		if (s[i - 1] == s[p[i]]) {
			p[i] += 1;
		}
	}
	vector<array<int, K>> next_given_letter(n + 1, array<int, K>{});
	for (int i = 1; i < (int)next_given_letter.size(); ++i) {
		next_given_letter[i] = next_given_letter[p[i]];
		if (i < n) {
			next_given_letter[i][s[i] - 'a'] = i;
		}
	}

	int q = nxt();
	while (q --> 0) {
		string t;
		cin >> t;
		for (int i = 0; i < (int)t.size(); ++i) {
			int l = p.back();
			while (l >= n && t[i] != t[l - n]) {
				l = p[l];
			}
			if (l >= n) {
				++l;
			} else {
				l = next_given_letter[l][t[i] - 'a'];
				if (t[i] == s[l]) {
					++l;
				}
			}
			p.push_back(l);

			cout << p.back() << " ";
		}
		cout << "\n";
		p.erase(p.end() - t.size(), p.end());
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	for (int i = 1; i <= t; ++i) {
		solve();
	}

	return 0;
}