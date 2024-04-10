#include <bits/stdc++.h>
#define ll long long
#define maxn 55 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int r[20];
int l;
ll dp[20][2][2]; //    
ll work() {
	// l - 1 0  

/*	for (int j = 0; j < 16; j++)
		cout << r[j] << ' ';
	cout << endl;
*/	ll res = 0;
	for (int mx = 0; mx <= 15; mx++) {	
		memset(dp, 0, sizeof(dp));
		for (int j = 0; j < 16; j++)
			for (int k = 0; k < 2; k++)
				for (int s = 0; s < 2; s++)
					for (int u = 0; u <= mx; u++) {
						int nj = j - 1, nk = k, ns = s;
						if (u == mx) nk = 1;
						if (u < r[j]) ns = 1;
						if (u > r[j] && !ns) continue;
						if (j == mx / 4 && ((u & (1 << (mx % 4))) == 0)) continue;
						if (nj == -1) {
						    if(nk) dp[j][k][s]++;
						    
						}
						else dp[j][k][s] += dp[nj][nk][ns];
					}	
	//	cout << mx << ' ' << dp[15][0][0] << endl;
		res += dp[15][0][0];	
	}
	return res;
}
char inp[20];
void read() {
	scanf("%s", inp);
	l = strlen(inp);
	memset(r, 0, sizeof(r));
	for (int j = 0; j < l; j++) {
		if (inp[j] <= '9')
			r[l - 1 - j] = inp[j] - '0';
		else r[l - 1 - j] = inp[j] - 'a' + 10;
	}
	
}
int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		ll ans = 0;
		read();
		r[0]--;
		for (int i = 0; i < 15; i++)
			if (r[i] < 0) r[i] += 16, r[i + 1]--;
		if (r[15] >= 0) ans -= work();
		read();
		ans += work();
		printf("%lld\n", ans);
	}
	return 0;
}