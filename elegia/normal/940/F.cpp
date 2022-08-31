#include <cmath>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <vector>

using namespace std;

struct Query {
	int l, r, t, id;

	Query() {}

	Query(int l, int r, int t, int id) : l(l), r(r), t(t), id(id) {}

	bool operator<(const Query& rhs) const {
		return t < rhs.t;
	}
};

const int N = 100010, N13 = 50;

int n, q, opCnt, bSize, bCnt;
int a[N], ans[N];
int opt[N], x[N], y[N];
int opX[N], opS[N], opT[N];
int c[N * 2], cc[N];
int uniq[N * 2];
vector<Query> qr[N13][N13];

void rmv(int x);
void add(int x);

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= q; ++i)
		scanf("%d%d%d", &opt[i], &x[i], &y[i]);

	bSize = pow(n, 2. / 3);
	bCnt = (n + bSize - 1) / bSize;
	memcpy(uniq, a, sizeof(a));
	for (int i = 1; i <= q; ++i)
		if (opt[i] == 1) {
			qr[(x[i] - 1) / bSize + 1][(y[i] - 1) / bSize + 1].emplace_back(x[i], y[i], opCnt, i - opCnt);
		} else {
			++opCnt;
			uniq[n + opCnt] = y[i];
		}
	sort(uniq + 1, uniq + n + opCnt + 1);
	int* lst = unique(uniq + 1, uniq + n + opCnt + 1);
	for (int i = 1; i <= n; ++i)
		a[i] = lower_bound(uniq + 1, lst, a[i]) - uniq;
	opCnt = 0;
	for (int i = 1; i <= q; ++i)
		if (opt[i] == 2) {
			++opCnt;
			y[i] = lower_bound(uniq + 1, lst, y[i]) - uniq;
			opX[opCnt] = x[i];
			opS[opCnt] = a[x[i]];
			opT[opCnt] = y[i];
			a[x[i]] = y[i];
		}
	for (int i = q; i; --i)
		if (opt[i] == 2) {
			a[x[i]] = opS[opCnt];
			--opCnt;
		}
	opCnt = count(opt + 1, opt + q + 1, 2);
	int lP = 1, rP = 0, tP = 0;
	cc[0] = n;
	for (int i = 1; i <= bCnt; ++i)
		for (int j = 1; j <= bCnt; ++j) {
			sort(qr[i][j].begin(), qr[i][j].end());
			for (auto&& qry: qr[i][j]) {
				while (lP < qry.l)
					rmv(a[lP++]);
				while (lP > qry.l)
					add(a[--lP]);
				while (rP < qry.r)
					add(a[++rP]);
				while (rP > qry.r)
					rmv(a[rP--]);
				while (tP < qry.t) {
					++tP;
					if (lP <= opX[tP] && opX[tP] <= rP)
						rmv(a[opX[tP]]);
					a[opX[tP]] = opT[tP];
					if (lP <= opX[tP] && opX[tP] <= rP)
						add(opT[tP]);
				}
				while (tP > qry.t) {
					if (lP <= opX[tP] && opX[tP] <= rP)
						rmv(a[opX[tP]]);
					a[opX[tP]] = opS[tP];
					if (lP <= opX[tP] && opX[tP] <= rP)
						add(opS[tP]);
					--tP;
				}
				int curAns = 1;
				while (cc[curAns])
					++curAns;
				ans[qry.id] = curAns;
			}
		}
	for (int i = 1; i <= q - opCnt; ++i)
		printf("%d\n", ans[i]);
	return 0;
}

void add(int x) {
	--cc[c[x]];
	++cc[++c[x]];
}

void rmv(int x) {
	--cc[c[x]];
	++cc[--c[x]];
}