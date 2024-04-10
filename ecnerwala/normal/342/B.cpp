/*
LANG: C++
ID: he.andr1
PROG: 342B
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

const int MAXN = 200000, MAXM = 200000;

int N, M;
int S, F;
int dir;
int T[MAXM];
pii R[MAXM];

void stay() {
	cout << 'X';
}

void advance() {
	S += dir;
	cout << ((dir == 1) ? 'R' : 'L');
}

bool inRange(int a, pii r) {
	return r.A <= a && a <= r.B;
}

void go() {
	dir = (F - S) / abs(F - S);
	int m = 0;
	for(int i = 1; S != F; i++) {
		if(T[m] == i) {
			if(inRange(S, R[m]) || inRange(S + dir, R[m])) stay();
			else advance();
			m++;
		} else {
			advance();
		}
	}
}

void io(istream &in, ostream &out) {
	in >> N >> M >> S >> F;
	for(int i = 0; i < M; i++) {
		in >> T[i] >> R[i].A >> R[i].B;
	}

	go();
	cout << '\n';
}

int main() {
	ifstream fin ("342B.in");
	if(fin.good()) {
		ofstream fout ("342B.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}