#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::sort; using std::min; using std::max;
#include <vector>
using std::vector;
#include <set>
using std::set;
#include <map>
using std::map;
#include <queue>
using std::queue; using std::priority_queue;
#include <utility>
using std::pair;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);

bool chmin(LL &a, const LL &b) { return a > b ? a = b, true : false; }
bool chmax(LL &a, const LL &b) { return a < b ? a = b, true : false; }

const int maxN = 100000000;
const int maxX = 8, maxK = 8;
const int maxQ = 25;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;

int x, k, n, q;
int c[maxK + 1];
map<int, int> Q;

const int maxS = 70 + 5;
LL G[maxS][maxS];
int H[maxS][maxS];
int M[1 << maxK], T[1 << maxK];
set<int> S;
int tot = 0;

struct Matrix {
	int n;
	LL __val__[maxS][maxS];
	LL *operator [](const int &i) {
		return __val__[i];
	}
	Matrix(int n = 0) {
		this->n = n;
		memset(__val__, 0x3f, sizeof(__val__));
	}
	friend Matrix operator * (Matrix A, Matrix B) {
		int n = A.n;
		Matrix R(n);
		for(int i = 0; i < n; ++i)
			for(int k = 0; k < n; ++k)
				for(int j = 0; j < n; ++j)
					chmin(R[i][j], A[i][k] + B[k][j]);
		return R;
	}
}P[30];
struct Vector {
	int n;
	LL __val__[maxS];
	LL &operator [](const int &i) {
		return __val__[i];
	}
	Vector(int n = 0) {
		this->n = n;
		memset(__val__, 0x3f, sizeof(__val__));
	}
	friend Vector operator ^ (Vector A, int b) {
		int n = A.n;
		for(int t = 0; (1 << t) <= b; ++t) if(b & (1 << t)) {
			Vector B(n);
			for(int i = 0; i < n; ++i) {
				for(int k = 0; k < n; ++k) {
					chmin(B[i], P[t][i][k] + A[k]);
				}
			}
			A = B;
		}
		return A;
	}
};

void initialize() {
	cin >> x >> k >> n >> q;
	for(int i = 1; i <= k; ++i) cin >> c[i];
	Q.clear();
	for(int i = 0; i < q; ++i) {
		int p, wp;
		cin >> p >> wp;
		Q[p] = wp;
	}
	if(!Q.count(n - x)) Q[n - x] = 0;
	
	memset(G, 0x3f, sizeof(G));
	memset(M, 0, sizeof(M));
	memset(T, 0, sizeof(T));
	S.clear();
	queue<int> Q;
	while(!Q.empty()) Q.pop();
	T[M[(1 << x) - 1] = tot++] = (1 << x) - 1;
	S.insert((1 << x) - 1);
	Q.push((1 << x) - 1);
	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
		for(int i = 1; i <= k; ++i) {
			LL t = 0;
			int v;
			if(u & 1) {
				if(u & (1 << i)) continue;
				v = (u >> 1) | (1 << (i - 1));
				t = c[i];
			} else if(i == 1) {
				v = u >> 1;
			} else {
				break;
			}
			if(!S.count(v)) {
				S.insert(v);
				T[M[v] = tot++] = v;
				Q.push(v);
			}
			G[M[u]][M[v]] = t;
#ifdef DEBUG
			assert(T[M[u]] == u); assert(T[M[v]] == v);
			assert(__builtin_popcount(u) == x);
			assert(__builtin_popcount(v) == x);
			printf("Edge added : %d -> %d (denoted as %d -> %d) w = %lld\n", u, v, M[u], M[v], G[M[u]][M[v]]);
#endif
			H[M[u]][M[v]] = (u & 1) ? i : 0;
		}
	}
	P[0] = Matrix(tot);
	for(int i = 0; i < tot; ++i)
		for(int j = 0; j < tot; ++j)
			P[0][j][i] = G[i][j]; // maybe ?
	for(int i = 1; i < 30; ++i) P[i] = P[i-1] * P[i-1];
}

/*
8 8 99999999 0
823562482 665935846 999310213 662531201 386917462 143294697 428773698 513889666
*/

Vector f, g;
LL solve() {
	f = Vector(tot); g = Vector(tot);
	vector<int> qs; qs.clear();
	for(pii p : Q) qs.push_back(p.first); // ordered
	std::reverse(qs.begin(), qs.end());
	int nowi = 1;
	f[M[(1 << x) - 1]] = 0;
	while(qs.size() && qs.back() < n - x + 1) {
		int p = qs.back();
		if(nowi < p - k) {
//			printf("matrix : forward by %d\n", p - k - nowi);
			g = f ^ (p - k - nowi);
			f = g;
			nowi = p - k;
		}
		for(int i = nowi; i < p; ++i) {
			g = Vector(tot);
			for(int j = 0; j < tot; ++j) {
				for(int k = 0; k < tot; ++k) if(G[j][k] < INF) {
					LL extra = 0;
					if(H[j][k] && Q.count(i + H[j][k])) extra = Q[i + H[j][k]];
					chmin(g[k], f[j] + G[j][k] + extra);
				}
			}
			f = g;
		}
//		printf("simple : forward by %d\n", p - nowi);
		nowi = std::max(nowi, p);
		qs.pop_back();
	}
	for(int i = nowi; i < n - x + 1; ++i) {
		g = Vector(tot);
		for(int j = 0; j < tot; ++j) {
			for(int k = 0; k < tot; ++k) if(G[j][k] < INF) {
				LL extra = 0;
				if(H[j][k] && Q.count(i + H[j][k])) extra = Q[i + H[j][k]];
				chmin(g[k], f[j] + G[j][k] + extra);
			}
		}
		f = g;
	}
//	printf("last : forward by %d\n", n - x + 1 - nowi);
	return f[M[(1 << x) - 1]];
}

int main() {
	initialize();
	printf("%lld\n", solve());
	return 0;
}