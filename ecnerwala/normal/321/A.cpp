/*
LANG: C++
ID: he.andr1
PROG: 321A
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

int N;
string S;
int X, Y;

bool go() {
	ll sx = 0, sy = 0;
	for(int i = 0; i < N; i++) {
		switch(S[i]) {
			case 'U': sy++;
					  break;
			case 'D': sy--;
					  break;
			case 'L': sx--;
					  break;
			case 'R': sx++;
					  break;
		}
	}
	cerr << sx << ' ' << sy << '\n' << '\n';
	ll cx = X, cy = Y;
	cerr << X << ' ' << Y << '\n';
	if(X == 0 && Y == 0) return true;
	for(int i = 0; i < N; i++) {
		switch(S[i]) {
			case 'U': cy--;
					  break;
			case 'D': cy++;
					  break;
			case 'L': cx++;
					  break;
			case 'R': cx--;
					  break;
		}
		cerr << cx << ' ' << cy << '\n';
		if(sx == 0) {
			if(cx != 0) continue;
		} else {
			if((sx * cx < 0) || (cx % sx != 0)) continue;
		}
		if(sy == 0) {
			if(cy != 0) continue;
		} else {
			if((sy * cy < 0) || (cy % sy != 0)) continue;
		}
		cerr << '\n';
		
		if(cx * sy == cy * sx) return true;
	}
	return false;
}

void io(istream &in, ostream &out) {
	in >> X >> Y >> S;
	N = S.size();
	out << (go() ? "Yes" : "No") << '\n';
}

int main() {
	ifstream fin ("321A.in");
	if(fin.good()) {
		ofstream fout ("321A.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}