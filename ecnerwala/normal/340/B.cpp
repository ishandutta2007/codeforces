/*
LANG: C++
ID: he.andr1
PROG: 340B
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

template <class T> T cross(complex<T> a, complex<T> b) { return imag(a * conj(b)); }

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }

template <class T> void setmin(T &a, T b) { if(b < a) a = b; }
template <class T> void setmax(T &a, T b) { if(b > a) a = b; }

typedef complex<double> pt;

const int MAXN = 500;
int N;
pt P[MAXN];

void io(istream &in, ostream &out) {
	in >> N;
	for(int i = 0; i < N; i++) {
		in >> P[i].X >> P[i].Y;
	}

	double ans = 0;

	for(int i = 0; i < N; i++) {
		for(int j = i + 1; j < N; j++) {

			double l = 0, r = 0;

			for(int k = 0; k < N; k++) {
				//i x j + j x k + k x i = (j - i) x (k - i)
				double area = cross(P[j] - P[i], P[k] - P[i]);
				area /= 2;
				setmax(l, -area);
				setmax(r, area);
			}

			if(l > 0 && r > 0) setmax(ans, l + r);

		}
	}


	printf("%.15f\n", ans);
}

int main() {
	ifstream fin ("340B.in");
	if(fin.good()) {
		ofstream fout ("340B.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}