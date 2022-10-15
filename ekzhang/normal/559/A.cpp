#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
int t, tr, br, b, bl, tl;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("A.in", "r", stdin);
	// freopen("A.out", "w", stdout);

	cin >> t >> tr >> br >> b >> bl >> tl;
	LL ans = 0;
	int k = min(tr, tl);
	ans += (2*t+k)*((LL)k);
	ans += 2 * (max(tr, tl)-k) * (t + k);
	int a = min(bl, br);
	ans += (2*b+a)*((LL)a);

	cout << ans << endl;
	return 0;
}