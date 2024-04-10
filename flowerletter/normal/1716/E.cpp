#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int N = 1 << 18, S = 1 << 9;
int n, B, q, a[N], cur, ls[N << 1], rs[N << 1];


struct Node {
	i64 sum, lmx, rmx, mx;
	friend Node operator + (Node x, Node y) {
		return {x.sum + y.sum, max(x.lmx, x.sum + y.lmx), max(y.rmx, y.sum + x.rmx), max({x.mx, y.mx, x.rmx + y.lmx})};
	}
};
vector<Node> t[N << 1];
void up2(int u, int dep) {
	for(int s = 0; s < 1 << dep - 1; s ++) {
		t[u][s] = t[ls[u]][s] + t[rs[u]][s];
		t[u][s | 1 << dep - 1] = t[rs[u]][s] + t[ls[u]][s];
	}
}
void up1(int u, int dep) {
	Node x, y;
	if(dep == B) x = t[ls[u]][cur], y = t[rs[u]][cur];
	else x = t[ls[u]][0], y = t[rs[u]][0];
	if(cur >> dep & 1) t[u][0] = y + x;
	else t[u][0] = x + y;
}
void build(int u, int dep) {
	if(!dep) {
		static int l = 0;
		t[u].resize(1);
		t[u][0] = {a[l], max(0, a[l]), max(0, a[l]), max(0, a[l])};
		l ++;
		return ;
	}
	ls[u] = u << 1;
	rs[u] = u << 1 | 1;
	build(ls[u], dep - 1), build(rs[u], dep - 1);
	if(dep < B) {
		t[u].resize(1 << dep);
		up2(u, dep);
	}
	else {
		t[u].resize(1);
		up1(u, dep);
	}
}
void upd1(int u, int dep, int k) {
	if(dep == k) {
		swap(ls[u], rs[u]);
		up1(u, dep);
		return ;
	}
	upd1(ls[u], dep - 1, k), upd1(rs[u], dep - 1, k);
	up1(u, dep);
}
void upd2(int u, int dep) {
	if(dep == B) {
		up1(u, dep);
		return ;
	}
	upd2(ls[u], dep - 1), upd2(rs[u], dep - 1);
	up1(u, dep);
}
int main() {
// 	freopen("in.txt", "r", stdin);
// 	freopen("out.txt", "w", stdout);
	int st = clock();
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n; 
	B = n;
	for(int i = 0; i < 1 << n; i ++) cin >> a[i];
	build(1, n);
	cin >> q;
	for(int i = 0; i < q; i ++) {
		int k;
		cin >> k;
		k ++;
		if(k >= B) upd1(1, n, k);
		else cur ^= 1 << k - 1, upd2(1, n);
		cout << t[1][0].mx << '\n';
	}
	cerr << 1.0 * (clock() - st) / CLOCKS_PER_SEC << '\n';
	return 0;
}