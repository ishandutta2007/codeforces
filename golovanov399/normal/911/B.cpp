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
	for (int k = 1;; ++k) {
		if (a / k + b / k < n) {
			cout << min({k - 1, a, b}) << "\n";
			return 0;
		}
	}
	
	return 0;
}