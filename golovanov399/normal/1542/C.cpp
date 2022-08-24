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

void A() {
	int n = nxt();
	int cnt = 0;
	for (int i = 0; i < 2 * n; ++i) {
		cnt += nxt() % 2;
	}
	puts(cnt == n ? "Yes" : "No");
}

void B() {
	int n = nxt(), a = nxt(), b = nxt();
	int x = 1;
	set<int> S;
	while (!S.count(x % b)) {
		S.insert(x % b);
		if (x % b == n % b) {
			cout << "Yes\n";
			return;
		}
		if (x > n / a) {
			break;
		}
		x *= a;
	}
	cout << "No\n";
}

void C() {
	const vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
	constexpr int mod = 1'000'000'007;
	long long n;
	cin >> n;
	long long ans = 0;
	long long cur = 1;
	for (int i = 2; n >= cur; ++i) {
		ans += (n / cur - n / lcm(cur, i)) % mod * i % mod;
		cur = lcm(cur, i);
	}
	cout << ans % mod << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		C();
	}

	return 0;
}