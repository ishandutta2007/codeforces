#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MOD 998244353
#define MAXN 1000013
int N;
LL par[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	par[0] = 1;
	for (int i = 0; i < N; i++) {
		par[i + 1] = (par[i] * (N - i)) % MOD;
	}

	LL pre = 1;
	LL ans = 1;
	for (int i = 1; i <= N; i++) {
		LL d = (MOD + par[i] - pre) % MOD;
		ans = (ans + i * d) % MOD;
		pre = par[i];
	}

	cout << ans << endl;
	return 0;
}