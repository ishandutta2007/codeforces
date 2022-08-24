#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int t = nxt();
	while (t--) {
		string s;
		cin >> s;
		set<pair<pair<int, int>, pair<int, int>>> S;
		pair<int, int> p = {0, 0};
		int ans = 0;
		for (char c : s) {
			auto q = p;
			if (c == 'S') {
				q.second -= 1;
			}
			if (c == 'N') {
				q.second += 1;
			}
			if (c == 'E') {
				q.first += 1;
			}
			if (c == 'W') {
				q.first -= 1;
			}
			auto w = make_pair(min(p, q), max(p, q));
			if (S.count(w)) {
				ans += 1;
			} else {
				ans += 5;
			}
			S.insert(w);
			p = q;
		}
		cout << ans << "\n";
	}

	return 0;
}