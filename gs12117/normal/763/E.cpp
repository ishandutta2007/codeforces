#include<stdio.h>
#include<algorithm>
int n, m, p;
int edge[500100][2];
int ct[101000][8];
int dt[101000][8];
int uft[101000];
const int bsz = 300;
struct qry {
	int l, r, idx;
	bool operator<(const qry&z)const {
		return r < z.r;
	}
};
qry ql[101000];
int ans[101000];
int uftf(int x) {
	if (x == uft[x])return x;
	return uft[x] = uftf(uft[x]);
}
int suft[101000];
int schk[101000];
int qn;
int suftf(int x) {
	if (schk[x] != qn) {
		schk[x] = qn;
		suft[x] = uftf(x);
	}
	if (x == suft[x])return x;
	return suft[x] = suftf(suft[x]);
}
int main() {
	scanf("%d%d", &n, &p);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &edge[i][0], &edge[i][1]);
		edge[i][0]--;
		edge[i][1]--;
		if (edge[i][0] > edge[i][1]) {
			int t = edge[i][0];
			edge[i][0] = edge[i][1];
			edge[i][1] = t;
		}
		ct[edge[i][0]][edge[i][1] - edge[i][0]] = 1;
		dt[edge[i][1]][edge[i][1] - edge[i][0]] = 1;
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &ql[i].l, &ql[i].r);
		ql[i].l--;
		ql[i].idx = i;
	}
	std::sort(ql, ql + q);
	for (int i = 0; i <= n; i++) {
		uft[i] = i;
	}
	for (int i = 0; i < q; i++) {
		if (ql[i].l + bsz >= ql[i].r) {
			qn = i + 1;
			int cnt = 0;
			for (int j = ql[i].l; j < ql[i].r; j++) {
				for (int k = 1; k <= 5; k++) {
					if (dt[j][k] == 1 && j - k >= ql[i].l) {
						int pa = suftf(j);
						int pb = suftf(j - k);
						if (pa != pb) {
							suft[pa] = pb;
							cnt++;
						}
					}
				}
			}
			ans[ql[i].idx] = ql[i].r - ql[i].l - cnt;
		}
	}
	for (int si = 0; si < n; si += bsz) {
		int ei = si + bsz;
		int ed = ei;
		for (int i = 0; i <= n; i++) {
			uft[i] = i;
		}
		int cnt = 0;
		for (int i = 0; i < q; i++) {
			if (ql[i].l >= si&&ql[i].l < ei&&ql[i].l + bsz < ql[i].r) {
				qn = i + 1;
				while (ed < ql[i].r) {
					int j = ed;
					for (int k = 1; k <= 5; k++) {
						if (dt[j][k] == 1 && j - k >= ei) {
							int pa = uftf(j);
							int pb = uftf(j - k);
							if (pa != pb) {
								uft[pa] = pb;
								cnt++;
							}
						}
					}
					ed++;
				}
				int scnt = cnt;
				int sd = ei;
				while (sd > ql[i].l) {
					sd--;
					int j = sd;
					for (int k = 1; k <= 5; k++) {
						if (ct[j][k] == 1 && j + k < ql[i].r) {
							int pa = suftf(j);
							int pb = suftf(j + k);
							if (pa != pb) {
								suft[pa] = pb;
								scnt++;
							}
						}
					}
				}
				ans[ql[i].idx] = ql[i].r - ql[i].l - scnt;
			}
		}
	}
	for (int i = 0; i < q; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}