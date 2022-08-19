/*
LANG: C++
ID: he.andr1
PROG: 329A
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

const int MAXN = 200;

int N;
bool E[MAXN][MAXN];
int r[MAXN], c[MAXN];

void go() {
	memset(r, -1, sizeof(r));
	memset(c, -1, sizeof(c));
	int er = N, ec = N;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(!E[i][j]) {
				if(r[i] == -1) {
					er --;
					r[i] = j;
				}
				if(c[j] == -1) {
					ec --;
					c[j] = i;
				}
			}
		}
	}
	if(er == 0) {
		for(int i = 0; i < N; i++) {
			cout << (i + 1) << ' ' << (r[i] + 1) << '\n';
		}
	} else if(ec == 0) {
		for(int i = 0; i < N; i++) {
			cout << (c[i] + 1) << ' ' << (i + 1) << '\n';
		}

	} else {
		cout << -1 << '\n';
	}
}

void io(istream &in, ostream &out) {
	in >> N;
	for(int i = 0; i < N; i++) {
		string s; in >> s;
		for(int j = 0; j < N; j++) E[i][j] = (s[j] == 'E');
	}

	go();
}

int main() {
	ifstream fin ("329A.in");
	if(fin.good()) {
		ofstream fout ("329A.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}