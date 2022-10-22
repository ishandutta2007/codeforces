#include <bits/stdc++.h>
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);
#define eb emplace_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define sorv(V) sort(allv(V))
#define univ(V) (V).erase(unique(allv(V)),(V).end())
#define rb(x) ((x)&(-(x)))
#define INF (0x3f3f3f3f)
using namespace std;
typedef pair<int, int> pii;
void fg(vector<int> G[], int a, int b) { G[a].eb(b); G[b].eb(a); }
static unsigned char str[22000022], *p=str;

const int MAXN = 300005;
const int MAXK = MAXN;
static int _int[MAXN*5], *_intp = _int;
inline int* newint(const unsigned int c) {
	_intp += c;
	return _intp - c;
}

struct BIT {
	int *d, n;

	void init(int _n) {
		n = _n + 2;
		d = newint(n);
		fill(d, d+n, INF);
	}
	void upd(int x, int r) {
		for(x++; x < n; x += rb(x))
			if(r < d[x]) d[x] = r;
	}
	int get(int x) {
		int r = INF; for(x++; x; x -= rb(x))
			if(d[x] < r) r = d[x];
		return r;
	}
};

struct NOD {
	NOD() : sy(INF), ey(-INF) {}
	BIT bitu, bitd;
	int x, sy, ey;

	void init() {
		int l = ey-sy+1;
		bitu.init(l);
		bitd.init(l);
	}
	void add(pii p) {
		x = p.first;
		if(p.second < sy) sy = p.second;
		if(ey < p.second) ey = p.second;
	}
	void add(int y, int d) {
		bitu.upd(y-sy, d-y);
		bitd.upd(ey-y, d+y);
	}
	int get(int y) {
		return min(bitu.get(y-sy) + y, bitd.get(ey-y) - y);
	}
} nod[MAXK];

vector<int> T[MAXN], G[MAXK];
int P[19][MAXK];
int C[19][MAXN], CY[19][MAXN];
int D[MAXK], prt[MAXK], cnt[MAXK];

pii A[MAXN];
int B[MAXN];

int N, Q, K;

int getidx(const pii &p) {
	int r = int(lower_bound(A+1, A+N+1, p) - A);
	return r <= N && p == A[r] ? r : 0;
}

void predfs(int i) {
	cnt[i] = 1;
	for(int v : G[i]) if(!cnt[v]) {
		predfs(v);
		cnt[i] += cnt[v];
	}
}

void cent(int &rt) {
	int N = cnt[rt];
	for(int hi, hc;;) {
		hi = hc = -1;
		for(int v : G[rt]) {
			if(N <= cnt[v] || cnt[v] <= hc) continue;
			hi = v; hc = cnt[v];
		}
		if(hc*2 <= N) break;
		cnt[rt] = N - hc;
		cnt[hi] = N;
		rt = hi;
	}
}

int makeCD(int i, int d) {
	cent(i);
	D[i] = d; P[d][i] = i;

	queue<int> PQ;
	for(int j = getidx({nod[i].x, nod[i].sy});; j++) {
		if(N < j || B[j] != i) break;
		PQ.push(j);
		C[d][j] = 0;
		CY[d][j] = A[j].second;
	}
	for(int j, c; !PQ.empty(); PQ.pop()) {
		j = PQ.front();
		c = C[d][j] + 1;
		for(int v : T[j]) {
			if(cnt[B[j]] < cnt[B[v]] || C[d][v] <= c) continue;
			PQ.push(v);
			C[d][v] = c;
			CY[d][v] = CY[d][j];
		}
	}

	for(int v : G[i]) if(cnt[v] < cnt[i]) {
		v = makeCD(v, d+1);
		prt[v] = i;
	}
	return i;
}

void makeTree() {
	K = B[1] = 1;
	nod[1].add(A[1]);
	for(int i = 2, j; i <= N; i++) {
		if(A[i-1].first != A[i].first || A[i-1].second != A[i].second-1) K++;
		else fg(T, i-1, i);
		B[i] = K;
		nod[K].add(A[i]);
		j = getidx({A[i].first-1, A[i].second});
		if(j) {
			fg(T, j, i);
			fg(G, B[j], B[i]);
		}
	}
	for(int i = 1; i <= K; i++) {
		nod[i].init();
		sorv(G[i]);
		univ(G[i]);
	}
}

void upd(int i) {
	for(int v = B[i], d = D[v]; v; v = prt[v], d--)
		nod[v].add(CY[d][i], C[d][i]);
}
int get(int i) {
	int r = INF;
	for(int v = B[i], d = D[v], t; v; v = prt[v], d--) {
		t = nod[v].get(CY[d][i]) + C[d][i];
		if(t < r) r = t;
	}
	return N <= r ? -1 : r;
}

int main() {
	fread(str, 1, 22000022, stdin);

	rf(N)
	for(int i = 1; i <= N; i++) { rf(A[i].first) rf(A[i].second) }
	sort(A+1, A+N+1);

	makeTree();
	predfs(1);
	fill(C[0], C[18]+MAXN, INF);
	makeCD(1, 0);

	rf(Q)
	for(int t, x, y; Q--;) {
		rf(t) rf(x) rf(y)
		x = getidx({x, y});
		if(1 == t) upd(x);
		else printf("%d\n", get(x));
	}
	return 0;
}