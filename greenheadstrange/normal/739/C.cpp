#include <bits/stdc++.h>
#define ll long long
#define maxn 300005 /*rem*/
#define db double
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
struct ST {
	int l, r;
	ST *ch[2];
	ll lz;
	int ex[2], ans, h[2]; // s :  h : hill ex :  
	ll s[2];
}p[maxn << 1], *root;
int x[maxn];
int stcnt = 0;
int n;
int l(ST *a) {
	return a->r - a->l + 1;
}
void upd(ST *a) {
	a->ans = max(a->ch[0]->ans, a->ch[1]->ans);
	for (int i = 0; i < 2; i++)
		a->ex[i] = a->ch[i]->ex[i], 
		a->s[i] = a->ch[i]->s[i], 
		a->h[i] = a->ch[i]->h[i];
	// ex :   
	if (a->ch[0]->s[1] < a->ch[1]->s[0]) {
		if (a->ex[1] == l(a->ch[1])) a->ex[1] += a->ch[0]->ex[1]; 
		int ls = a->ch[0]->r - a->ch[0]->ex[1] + 1, rs = a->ch[1]->l + a->ch[1]->h[0] - 1;
		if (ls == a->l) a->h[0] = rs - ls + 1;
		if (rs == a->r) a->h[1] = rs - ls + 1;
		a->ans = max(a->ans, rs - ls + 1);
	} 
	if (a->ch[0]->s[1] > a->ch[1]->s[0]) {
		if (a->ex[0] == l(a->ch[0])) a->ex[0] += a->ch[1]->ex[0]; 
		int ls = a->ch[0]->r - a->ch[0]->h[1] + 1, rs = a->ch[1]->l + a->ch[1]->ex[0] - 1;
		if (ls == a->l) a->h[0] = rs - ls + 1;
		if (rs == a->r) a->h[1] = rs - ls + 1;
		a->ans = max(a->ans, rs - ls + 1);
	}
}
void bdtree(ST *a, int l, int r) {
	a->l = l, a->r = r;
	if (l == r) {
		a->lz = 0, a->ex[0] = a->ex[1] = a->h[0] = a->h[1] = 1, a->ans =1;
		a->s[0] = a->s[1] = x[l];
		return ;
	}
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), bdtree(a->ch[1], mid + 1, r);
	upd(a);
}
void actlz(ST *a, ll lz) {
	a->s[0] += lz, a->s[1] += lz, a->lz += lz;
}
void pushdown(ST *a) {
	if (a->lz)
		actlz(a->ch[0], a->lz), 
		actlz(a->ch[1], a->lz), 
		a->lz = 0;
}
void push(ST *a, int l, int r, int lz) {
//	cout << l << ' ' << r << ' ' << a->l << ' ' << a->r << endl;
	if (a->l == l && a->r == r) {
		actlz(a, lz);
		return ;
	}
	pushdown(a);
	int mid = (a->l + a->r) >> 1;
	if (r <= mid) push(a->ch[0], l, r, lz);
	else if (l > mid) push(a->ch[1], l, r, lz);
	else push(a->ch[0], l, mid, lz), push(a->ch[1], mid + 1, r, lz);
	upd(a);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
	root = &p[stcnt++];
	bdtree(root, 1, n);
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int l, r, d;
		scanf("%d%d%d", &l, &r, &d);
		push(root, l, r, d);
		printf("%d\n", root->ans);
	}
	return 0;
}
/*
5 4
0 1 2 3

*/