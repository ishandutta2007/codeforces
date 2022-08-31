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

bool win(long long our_h, long long our_d, long long gay_h, long long gay_d) {
	return (gay_h + our_d - 1) / our_d <= (our_h + gay_d - 1) / gay_d;
}

void solve() {
	long long our_h, our_d, gay_h, gay_d;
	cin >> our_h >> our_d >> gay_h >> gay_d;
	int k = nxt();
	long long add_d, add_h;
	cin >> add_d >> add_h;
	for (int i = 0; i <= k; ++i) {
		if (win(our_h + i * add_h, our_d + (k - i) * add_d, gay_h, gay_d)) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}