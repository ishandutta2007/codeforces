#include <bits/stdc++.h>
#define ll long long
#define maxn 105 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
db cn[maxn];
db p[maxn];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int s;
		scanf("%d", &s);
		p[i] = 1.0 * s / 100;
		cn[i] = 1 - p[i];
	//	cout << i << ' ' << p[i] << ' ' << cn[i] << endl;
	}
	db ans = n;
	db tsum = 1;
	for (int i = 1; i <= n; i++)
		tsum *= (1 - cn[i]);
	for (int j = 1; j <= 100000000; j++) {
		if (j % 1000 == 0 && 1.0 * clock() / CLOCKS_PER_SEC > 1.8) break;
		db mx = 0;
		ans += 1 - tsum;
		int pl = 0;
		for (int k = 1; k <= n; k++) {
			db e = 1 - cn[k] * (1 - p[k]);
			db f = 1 - cn[k];
			db cur = e / f;
			if (cur > mx) mx = cur, pl = k;
		}
	//	cout << j << ' ' << tsum << ' ' << mx << ' ' << pl << endl;
		tsum *= mx;
		cn[pl] *= (1 - p[pl]);
	}
	printf("%.10lf\n", ans);
	return 0;
}