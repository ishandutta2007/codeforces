#include <bits/stdc++.h>
using namespace std;

char a[500010], b[500010];
char s[1000010];
char tmp[2000010];
int f[500010], g[500010];
int z[2000010];

void get_z(char *s, int n) {
	int L = 0, R = 0;
	for (int i = 1; i < n; i++) {
		if (R < i) {
			L = R = i;
			while (R < n && s[R] == s[R - L]) R++;
			z[i] = R - L, R--;
			continue;
		}
		if (i + z[i - L] - 1 < R) {
			z[i] = z[i - L];
			continue;
		}
		L = i;
		while (R < n && s[R] == s[R - L]) R++;
		z[i] = R - L, R--;
	}
}

struct Segment_tree {
	vector <int> T[2000000];
	vector <long long> sum[2000010];
	void merge(vector <int> &a, vector <long long> &sum, vector <int> &b, vector <int> &c) {
		int l = 0, r = 0;
		while (l < b.size() && r < c.size()) {
			int x;
			if (b[l] < c[r]) x = b[l], l++;
			else x = c[r], r++;
			a.push_back(x);
			if (sum.size()) sum.push_back(sum.back() + x);
			else sum.push_back(x);
		}
		while (l < b.size()) {
			int x = b[l]; l++;
			a.push_back(x);
			if (sum.size()) sum.push_back(sum.back() + x);
			else sum.push_back(x);
		}
		while (r < c.size()) {
			int x = c[r]; r++;
			a.push_back(x);
			if (sum.size()) sum.push_back(sum.back() + x);
			else sum.push_back(x); 
		}
	}
	void Build(int now, int l, int r) {
		if (l == r) {
			T[now].push_back(g[l]);
			sum[now].push_back(g[l]);
			return ; 
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		merge(T[now], sum[now], T[now << 1], T[now << 1 | 1]);
	}
	long long Query(int now, int l, int r, int L, int R, int x) {
		if (l == L && r == R) {
			int pos = lower_bound(T[now].begin(), T[now].end(), x) - T[now].begin();
			return sum[now].back() - (pos ? sum[now][pos - 1] : 0) - 1ll * (T[now].size() - pos) * x;
		}
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R, x);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R, x);
		return Query(now << 1, l, mid, L, mid, x) + Query(now << 1 | 1, mid + 1, r, mid + 1, R, x); 
	}
}seg;

int main () {
	int n, m; scanf("%d%d", &n, &m);
	scanf("%s%s%s", a, b, s);
	for (int i = 0; i < m; i++) {
		tmp[i] = s[i];
	}
	for (int i = 0; i < n; i++) {
		tmp[m + i] = a[i];
	}
	get_z(tmp, n + m);
	for (int i = 0; i < n; i++) {
		f[i] = min(z[m + i], m - 1);
	}
	reverse(tmp, tmp + m);
	for (int i = 0; i < n; i++) {
		tmp[m + n - i - 1] = b[i];
	}
	get_z(tmp, n + m);
	for (int i = 0; i < n; i++) {
		g[i] = min(z[m + n - i - 1], m - 1);
	}
	seg.Build(1, 0, n - 1);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int old = ans;
		ans += seg.Query(1, 0, n - 1, i, min(n - 1, i + m - 2), m - 1 - f[i]);
	}
	printf("%lld\n", ans);
	return 0;
}