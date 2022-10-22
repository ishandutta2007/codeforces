#include <bits/stdc++.h>
#define eb emplace_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define sorv(V) sort(allv(V))
#define univ(V) (V).erase(unique(allv(V)),(V).end())
using namespace std;

const int MAXN = 100055;
const int MAXQ = 100055;
const int MX = 131072;

struct NOD {
	NOD() { init(); }
	int s, l, r, g;

	void init() { s = 1; l = r = g = 0; }
	void on() { s = l = r = g = 1; }

	NOD operator + (const NOD &t) const {
		NOD ret;
		ret.s = s + t.s;
		ret.l = l == s ? l + t.l : l;
		ret.r = t.r == t.s ? t.r + r : t.r;
		ret.g = max({g, t.g, r + t.l});
		return ret;
	}
};

struct SEG {
	NOD nod[MX*2];

	void init() {
		for(int i = MX*2; i--;) nod[i].init();
	}

	void upd(int i) {
		i += MX; nod[i].on();
		for(i >>= 1; i; i >>= 1)
			nod[i] = nod[i<<1] + nod[i<<1|1];
	}

	int get(int s, int e) {
		NOD l, r;
		for(s += MX, e += MX; s <= e; s >>= 1, e >>= 1) {
			if(s&1) l = l + nod[s++];
			if(~e&1) r = nod[e--] + r;
		}
		return (l + r).g;
	}
} seg;

struct QRY {
	QRY(int idx, int s, int e)
		: idx(idx), s(s), e(e), m((s+e)>>1) {}
	int idx, s, e, m;

	bool operator < (const QRY &t) const {
		return m < t.m;
	}
};

vector<int> AV;

int A[MAXN], O[MAXN];
int B[MAXQ], C[MAXQ], D[MAXQ];

int Ans[MAXQ];
int N, Q;

void solve() {
	vector<QRY> QV;
	for(int i = 1; i <= Q; i++) QV.eb(i, 1, N);

	for(;;) {
		vector<QRY> V;
		int i = 1;
		
		for(auto &qry : QV) {
			for(; i <= qry.m; i++) seg.upd(O[i]);
			if(D[qry.idx] <= seg.get(B[qry.idx], C[qry.idx])) {
				if(qry.s == qry.m) Ans[qry.idx] = qry.m;
				else V.eb(qry.idx, qry.s, qry.m);
			} else if(qry.m+1 == qry.e) Ans[qry.idx] = qry.e;
			else V.eb(qry.idx, qry.m+1, qry.e);
		}

		swap(QV, V);
		if(QV.empty()) break;

		seg.init();
		sorv(QV);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> A[i];
		AV.eb(A[i]);
	}

	sorv(AV); univ(AV);
	for(int i = 1; i <= N; i++)
		A[i] = int(lower_bound(allv(AV), A[i]) - AV.begin());
	iota(O, O+N+1, 0); sort(O+1, O+N+1, [&](int a, int b) { return A[a] > A[b]; });
	
	cin >> Q;
	for(int i = 1; i <= Q; i++) cin >> B[i] >> C[i] >> D[i];

	solve();

	for(int i = 1; i <= Q; i++) cout << AV[A[O[Ans[i]]]] << '\n';
	return 0;
}