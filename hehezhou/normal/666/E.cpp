#include <bits/stdc++.h>
using namespace std;
struct node {
	int ls, rs;
	pair <int, int> value;
} t[100010 * 150];
inline void pushup(int x) {
	t[x].value = max(t[t[x].ls].value, t[t[x].rs].value);
}
int tot;
inline int merge(int a, int b, int l, int r) {
	if(!a || !b) return a | b;
	if(l == r) return t[++tot].value.first = t[a].value.first + t[b].value.first, t[tot].value.second = -l, tot;
	int ans = ++tot;
	int mid = l + r >> 1;
	t[ans].ls = merge(t[a].ls, t[b].ls, l, mid);
	t[ans].rs = merge(t[a].rs, t[b].rs, mid + 1, r);
	pushup(ans);
	return ans;
}
inline void add(int &now, int l, int r, int x, int k) {
	if(!now) now = ++tot;
	if(l == r) t[now].value.first = k, t[now].value.second = -l;
	else {
		int mid = l + r >> 1;
		if(x <= mid) add(t[now].ls, l, mid, x, k);
		else add(t[now].rs, mid + 1, r, x, k);
		pushup(now);
	}
}
inline pair <int, int> getMax(int x, int l, int r, int L, int R) {
	if(x == 0 || l > R || L > r) return make_pair(-1, -1);
	if(L <= l && r <= R) return t[x].value;
	int mid = l + r >> 1;
	return max(getMax(t[x].ls, l, mid, L, R), getMax(t[x].rs, mid + 1, r, L, R));
}
struct data {
	int son[26], parent, len;
	inline int& operator [] (int x) {
		return son[x];
	}
} a[1500010];
int last = 1, cnt = 1;
int n, m, q;
char s[1500010];
inline int add(int c) {
	int p = last;
	if(a[p][c] && a[a[p][c]].len == a[p].len + 1) return last = a[p][c];
	int np = last = ++cnt;
	a[np].len = a[p].len + 1;
	for(; p && a[p][c] == 0; p = a[p].parent) a[p][c] = np;
	if(p == 0) return a[np].parent = 1, last;
	int q = a[p][c];
	if(a[q].len == a[p].len + 1) return a[np].parent = q, last;
	int nq = ++cnt;
	a[nq] = a[q];
	a[nq].len = a[p].len + 1;
	a[q].parent = a[np].parent = nq;
	for(; a[p][c] == q; p = a[p].parent) a[p][c] = nq;
	return last;
}
int pos[500010], rt[1500010], f[1500010][21];
int buc[1500010], ls[1500010];
int main() {
	scanf("%s", s + 1);
	m = strlen(s + 1);
	for(int i = 1; i <= m; i++) pos[i] = add(s[i] - 'a');
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		last = 1;
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		for(int j = 1; j <= len; j++) add(rt[add(s[j] - 'a')], 1, n, i, 1);
	}
	for(int i = 1; i <= cnt; i++) f[i][0] = a[i].parent;
	for(int i = 1; i <= 20; i++)
		for(int j = 1; j <= cnt; j++) f[j][i] = f[f[j][i - 1]][i - 1];
	for(int i = 1; i <= cnt; i++) buc[a[i].len]++;
	for(int i = 1; i <= 500000; i++) buc[i] += buc[i - 1];
	for(int i = 1; i <= cnt; i++) ls[buc[a[i].len]--] = i;
	for(int i = cnt; i > 1; i--) {
		rt[a[ls[i]].parent] = merge(rt[a[ls[i]].parent], rt[ls[i]], 1, n);
	}
	scanf("%d", &q);
	cerr << getMax(rt[2], 1, 1, 1, 1).first << endl;
	for(int i = 1; i <= q; i++) {
		int l, r, pl, pr;
		scanf("%d%d%d%d", &l, &r, &pl, &pr);
		int now = pos[pr];
		for(int i = 20; i >= 0; i--) if(a[f[now][i]].len >= pr - pl + 1) now = f[now][i];
		pair <int, int> ans = getMax(rt[now], 1, n, l, r);
		cerr << now << endl;
		if(ans.first == -1) printf("%d 0\n", l);
		else printf("%d %d\n", -ans.second, ans.first);
	}
	return 0;
}