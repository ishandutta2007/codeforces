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

void solve() {
	int n = nxt();
	pair<int, long long> neg = {0, 0}, pos = {0, 0};
	while (n--) {
		int x = nxt();
		if (x > 0) {
			pos = max(pos, {neg.first + 1, neg.second + x});
		} else {
			neg = max(neg, {pos.first + 1, pos.second + x});
		}
	}
	cout << max(pos, neg).second << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}