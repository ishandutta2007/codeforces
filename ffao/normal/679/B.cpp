#include <bits/stdc++.h>
using namespace std;


long long m;

typedef pair<int, long long> pill;

map< pair<long long, long long>, pill > memo;

pill rec(long long lo, long long hi) {
	if (lo == hi && lo == 0) return {0,0};

	pair<long long, long long> pp = {lo, hi};
	if (memo.find(pp) != memo.end()) return memo[pp];

	long long bl = pow(hi, 1/3.0);
	while ((bl+1)*(bl+1)*(bl+1) <= hi) bl++;
	while (bl*bl*bl > hi) bl--;

	pill ans = {0,0};

	long long cb = bl*bl*bl;
	for (int u = (lo+cb-1)/cb; cb*u <= hi; u++) {
		long long mx = min(cb*u + cb-1, hi);
		pill ot = rec(0, mx - cb*u);
		ot.first += u;
		ot.second += cb*u;
		ans = max(ans, ot);
	}

	return memo[pp] = ans;
}

void solve() {
	scanf("%lld", &m);

	pill ans = rec(0, m);
	printf("%d %lld\n", ans.first, ans.second);
}

int main() {
    solve();
}