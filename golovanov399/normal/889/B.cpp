#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void panic() {
	puts("NO");
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0);

	int n = nxt();
	vector<char> pr(26, 0), nx(26, 0);
	vector<char> need(26, 0);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (char c : s) {
			need[c - 'a'] = 1;
		}
		for (int j = 0; j < (int)s.length() - 1; ++j) {
			char u = s[j], v = s[j + 1];
			if (nx[u - 'a'] && nx[u - 'a'] != v) {
				panic();
			}
			nx[u - 'a'] = v;
			if (pr[v - 'a'] && pr[v - 'a'] != u) {
				panic();
			}
			pr[v - 'a'] = u;
		}
	}

	string res = "";
	vector<char> used(26, 0);
	for (int i = 0; i < 26; ++i) {
		char c = 'a' + i;
		if (need[i] && (!nx[i] && !pr[i])) {
			res += c;
		}
		if (nx[i] == 0) {
			continue;
		}
		if (pr[i]) {
			continue;
		}
		res += c;
		int j = i;
		used[i] = 1;
		while (nx[j]) {
			if (nx[j] == c) {
				panic();
			}
			res += nx[j];
			j = nx[j] - 'a';
			used[j] = 1;
		}
	}
	for (int i = 0; i < 26; ++i) {
		if ((nx[i] || pr[i]) && !used[i]) {
			panic();
		}
	}
	cout << res << "\n";

	return 0;
}