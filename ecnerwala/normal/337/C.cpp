/*
LANG: C++
ID: he.andr1
PROG: 337C
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<list>
#include<string>
#include<cstring>
#include<cassert>
#include<numeric>
#include<complex>
#include<cmath>
#include<ctime>

using namespace std;

#define DEBUG 1

#ifdef DEBUG
	#define ERR cerr
#else
	#define ERR if(true); else cerr
#endif

#define ITER(i, v) for(__typeof(v.begin()) i = v.begin(); i != v.end(); i++) 
#define X real()
#define Y imag()
#define A first
#define B second

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<int> pt;

template <class T> T cross(complex<T> a, complex<T> b) { return imag(a * conj(b)); }

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }

template <class T> void setmin(T &a, T b) { if(b < a) a = b; }
template <class T> void setmax(T &a, T b) { if(b > a) a = b; }

const ll MOD = 1000000009;

ll N, M, K;

ll go() {
	if((N / K) <= (N - M)) return M;
	ll numCyc = (N / K) - (N - M);
	cerr << numCyc << '\n';
	ll out = 1;
	//out = K * 2^numCyc + ... + K * 2
	//= K * 2 * (2^(numCyc) - 1)
	for(ll pow2 = 2, exp = 1; exp <= numCyc; exp *= 2, pow2 *= pow2, pow2 %= MOD) {
		if(numCyc & exp) out *= pow2, out %= MOD;
	}
	cerr << out << '\n'; // out = 2 ^ numCyc 
	out --;
	out *= K;
	out %= MOD;
	out *= 2;
	out %= MOD;
	out += M - K * numCyc;
	out %= MOD;
	return out;
}

void io(istream &in, ostream &out) {
	in >> N >> M >> K;
	out << go() << '\n';
}

int main() {
	ifstream fin ("337C.in");
	if(fin.good()) {
		ofstream fout ("337C.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}