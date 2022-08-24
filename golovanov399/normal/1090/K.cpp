#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

int main() {
	cin.sync_with_stdio(0);
	int n = nxt();
	map<pair<string, int>, vector<int>> M;
	for (int i = 0; i < n; ++i) {
		string s, t;
		cin >> s >> t;
		int mask = 0;
		for (char c : t) {
			mask |= 1 << (c - 'a');
		}
		while (!s.empty() && ((1 << (s.back() - 'a')) & mask)) {
			s.pop_back();
		}
		pair<string, int> p(s, mask);
		M[p].push_back(i);
	}
	printf("%d\n", (int)M.size());
	for (const auto& p : M) {
		printf("%d", (int)p.second.size());
		for (int x : p.second) {
			printf(" %d", x + 1);
		}
		printf("\n");
	}

	return 0;
}