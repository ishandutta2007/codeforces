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

const int N = 2222222;
long long res[N];
const int mod = 1000000007;

void solve() {
	cout << res[nxt() - 1] * 4 % mod << "\n";
}

int main() {
	for (int i = 2; i < N; ++i) {
		res[i] = (res[i - 1] * 2 + vector{0, 0, 1, -1, 1, 0}[i % 6]) % mod;
	}

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}