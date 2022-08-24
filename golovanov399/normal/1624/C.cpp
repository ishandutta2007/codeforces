#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	priority_queue<int> pq;
	for (int i = 0; i < n; ++i) {
		pq.push(nxt());
	}
	for (int i = n; i >= 1; --i) {
		while (pq.top() > i) {
			int x = pq.top();
			pq.pop();
			pq.push(x / 2);
		}
		if (pq.top() != i) {
			cout << "No\n";
			return;
		}
		pq.pop();
	}
	cout << "Yes\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}