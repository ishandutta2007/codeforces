/*
LANG: C++
ID: he.andr1
PROG: 350C
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

typedef pair<int, bool> sint; //int & sign
typedef pair<sint, sint> pss;

vector<string> ans;

int N;
pss pts[200000];

int numOp() {
	int ans = 0;
	for(int i = 0; i < N; i++) {
		ans += 2 * bool(pts[i].A.A);
		ans += 2 * bool(pts[i].B.A);
		ans += 2;
	}
	return ans;
}

void io(istream &in, ostream &out) {
	in >> N;
	for(int i = 0; i < N; i++) {
		in >> pts[i].A.A >> pts[i].B.A;
		if(pts[i].A.A < 0) {
			pts[i].A.A *= -1;
			pts[i].A.B = false;
		} else {
			pts[i].A.B = true;
		}
		if(pts[i].B.A < 0) {
			pts[i].B.A *= -1;
			pts[i].B.B = false;
		} else {
			pts[i].B.B = true;
		}
	}

	sort(pts, pts + N);
	out << numOp() << '\n';

	for(int i = 0; i < N; i++) {
		if(pts[i].B.A) {
			out << 1 << ' ';
			out << pts[i].B.A << ' ';
			out << (pts[i].B.B ? 'U' : 'D') << '\n';
		}
		if(pts[i].A.A) {
			out << 1 << ' ';
			out << pts[i].A.A << ' ';
			out << (pts[i].A.B ? 'R' : 'L') << '\n';
		}
		out << 2 << '\n';
		if(pts[i].A.A) {
			out << 1 << ' ';
			out << pts[i].A.A << ' ';
			out << (pts[i].A.B ? 'L' : 'R') << '\n';
		}
		if(pts[i].B.A) {
			out << 1 << ' ';
			out << pts[i].B.A << ' ';
			out << (pts[i].B.B ? 'D' : 'U') << '\n';
		}
		out << 3 << '\n';
	}
}

int main() {
	ifstream fin ("350C.in");
	if(fin.good()) {
		ofstream fout ("350C.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}