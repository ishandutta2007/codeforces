/*
LANG: C++
ID: he.andr1
PROG: D
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<cstring>
#include<cassert>
#include<stack>
#include<list>
#include<cstdio>
#include<numeric>
#include<complex>
#include<string>
#include<map>

using namespace std;

#define DEBUG 1

#ifdef DEBUG
	#define ERR cerr
#else
	#define ERR if(true); else cerr
#endif

#define ITER(v, i) for(__typeof(v.begin()) i = v.begin(); i != v.end(); i++) 
#define X real()
#define Y imag()
#define A first
#define B second

typedef pair<int, int> pii;
typedef complex<int> pt;
typedef long long ll;

template <class T> T cross(complex<T> a, complex<T> b) { return imag(a * conj(b)); }

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }

template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }

template <class T> void setmin(T &a, T b) { if(b < a) a = b; }

template <class T> void setmax(T &a, T b) { if(b > a) a = b; }

const int MAXN = 505, MAXM = 10010;

int N, M;
pii E[MAXM];
int prefPar[MAXM][MAXN];
int suffPar[MAXM][MAXN];

int par[MAXN];

int getPar(int i) {
	if(par[i] == -1) return i;
	return par[i] = getPar(par[i]);
}

int merge(int a, int b) {
	int pa = getPar(a);
	int pb = getPar(b);
	if(pa != pb) par[pb] = pa;
}

void init() {
	memset(par, -1, sizeof(par));
}

void precomp() {
	ERR << "starting\n";
	init();
	memcpy(prefPar[0], par, sizeof(par));
	for(int i = 0; i < M; i++) {
		merge(E[i].A, E[i].B);
		memcpy(prefPar[i + 1], par, sizeof(par));
	}
	ERR << "pref done\n";
	init();
	memcpy(suffPar[M], par, sizeof(par));
	for(int i = M - 1; i >= 0; i--) {
		merge(E[i].A, E[i].B);
		memcpy(suffPar[i], par, sizeof(par));
	}
	ERR << "suff done\n";
}

//halfopen
int query(int l, int r) {
	memcpy(par, prefPar[l], sizeof(par));
	for(int i = 0; i < N; i++) {
		int p = suffPar[r][i];
		if(p >= 0) merge(i, p);
	}
	int out = 0;
	for(int i = 0; i < N; i++) {
		out += (par[i] == -1);
	}
	return out;
}

void io(istream &in, ostream &out) {
	in >> N >> M;
	for(int i = 0; i < M; i++) {
		in >> E[i].A >> E[i].B;
		E[i].A --, E[i].B--;
	}
	precomp();
	int K; in >> K;
	for(int i = 0; i < K; i++) {
		int l, r; in >> l >> r;
		l--;
		out << query(l, r) << '\n';
	}
}

int main() {
	ifstream fin ("D.in");
	if(fin.good()) {
		ofstream fout ("D.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}