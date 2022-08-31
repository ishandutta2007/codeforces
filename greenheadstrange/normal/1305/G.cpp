#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
const int S = 262144;
int cnt[S];
int a[maxn];
int fa[S];

ll ans = 0;
int n;
int gfa(int x) {
	if (fa[x] == x) return x;
	return fa[x] = gfa(fa[x]);
}
void lk(int u, int v) {
	if (!cnt[u] || !cnt[v]) return ;
	if (gfa(u) == gfa(v)) return ;
	int us = gfa(u), vs = gfa(v);
	fa[us] = vs;
	ans += 1ll * (u + v) * (cnt[u] + cnt[v] - 1);
	cnt[u] = 1, cnt[v] = 1;
}
int main() {
	int test = 0;
	if (test) n = 200000;
	else 
		cin >> n;
	for (int i = 1; i <= n; i++) 
		if (test) a[i] = i;
		else scanf("%d", &a[i]);
	a[++n] = 0;
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--)
		cnt[a[i]]++;
	for (int i = 0; i < S; i++) fa[i] = i; 
	for (int i = S - 1; i >= 0; i--) {
		for (int j = i; 1; j = (j - 1) & i) {
			lk(j, i ^ j);
			if (j == 0) break;
			if ((i ^ j) > j) break;
		}
	}
	for (int i = 1; i <= n; i++) ans -= a[i];
	cout << ans << endl;
	if (test) cout << clock() << endl;
	return 0;
}