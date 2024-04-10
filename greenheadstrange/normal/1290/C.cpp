#include <bits/stdc++.h>
#define ll long long
#define maxn 300005 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int fa[maxn], cnt[2][maxn];
int col[maxn];
int gfa(int a) {
	if (fa[a] == a) return a;
	int ns = gfa(fa[a]);
	col[a] ^= col[fa[a]];
	return fa[a] = ns;
} 
int ans = 0;
int cal(int u) {
	return min(cnt[0][u], cnt[1][u]);
}
void u(int x, int y, int tp) {
//	cout << x << ' ' << y << ' ' << tp << endl;
	int ufa = gfa(x), vfa = gfa(y);
	if (ufa > vfa) swap(ufa, vfa);
	int nc = col[x] ^ col[y] ^ tp;
	if (ufa == vfa) return;
	else {
		ans -= cal(ufa), ans -= cal(vfa);
		fa[ufa] = vfa;
		for (int j = 0; j < 2; j++)
			cnt[j][vfa] += cnt[j ^ nc][ufa];
		col[ufa] = nc;
		ans += cal(vfa);
	}
}
int n, k;
vi eg[maxn];
char s[maxn];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k + 1; i++)
		col[i] = 0, fa[i] = i, cnt[0][i] = 1;
	scanf("%s", s + 1);
	for (int i = 1; i <= k; i++) {
		int c;
		scanf("%d", &c);
		for (int j = 1; j <= c; j++) {
			int t;
			scanf("%d", &t);
			eg[t].pb(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (eg[i].size() == 1) 
			eg[i].pb(k + 1);
		if (eg[i].size() == 2) {
//			cout << s[i] << ' ' << s[i] - '0' << endl;
			u(eg[i][0], eg[i][1], (s[i] - '0') ^ 1);
		}
		int nans = ans;
		assert(fa[k + 1] == k + 1);
		nans -= cal(k + 1);
		nans += cnt[1][k + 1];
		printf("%d\n", nans);
	}
	return 0;
}
/*
1 2
..
*/