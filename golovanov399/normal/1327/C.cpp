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
	int n = nxt(), m = nxt();
	cout << n - 1 + m - 1 + n * m - 1 << "\n";
	cout << string(n - 1, 'D') << string(m - 1, 'L');
	for (int i = 0; i < m; ++i) {
		cout << string(n - 1, i % 2 ? 'D' : 'U');
		if (i < m - 1) {
			cout << 'R';
		}
	}
	cout << "\n";

	return 0;
}