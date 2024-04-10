#include <bits/stdc++.h>
#define ll long long
#define maxn 400005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int fa[maxn], sz[maxn];
int gfa(int a) {
	if (fa[a] == a) return a;
	return fa[a] = gfa(fa[a]);
}
int c[maxn];
int cc(int a) {
	return a * (a - 1) / 2;
}
int main() {
	int n, m, k; 
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) sz[i] = 1, fa[i] = i;
	for (int i = 1; i <= k; i++) scanf("%d", &c[i]);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		int uf = gfa(u), vf = gfa(v);
		if (uf == vf) continue;
		fa[uf] = vf, sz[vf] += sz[uf];
	}
	int tt = n, mx = 0, s = 0;
	for (int i = 1; i <= k; i++) {
		int ns = sz[gfa(c[i])];
		mx = max(mx, ns), tt -= ns, s += cc(ns);
	}
	s -= cc(mx), mx += tt, s += cc(mx);
	s -= m;
	cout << s << endl;
	return 0;
}