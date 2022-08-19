#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
using namespace std;
int n;
int x[maxn];
ll a, b;
ll ans = 2e18;
int fl[maxn];
ll fr[maxn], ed[maxn];
void work(int s) {
	for (int j = 1; j <= n; j++)
		if (x[j] % s == 0) fl[j] = 0;
		else if (x[j] % s == 1 || x[j] % s == s - 1) fl[j] = 1;
		else fl[j] = -1;
	for (int j = 1; j <= n; j++)	
		if (fl[j] == -1) fr[j] = 1e18;
		else fr[j] = fr[j - 1] + fl[j] * b;
	for (int j = n; j >= 1; j--) {
		if (fl[j] == -1) ed[j] = 1e18;
		else ed[j] = ed[j + 1] + fl[j] * b;
	}
	ll nm = n * a;
	for (int j = n; j >= 1; j--) {
		ll ca = fr[j] + nm - j * a;
		ans = min(ans, ca);
		nm = min(nm, (j - 1) * a + ed[j]);
	}
	for (int j = n; j >= 1; j--)
		ans = min(ans, ed[j] + (j - 1) * a); 
}
void solve(int a) {
	for (int j = 2; j * j <= a; j++) {
		if (a % j == 0) {
			work(j);
			while (a % j == 0) a /= j;
		}
	}
	if (a != 1) work(a);
}
int main() {
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)	
		scanf("%d", &x[i]);
	solve(x[1] + 1), solve(x[1] - 1), solve(x[1]);
	solve(x[n] + 1), solve(x[n] - 1), solve(x[n]);
	cout << ans << endl;
	return 0;
}