/*
LANG: C++
ID: he.andr1
PROG: 358A
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

const int MAXN = 2000;
int N;
int X[MAXN];

bool crosses(int a1, int a2, int b1, int b2) {
	if(a2 < a1) swap(a1, a2);
	if(b2 < b1) swap(b1, b2);
	if(b1 < a1) swap(a1, b1), swap(a2, b2);
	return (a1 < b1 && b1 < a2 && a2 < b2);
}

bool go() {
	for(int i = 0; i + 1 < N; i ++) {
		for(int j = i + 2; j + 1 < N; j++) {
			if(crosses(X[i], X[i + 1], X[j], X[j + 1])) return true;
		}
	}
	return false;
}

void io(istream &in, ostream &out) {
	in >> N;
	for(int i = 0; i < N; i++) in >> X[i];
	out << (go() ? "yes" : "no") << '\n';
}

int main() {
	ifstream fin ("358A.in");
	if(fin.good()) {
		ofstream fout ("358A.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}