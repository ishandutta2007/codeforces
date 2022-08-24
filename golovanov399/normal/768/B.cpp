#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	long long n, l, r;
	cin >> n >> l >> r;
	vector<int> digits;
	while (n) {
		digits.push_back(n % 2);
		n /= 2;
	}
	if (digits.empty()) {
		digits.push_back(0);
	}
	reverse(all(digits));

	int ans = 0;
	for (long long i = l; i <= r; ++i) {
		ans += digits[__builtin_ctzll(i)];
	}
	printf("%d\n", ans);

	return 0;
}