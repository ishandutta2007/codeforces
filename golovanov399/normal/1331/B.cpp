#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt();
	for (int p = 2; p < n; ++p) {
		if (n % p == 0) {
			cout << p << n / p << "\n";
			break;
		}
	}

	return 0;
}