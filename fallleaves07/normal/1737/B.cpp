#include<bits/stdc++.h>
using namespace std;
using LL = long long;

LL calc(LL x) {
	if (x == 0) {
		return 0;
	}
	LL d = sqrtl(x);
	LL ret = (d - 1) * 3ll + x / d - d + 1;
	return ret;
}

void solve() {
	LL l, r;
	cin >> l >> r;
	printf("%lld\n", calc(r) - calc(l - 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}