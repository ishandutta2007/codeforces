#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 300013
int N, P, K;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	map<int, int> m;
	cin >> N >> P >> K;
	LL ans = 0;
	for (int i = 0; i < N; i++) {
		LL x; cin >> x;
		LL po = (x * x) % P;
		po = (po * po) % P;
		po = (po + P - (K * x) % P) % P;
		ans += m[po]++;
	}

	cout << ans << endl;
	return 0;
}