#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt(), a = nxt(), b = nxt();
	vector<int> ar = {a, a, b, a, a, b};
	int ans = 6;
	do {
		itn cur = 1, tmp = 0;
		for (int x : ar) {
			tmp += x;
			if (tmp == n) {
				cur += 1;
				tmp = 0;
			}
			if (tmp > n) {
				tmp = x;
				cur += 1;
			}
		}
		if (tmp == 0) {
			cur -= 1;
		}
		ans = min(ans, cur);
	} while (next_permutation(all(ar)));
	cout << ans << "\n";
	
	return 0;
}