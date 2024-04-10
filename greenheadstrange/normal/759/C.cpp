#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define db double
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll ksm(ll a, ll b, ll c) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1, c);
   ns = ns * ns % c;
   if (b & 1) ns = ns * a % c;
   return ns;
}
struct ST {
	int l, r;
	ST *ch[2];
	int lz, mn;
}p[maxn << 1], *root;
int stcnt = 0;
void bdtree(ST *a, int l, int r) {
	a->l = l, a->r = r, a->lz = a->mn = 0;
	if (l == r) return;
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), 
	bdtree(a->ch[1], mid + 1, r);
}
void upd(ST *a) {
	a->mn = min(a->ch[0]->mn, a->ch[1]->mn);
}
void actlz(ST *a, int lz) {
	a->lz += lz, a->mn += lz;
}
void pushdown(ST *a) {
	actlz(a->ch[0], a->lz);
	actlz(a->ch[1], a->lz);
	a->lz = 0;
}
void push(ST *a, int l, int r, int lz)
{
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
int q(ST *a, int num) {
	if (a->l == a->r) return a->l; 
	pushdown(a);
	if (a->ch[1]->mn < num) return q(a->ch[1], num);
	else return q(a->ch[0], min(num, a->ch[1]->mn));
}
int tr[maxn];
int main() {
	int m;
	scanf("%d", &m);
	root = &p[stcnt++];
	bdtree(root, 0, m);
	int s = 0;
	for (int i = 1; i <= m; i++) {
		int p, t;
		scanf("%d%d", &p, &t);
		if (t == 0) push(root, p, m, -1), s--;
		else {
			scanf("%d", &tr[p]);
			push(root, p, m, 1), s++;
		}
		if (root->mn >= s) printf("-1\n");
		else printf("%d\n", tr[q(root, s) + 1]);
	}
	return 0;
}
/*
5 4
0 1 2 3

*/