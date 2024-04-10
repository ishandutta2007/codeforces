#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int a[200010], L[200010][2], R[200010][2], ql[200010], qr[200010];
int up[200010], t1, dw[200010], t2, cnt[200010];
vector <int> seq[1000010];
int ans[200010];
vector <pii> all, qry;
int TOT;
set <int> S;

bool IsBig(const int &x, const int &y) {
	return a[x] > a[y];
}

bool IsSmall(const int &x, const int &y) {
	return a[x] < a[y];
}

void AddRng(int a, int b, int c, int d) {
	seq[TOT] = {a, b, c, d}, all.push_back(mp(a, TOT)), TOT++;
}

void AddRng(int a, int b, int c) {
	seq[TOT] = {a, b, c}, all.push_back(mp(a, TOT)), TOT++;
}

void Modify(int x, int v) {
	if (cnt[x] == 0) S.erase(x);
	cnt[x] += v;
	if (cnt[x] == 0) S.insert(x);
}

int main() {
	int n, q; scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	t1 = t2 = 0;
	for (int i = 1; i <= n; i++) {
		while (t1 && a[up[t1 - 1]] <= a[i]) t1--; L[i][0] = t1 ? up[t1 - 1] : -1;
		while (t2 && a[dw[t2 - 1]] >= a[i]) t2--; L[i][1] = t2 ? dw[t2 - 1] : -1;
		up[t1++] = i, dw[t2++] = i;
	}
	t1 = t2 = 0;
	for (int i = n; i >= 1; i--) {
		while (t1 && a[up[t1 - 1]] <= a[i]) t1--; R[i][0] = t1 ? up[t1 - 1] : -1;
		while (t2 && a[dw[t2 - 1]] >= a[i]) t2--; R[i][1] = t2 ? dw[t2 - 1] : -1;
		up[t1++] = i, dw[t2++] = i;
	}
	t1 = t2 = 0;
	for (int i = 1; i <= n; i++) S.insert(i);
	for (int i = 1; i <= n; i++) {
		while (t1 && a[up[t1 - 1]] < a[i]) Modify(up[t1 - 1], -1), t1--;
		while (t2 && a[dw[t2 - 1]] > a[i]) Modify(dw[t2 - 1], -1), t2--;
		int p1 = lower_bound(up, up + t1, i, IsBig) - up;
		int p2 = lower_bound(dw, dw + t2, i, IsSmall) - dw;
		if (p1 && p2) {
			set <int> :: iterator it = S.lower_bound(min(up[p1 - 1], dw[p2 - 1]));
			if (it != S.begin()) {
				it--;
				int P = *lower_bound(up, up + t1, *it), Q = *lower_bound(dw, dw + t2, *it);
				AddRng(*it, P, Q, i);
			}
		}
		up[t1++] = i, dw[t2++] = i, Modify(i, 2);
	}
	for (int i = 1; i <= n; i++) {
		if (L[i][0] != -1 && R[i][0] != -1) AddRng(L[i][0], i, R[i][0]);
		if (L[i][1] != -1 && R[i][1] != -1) AddRng(L[i][1], i, R[i][1]);
	}
	for (int i = 0; i < TOT; i++) sort(seq[i].begin(), seq[i].end()); 
	sort(all.rbegin(), all.rend());
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &ql[i], &qr[i]);
		qry.push_back(mp(ql[i], i));
	}
	sort(qry.rbegin(), qry.rend());
	int pos = 0, M3 = -1, M4 = -1;
	for (auto it : qry) {
		int id = it.se, l = ql[id], r = qr[id];
		while (pos < all.size() && all[pos].fi >= l) {
			int x = all[pos].se;
			if (seq[x].size() == 3) {
				if (M3 == -1 || seq[M3].back() > seq[x].back()) M3 = x;
			} else {
				if (M4 == -1 || seq[M4].back() > seq[x].back()) M4 = x;
			}
			pos++;
		}
		if (M4 != -1 && r >= seq[M4].back()) ans[id] = M4;
		else if (M3 != -1 && r >= seq[M3].back()) ans[id] = M3;
		else ans[id] = -1;
	}
	for (int i = 0; i < q; i++) {
		if (ans[i] == -1) printf("0\n");
		else {
			printf("%d\n", (int)seq[ans[i]].size());
			for (auto x : seq[ans[i]]) printf("%d ", x);
			printf("\n");
		}
	}
	return 0;
}