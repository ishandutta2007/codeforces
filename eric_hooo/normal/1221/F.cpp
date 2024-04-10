#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, int> pli;

const long long INF = 0x3f3f3f3f;

struct Node {
	int x, y, c;
	int val() const {return min(x, y);}
	int lav() const {return max(x, y);}
	bool operator < (const Node &A) const {
		return val() < A.val();
	}
}a[500010];

vector <int> all;

pli operator + (const pli &A, const long long &x) {
	return mp(A.fi + x, A.se);
}

struct Segment_tree {
	pli T[2100000];
	long long tag[2100000];
	void Build(int now, int l, int r) {
		tag[now] = 0;
		if (l == r) {
			T[now] = mp(-INF, all[l]);
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		T[now] = max(T[now << 1], T[now << 1 | 1]) + tag[now];
	}
	void Update(int now, int l, int r, int L, int R, int x) {
		if (l == L && r == R) {
			T[now] = T[now] + x, tag[now] += x;
			return ;
		}
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, x);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, x);
		else Update(now << 1, l, mid, L, mid, x), Update(now << 1 | 1, mid + 1, r, mid + 1, R, x);
		T[now] = max(T[now << 1], T[now << 1 | 1]) + tag[now];
	}
	pli Query() {return T[1];}
}seg;

int main () {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].c);
		all.push_back(a[i].x);
		all.push_back(a[i].y);
	}
	all.push_back(-1);
	sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
	for (int i = 0; i < n; i++) {
		a[i].x = lower_bound(all.begin(), all.end(), a[i].x) - all.begin();
		a[i].y = lower_bound(all.begin(), all.end(), a[i].y) - all.begin();
	}
	int N = (int)all.size() - 1;
	sort(a, a + n);
	seg.Build(1, 1, N);
	long long ans = 0; int L = 2000000000, R = 2000000000;
	int p = N;
	for (int i = n - 1; i >= 0; i--) {
		int j = i;
		while (j >= 0 && a[j].val() == a[i].val()) {
			seg.Update(1, 1, N, a[j].lav(), N, a[j].c);
			j--;
		}
		while (p >= a[i].val()) seg.Update(1, 1, N, p, p, INF - all[p]), p--;
		if (ans < seg.Query().fi + all[a[i].val()]) {
			ans = seg.Query().fi + all[a[i].val()];
			L = all[a[i].val()], R = seg.Query().se;
		}
		i = j + 1;
	}
	printf("%I64d\n", ans);
	printf("%d %d %d %d\n", L, L, R, R);
	return 0;
}