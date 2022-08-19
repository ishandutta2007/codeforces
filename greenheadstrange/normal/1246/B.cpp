#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int num[maxn], a[maxn], bpr[maxn], prs[maxn], prcnt = 0;
int main() {
	int n, k;
	ll ans = 0;
	cin >> n >> k;
	for (int i = 0; i < maxn; i++)
		bpr[i] = 1;
	for (int i = 2; i < maxn; i++) {
		if (!bpr[i]) continue;
		prs[prcnt++] = i;
		for (int j = 2; j * i < maxn; j++)
			bpr[i * j] = 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		int ns = a[i];
		ll nr = 1, nu = 1;
		for (int j = 0; j < maxn; j++) {
			int ns = prs[j];
			if (ns * ns > a[i]) break;
			int nt = 0;
			while (a[i] % ns == 0)
				nt++, a[i] /= ns;
			nt %= k;
			for (int i = 0; i < nt; i++)
				nu = nu * ns;
			if (nt)
				for (int r = 0; r < k - nt; r++) {
					if (nr >= maxn) break;
					nr = nr * ns;
				}
		} 
	
		if (a[i] != 1) {
			nu *= a[i];
			for (int r = 0; r < k - 1; r++) {
				if (nr >= maxn) break;
				nr = nr * a[i];
			}
		}	
	//	cout << a[i] << ' ' << nr << endl;
		if (nr < maxn) ans += num[nr];
		num[nu]++;
	}
	cout << ans << endl;
	return 0;
}