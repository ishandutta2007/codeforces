#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
typedef long long ll;
using namespace std;

const int mod = 998244353, maxn = 1e5 + 5;
int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return (a * 1ll * b) % ((ll)mod); }
void upd(int& a, int b) { a = (a + b) % mod; }
int pwr(int a, int b = mod - 2)
{
	if (!b) return 1;
	int h = pwr(a, b >> 1);
	h = mul(h, h);
	if (b & 1) h = mul(h, a);
	return h;
}
int f[maxn], invf[maxn];
int n;
int c(int n, int k)
{
	return mul(f[n], mul(invf[n - k], invf[k]));
}
int solve(int bl, int wl, int ql, int br, int wr, int qr)
{
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		int j = n - i;
		if (i < bl || i < wr || i > bl + ql || i > wr + qr) continue;
		if (j < br || j < wl || j > br + qr || j > wl + ql) continue;
		upd(ans, mul(c(ql, i - bl), c(qr, i - wr)));
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	f[0] = 1, invf[0] = 1;
	for (int i = 1; i < maxn; i++)
	{
		f[i] = mul(f[i - 1], i);
		invf[i] = mul(invf[i - 1], pwr(i));
	}
	cin >> n;
	int bw = 1, wb = 1;
	int bad = 1, bl = 0, wl = 0, ql = 0, br = 0, wr = 0, qr = 0;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (s[0] == 'W' || s[1] == 'B') bw = 0;
		if (s[0] == 'B' || s[1] == 'W') wb = 0;
		if (s == "WW" || s == "BB") bad = 0;
		if (s == "??") bad = mul(bad, 2);
		if (s[0] == 'B') bl++;
		if (s[0] == 'W') wl++;
		if (s[0] == '?') ql++;
		if (s[1] == 'B') br++;
		if (s[1] == 'W') wr++;
		if (s[1] == '?') qr++;
	}
	int ans = solve(bl, wl, ql, br, wr, qr);
	upd(ans, mod - bad);
	upd(ans, bw + wb);
	cout << ans << "\n";
	return 0;
}