#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define db double
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll ksm(ll a, ll b, ll c) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1, c);
   ns = ns * ns % c;
   if (b & 1) ns = ns * a % c;
   return ns;
}
int a[maxn];
unordered_map<int, int> fl;
bool cu[maxn];
int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	if (n == m) {
		cout << 0 << ' ' << 1 << endl;
		return 0;
	}
	if (n == 1) {
		cout << a[1] << ' ' << 0 << endl;
		return 0;
	}
	int cc = 0;
	if (2 * n >= m) {
		cc = 1;
		for (int i = 1; i <= n; i++)
			cu[a[i]] = 1;
		int cnt = 0;
		for (int i = 0; i < m; i++)
			if (!cu[i])
				a[++cnt] = i;
		n = cnt;
	}
	if (n == 1) {
		cout << (a[1] + 1) % m << ' ' << 1 << endl;
		return 0;
	}
//	cout << n << ' ' << a[1] << ' ' << a[2] << endl;
	ll s = 0;
	for (int i = 1; i <= n; i++)
		s += a[i];
	s %= m;
	s = s * ksm(n, m - 2, m) % m;
	for (int i = 1; i <= n; i++) {
		int cur = a[i] - s;
		cur %= m;
		if (cur < 0) cur += m;
		fl[cur] = 1;
	}
	for (int i = 1; i <= n; i++) {
		ll dis = a[i] - s;
		int fls = 1;
		if (n % 2 == 1) dis = dis * (m + 1) / 2 % m; // dis :  
		dis %= m;
		if (dis == 0) continue;
		for (int j = -(n - 1); j <= n - 1; j += 2) {
			ll nc = dis * j % m;
			if (nc < 0) nc += m;
			if (!fl[nc]) {
				fls = 0;
				break;
			}
		}
		if (fls) {
			ll cur = s - dis * (n - 1) % m;
			cur %= m;
			if (cur < 0) cur += m;
			dis = dis * 2 % m;
			if (dis < 0) dis += m;
			if (cc) cur = (cur + n * dis) % m;
			cout << cur << ' ' << dis << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
/*
5 4
0 1 2 3

*/