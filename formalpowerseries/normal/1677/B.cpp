#include <iostream>
using namespace std;
typedef long long LL;
char s[1000005];
int n, m;
int a[1000005], b[1000005], sum[1000005];
void Solve()
{
	cin >> n >> m;
	cin >> (s + 1);
	int ans = 0;
	for (int i = 1; i <= n * m; ++ i) {
		int c = s[i] ^ '0';
		sum[i] = sum[i-1] + c;
		if (c) {
			if (!a[i % m]) {
				++ ans;
				a[i % m] = 1;
			}
		}
		if (i < m) b[i % m] = !!sum[i];
		else	b[i % m] += !!(sum[i] - sum[i - m]);
		cout << b[i % m] + ans << ' ';
	}
	cout << endl;
	for (int i = 0; i <= max (n, m); ++ i) a[i] = b[i] = 0;
}
int main() {
	int T;
	cin >> T;
	while (T) --T, Solve();
	return 0;
}