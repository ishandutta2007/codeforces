#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) if(0) printf("qwq")
#endif

const int maxN = 500000 + 233;
const int maxK = 50 + 2;
int n, m, k, q;
int x[maxN], y[maxN], e[maxN], c[maxN];
int p[maxN], ip[maxN];
bool cmp(int x, int y) {
	return e[x] < e[y] || (e[x] == e[y] && x < y);
}
int cnt = 0, id[maxN][maxK];
int pa[maxN * 2], sz[maxN * 2], rel[maxN * 2];
pii findset(int x) {
	if(pa[x] == x) {
		return pii(x, 0);
	} else {
		pii r = findset(pa[x]);
		r.second ^= rel[x];
		return r;
	}
}
bool bad(int x, int y) {
	pii px = findset(x), py = findset(y);
	if(px.first == py.first && px.second == py.second) return true;
	else return false;
}
bool merge(int x, int y, int &fx, int &fy) {
	pii px = findset(x), py = findset(y);
	fx = px.first, fy = py.first;
	if(fx == fy) {
		assert(px.second != py.second);
		return false;
	} else {
		if(sz[fx] < sz[fy]) swap(fx, fy);
		pa[fy] = fx; sz[fx] += sz[fy]; rel[fy] = 1 ^ px.second ^ py.second;
		return true;
	}
}
void cut(int fx, int fy) {
	pa[fy] = fy; sz[fx] -= sz[fy]; rel[fy] = 0;
}

#define lson (o << 1)
#define rson (lson | 1)
int ql, qr; pii qp;
vector<pii> a[maxN * 4];
void cover(int o, int L, int R) {
	if(ql <= L && R <= qr) {
		a[o].push_back(qp);
	} else {
		int M = (L + R) >> 1;
		if(ql <= M) cover(lson, L, M);
		if(M < qr) cover(rson, M + 1, R);
	}
}
void cover(int L, int R, pii p) {
	ql = L; qr = R; qp = p;
	eprintf("cover [%d, %d] with (%d, %d)\n", L, R, p.first, p.second);
	if(L <= R) {
		cover(1, 1, q);
	}
}

void solve(int o, int L, int R) {
	vector<pii> op;
//	eprintf("Merge of [%d, %d]\n", L, R);
	for(int i = 0; i < (int)a[o].size(); ++i) {
		pii e = a[o][i]; int fx, fy;
		if(!merge(e.first, e.second, fx, fy)) continue;
		op.push_back(pii(fx, fy));
	}
	if(L == R) {
		int &nx = id[x[e[L]]][c[L]], &ny = id[y[e[L]]][c[L]];
		if(nx == 0) nx = ++cnt;
		if(ny == 0) ny = ++cnt;
		int till = e[p[ip[L] + 1]] == e[L] ? p[ip[L] + 1] - 1 : q;
		eprintf("On %d we check (%d, %d)\n", L, nx, ny);
		eprintf("next qid = %d, e = %d\n", p[ip[L] + 1], e[p[ip[L] + 1]]);
		if(bad(nx, ny)) {
			printf("NO\n");
			int i = p[ip[L] - 1];
			if(e[i] == e[L]) {
				cover(L + 1, till, pii(id[x[e[i]]][c[i]], id[y[e[i]]][c[i]]));
				p[ip[L]] = i;
			} else {
				p[ip[L]] = 0;
			}
		} else {
			printf("YES\n");
			cover(L + 1, till, pii(nx, ny));
		}
	} else {
		int M = (L + R) >> 1;
		solve(lson, L, M);
		solve(rson, M + 1, R);
	}
	reverse(op.begin(), op.end());
	for(int i = 0; i < (int)op.size(); ++i) {
		pii e = op[i];
		cut(e.first, e.second);
	}
}

int main() {
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for(int i = 1; i <= m; ++i) {
		scanf("%d %d", &x[i], &y[i]);
	}
	for(int i = 1; i <= q; ++i) {
		scanf("%d %d", &e[i], &c[i]);
		p[i] = i;
	}
	sort(p + 1, p + q + 1, cmp);
	for(int i = 1; i <= q; ++i) ip[p[i]] = i;
	for(int i = 1; i <= q * 2; ++i) pa[i] = i, rel[i] = 0, sz[i] = 1;
	solve(1, 1, q);
	return 0;
}