#include <bits/stdc++.h>
using namespace std;
constexpr int N = 4e5 + 10, maxn = 4e5 + 1, mod = 1e9 + 7;
int n, a[N], fac[N], invfac[N], inv[N];
inline int mul(int a, int b) {return 1ll * a * b % mod;}
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
void init() {
	fac[0] = invfac[0] = 1;
	inv[1] = 1;
	for(int i = 1; i <= maxn; i ++) fac[i] = mul(fac[i - 1], i);
	for(int i = 2; i <= maxn; i ++) inv[i] = mul(mod - mod / i, inv[mod % i]);
	for(int i = 1; i <= maxn; i ++) invfac[i] = mul(invfac[i - 1], inv[i]);
}
inline int c(int n, int m) {
	if(n < m) return 0;
	return mul(fac[n], mul(invfac[m], invfac[n - m]));
}
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init();
	cin >> n;
	for(int i = 0; i <= n; i ++) cin >> a[i];
	int sum = 0;
	for(int i = 0; i <= n; i ++) {
		sum = add(sum, c(i + a[i], i + 1));
	}
	cout << sum << '\n';
	return 0;
}