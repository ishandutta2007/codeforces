#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353 
#define db double
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int fa[maxn], col[maxn];
int gfa(int a) {
	if(fa[a ] == a) return a;
	int ns = gfa(fa[a]);
	if (col[fa[a]]) col[a] ^= 1;
	fa[a] = ns;
	return ns;
} 
int n, m;
vi eg[maxn];
int r[maxn];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &r[i]);
	}
	for (int j = 1; j <= m; j++) {
		int x;
		scanf("%d", &x);
		for(int k = 0; k < x; k++) {
			int l;
			scanf("%d", &l);
			eg[l].pb(j);
		}
	}
	for (int i = 1; i <= m; i++) {
		col[i] = 0, fa[i] = i;
	}
	int fl = 1;
	for (int i = 1; i <= n; i++) {
		int u = eg[i][0], v = eg[i][1], c = r[i] ^ 1;
		int ufa = gfa(u), vfa = gfa(v), nl = col[u] ^ col[v] ^ c;
		if (ufa == vfa)
			if (nl) fl = 0;
			else continue;
		fa[ufa] = vfa, col[ufa] = nl;
	}
	if (fl) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
/*
1 2
..
*/