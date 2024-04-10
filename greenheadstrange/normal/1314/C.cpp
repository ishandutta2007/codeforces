#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int maxl = 4005;
int s[maxl];
int rk[maxl], sa[maxl], cnt[maxl], a[maxl], b[maxl];
int len = 1;
void bogo_sort()
{
	int n = len;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++)
		cnt[b[i]]++;
	for(int i = 1; i < maxl; i++)
		cnt[i] += cnt[i - 1];
	for(int i = 1; i <= n; i++)
		rk[i] = cnt[b[i]]--, sa[rk[i]] = i;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++)
		cnt[a[i]]++;
	for(int i = 1; i < maxl; i++)
		cnt[i] += cnt[i - 1];
	for(int i = n; i >= 1; i--)
		rk[sa[i]] = cnt[a[sa[i]]]--;
	for(int i = 1; i <= n; i++)
		sa[rk[i]] = i;
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(i == 1 || a[sa[i]] != a[sa[i - 1]] || b[sa[i]] != b[sa[i - 1]]) cnt++;
		rk[sa[i]] = cnt;
	}
}
int h[maxl], height[maxl];
int st[22][maxl];
int lg2[maxl];
void initsuffix()
{
	int n = len;
	for(int i = 1; i <= n; i++)
		a[i] = s[i], b[i] = 1;
	bogo_sort();
	int l = 1;
	while(l < n)
	{
		for(int i = 1; i <= n; i++)
			a[i] = rk[i], b[i] = rk[i + l];
		bogo_sort();
		l <<= 1;
	}
	for(int i = 1; i <= n; i++)
	{
		h[i] = max(0, h[i - 1] - 1);
		while(i + h[i] <= n && s[i + h[i]] == s[sa[rk[i] + 1] + h[i]]) h[i]++;
	}
	for(int i = 1; i <= n; i++) height[i] = h[sa[i]];
	for(int i = 0; i < 22; i++)
		for(int j = 1; j <= n + 1 - (1 << i); j++)
		{
			if(!i) st[i][j] = height[j];
			else st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		}
	for(int i = 0; i < 22; i++)
		for(int j = (1 << i); j <= n && j < (1 << (i + 1)); j++)
			lg2[j] = i;
}
int qmin(int a, int b)
{
	int l = b - a + 1;
	int bs = lg2[l];
	int ans = min(st[bs][a], st[bs][b - (1 << bs) + 1]);
	return ans;
}
int qsuffix(int l, int r)
{	// l, r 
	if (l == r) return len - l + 1;
	if(rk[l] > rk[r]) swap(l, r);
	int ans = qmin(rk[l], rk[r] - 1);
	return ans;	
}
int n, m;
ll k;
char x[maxl];
bool cmp(pi a, pi b) { 
	int l = qsuffix(a.fi, b.fi);
	if (l < min(a.se, b.se))
		return x[a.fi + l] < x[b.fi + l];
	else {
		if (a.se != b.se) return a.se < b.se;
		return a.fi < b.fi;
	} 	
}
const int maxn = 1005;
ll dp[maxn][maxn];
ll sum[maxn][maxn];
int tu[maxn];
const ll mx = 2e18;
bool check(pi cur) {
	for (int i = 1; i <= n; i++) {
		if (cmp(mp(i, n - i + 1), cur)) tu[i] = n + 1;
		else {
			int l = i, r = n;
			while (l < r) {
				int mid = (l + r) >> 1;
				if (cmp(mp(i, mid + 1 - i), cur)) l = mid + 1;
				else r = mid;
			}
			tu[i] = l;
		} 
	//	cout << i << ' ' << tu[i] << ' ' << cmp(mp(1, 1), cur) << ' ' << cur.fi << ' ' << cur.se << endl;
	} 
	for (int i = 0; i <= m; i++) 
		for (int j = n + 1; j >= 1; j--) {
			if (i == 0) {
				if (j == n + 1) dp[i][j] = 1;
				else dp[i][j] = 0;
			}
			else {
				if (j == n + 1) dp[i][j] = 0;
				else dp[i][j] = sum[i - 1][tu[j] + 1];
			}
			sum[i][j] = (sum[i][j + 1] + dp[i][j]);
			if (sum[i][j] > mx) sum[i][j] = mx;
		}
//	cout << dp[m][1] << endl;
	return (dp[m][1] >= k);
}
int main() {
	cin >> n >> m >> k;
	scanf("%s", x + 1);
	len = n;
	for (int i = 1; i <= n; i++) s[i] = x[i] - 'a';
	initsuffix();
	vector<pi> u;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			u.pb(mp(i, j - i + 1));
	sort(u.begin(), u.end(), cmp);
//	for (auto s : u) cout << s.fi << ' ' << s.se << endl;
//	cout << check(u[1]);
//	while (1);
	int l = 0, r = u.size() - 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(u[mid + 1])) l = mid + 1;
		else r = mid;
	}
	for (int j = 0; j < u[l].se; j++)
		cout << x[u[l].fi + j];
	cout << endl;
	return 0;
}
/*
1 2
..
*/