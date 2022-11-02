#include <bits/stdc++.h>
using std::cin;
typedef long long LL;

const int maxN = 100000 + 233;
const LL P = 1000000007;
int n, m;
LL a[maxN];
void mul(LL A[2][2], LL B[2][2], LL R[2][2]) {
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			R[i][j] = 0;
	for(int i = 0; i < 2; ++i)
		for(int k = 0; k < 2; ++k)
			for(int j = 0; j < 2; ++j)
				R[i][j] += A[i][k] * B[k][j];
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			R[i][j] %= P;
}
void mul(LL A[2][2], LL B[2], LL R[2]) {
	for(int i = 0; i < 2; ++i) R[i] = 0;
	for(int i = 0; i < 2; ++i)
		for(int k = 0; k < 2; ++k)
			R[i] += A[i][k] * B[k];
	for(int i = 0; i < 2; ++i) R[i] %= P;
}
LL Q[70][2][2];
void power(LL A[2], LL b) {
	LL T[2];
	for(int i = 0; (1ll << i) <= b; ++i) if(b >> i & 1) {
		T[0] = T[1] = 0;
		mul(Q[i], A, T);
		A[0] = T[0]; A[1] = T[1];
	}
}

#define lson (o << 1)
#define rson (o << 1 | 1)
LL V[maxN * 4][2], tag[maxN * 4];
void maintain(int o, int L, int R) {
	if(L < R) {
		for(int i = 0; i < 2; ++i)
			V[o][i] = (V[lson][i] + V[rson][i]) % P;
	} else {
		assert(false);
	}
}
void apply(int o, LL t) {
	power(V[o], t); tag[o] += t;
}
void pushdown(int o, int L, int R) {
	if(L < R && tag[o]) {
		apply(lson, tag[o]);
		apply(rson, tag[o]);
		tag[o] = 0;
	}
}
void build(int o, int L, int R) {
	if(L == R) {
		V[o][0] = 0;
		V[o][1] = 1;
		apply(o, a[L]);
	} else {
		int M = (L + R) >> 1;
		build(lson, L, M);
		build(rson, M + 1, R);
		maintain(o, L, R);
	}
}
int ql, qr;
LL qans;
void query(int o, int L, int R) {
	if(ql <= L && R <= qr) {
		qans = (qans + V[o][0]) % P;
	} else {
		int M = (L + R) >> 1;
		pushdown(o, L, R);
		if(ql <= M) query(lson, L, M);
		if(qr > M) query(rson, M + 1, R);
	}
}
void modify(int o, int L, int R) {
	if(ql <= L && R <= qr) {
		apply(o, qans);
	} else {
		int M = (L + R) >> 1;
		pushdown(o, L, R);
		if(ql <= M) modify(lson, L, M);
		if(qr > M) modify(rson, M + 1, R);
		maintain(o, L, R);
	}
}
#undef lson
#undef rson

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	Q[0][0][0] = 1; Q[0][0][1] = 1;
	Q[0][1][0] = 1; Q[0][1][1] = 0;
	for(int k = 1; k < 70; ++k) mul(Q[k - 1], Q[k - 1], Q[k]);
	build(1, 1, n);
	for(int kase = 1; kase <= m; ++kase) {
		int op; cin >> op;
		if(op == 1) {
			cin >> ql >> qr >> qans;
			modify(1, 1, n);
		} else if(op == 2) {
			cin >> ql >> qr;
			qans = 0;
			query(1, 1, n);
			printf("%lld\n", qans);
		} else {
			assert(false);
		}
	}
	return 0;
}