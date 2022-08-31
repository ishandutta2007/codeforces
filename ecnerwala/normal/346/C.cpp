/*
LANG: C++
ID: he.andr1
PROG: 346C
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

const int MAXN = 200000;

int N;
int X[MAXN];
int A, B;

int go() {
	sort(X, X + N);
	N = unique(X, X + N) - X;

	list<int> M(X, X + N);

	int cnt = 0;
	while(A > B) {
		int best = A - 1;
		for(list<int>::iterator i = M.begin(); i != M.end();) {
			int v = A - (A % (*i));
			if(v < B) {
				i = M.erase(i);
			} else {
				setmin(best, v);
				i++;
			}
		}
		A = best;
		cnt++;
	}
	return cnt;
}

void io(istream &in, ostream &out) {
	in >> N;
	for(int i = 0; i < N; i++) in >> X[i];
	in >> A >> B;
	out << go() << '\n';
}

int main() {
	ifstream fin ("346C.in");
	if(fin.good()) {
		ofstream fout ("346C.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}