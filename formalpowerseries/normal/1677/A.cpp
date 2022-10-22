#include <iostream>
using namespace std;
typedef long long LL;
int n;
int a[5005];
int s[5005][5005];
void Solve()
{
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) s[i][j] = s[i - 1][j];
//		memcpy (s[i], s[i - 1], sizeof (s[i]));
		for (int j = a[i]; j <= n; ++ j) ++ s[i][j];
	}
	LL ans = 0;
	for (int j = 0; j < n; ++ j) {
		for (int k = j + 1; k <= n; ++ k) {
			ans += LL (s[j][a[k+1]]) * LL (s[n][a[j+1]] - s[k+1][a[j+1]]);
		}
	}
	cout << ans << endl;
	for (int i = 0; i <= n; ++ i) for (int j = 0; j <= n; ++ j) s[i][j] = a[i] = 0;
}
int main() {
	int T;
	cin >> T;
	while (T) --T, Solve();
	return 0;
}
// Seems like CF1400D.