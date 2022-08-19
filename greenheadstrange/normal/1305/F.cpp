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
int n;
ll a[maxn];
const int S = 1000007;
bool bpr[S];
int prs[S], prcnt = 0;
ll ans;
void work(ll t) {
	ll nr = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] < t) nr += t - a[i];
		else {
			ll cu = a[i] % t;
			nr += min(cu, t - cu);
		}
	}
	ans = min(ans, nr);
}
void chk(ll t) {
	if (t == 0) return;
	for (int i = 0; i < prcnt; i++) {
		if (t % prs[i] == 0) {
			while (t % prs[i] == 0) t /= prs[i];
			if (i > 10) work(prs[i]);
		}
	}
	if (t != 1) work(t);
}
int main() {
	for (int i = 0; i < S; i++) bpr[i] = 1;
	for (int i = 2; i < S; i++) {
		if (!bpr[i]) continue;
		prs[prcnt++] = i;
		for (int j = 2; j * i < S; j++)
			bpr[i * j] = 0;
	}
	srand((unsigned long long)(new char));
	cin >> n;
	ans = n;
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i = 0; i <= 15; i++) 
		work(prs[i]);
	while (1.0 * clock() / CLOCKS_PER_SEC < 1.8) {
		int pl = (rand() & 32767) * 32768 + (rand() & 32767);
		pl = pl % n + 1;
		chk(a[pl]), chk(a[pl] + 1), chk(a[pl] - 1);
	}
	cout << ans << endl;
	return 0;
}