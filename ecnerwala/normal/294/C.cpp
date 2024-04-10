/*
LANG: C++
ID: he.andr1
PROG: C
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

const int MAXN = 1010, MAXM = MAXN;

const ll MOD = 1000000007;

int N, M;
int ind[MAXM];

map<ll, ll> mem;

ll inv(ll i) {
	if(mem.count(i)) return mem[i];
	for(ll j = 1; ; j += MOD) {
		if(j % i == 0) {
			return mem[i] = j / i;
		}
	}
}

ll go() {
	ll out = 1;
	for(int i = 1; i <= N - M; i++) {
		out *= i;
		out %= MOD;
	}
	int prev = 0;
	sort(ind, ind + M);
	ind[M] = N + 1;
	for(int i = 0; i <= M; i++) {
		int n = ind[i];
		int c = n - prev - 1;
		prev = n;
		for(int j = 1; i != 0 && i != M && j < c; j++) {
			out *= 2;
			out %= MOD;
		}
		for(int j = 1; j <= c; j++) {
			out *= inv(j);
			out %= MOD;
		}
	}
	return out;
}

void io(istream &in, ostream &out) {
	in >> N >> M;
	for(int i = 0; i < M; i++) in >> ind[i];
	out << go() << '\n';
}

int main() {
	ifstream fin ("C.in");
	if(fin.good()) {
		ofstream fout ("C.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}