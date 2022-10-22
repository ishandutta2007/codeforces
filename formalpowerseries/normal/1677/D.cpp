#include <iostream>
using namespace std;
typedef long long LL;
const int P = 998244353;
int n, k;
int a[1000005], b[1000005];
void Solve()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	for (int i = n - k + 1; i <= n; ++ i) {
		if (a[i] > 0) {
			cout << 0 << endl;
			return ;
		}
	}
	for (int i = 1; i <= n; ++ i) {
		if (a[i] != -1 && a[i] >= i) {
			cout << 0 << endl;
			return ;
		}
	}
	int ans = 1;
	for (int i = 1; i <= n; ++ i) {
		if (i <= k) ans = LL (ans) * LL (i) % P;
		else if (a[i - k] == -1) ans = LL (ans) * LL (i) % P;
		else if (a[i - k] == 0) ans = LL (ans) * LL (k+1) % P;
	}
	cout << ans << endl;
	for (int i = 1; i <= n; ++ i) b[i] = 0;
}
int main() {
	int T;
	cin >> T;
	while (T) --T, Solve();
	return 0;
}