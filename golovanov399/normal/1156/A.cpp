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
	int n = nxt();
	int last = nxt();
	int llast = 0;
	int ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		int x = nxt();
		if (x + last == 5) {
			cout << "Infinite\n";
			return 0;
		} else {
			ans += x + last;
		}
		if (llast == 3 && last == 1 && x == 2) {
			--ans;
		}
		llast = last;
		last = x;
	}
	cout << "Finite\n" << ans << "\n";

	return 0;
}