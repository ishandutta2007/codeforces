/*
LANG: C++
ID: he.andr1
PROG: 342C
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

const double RT3 = 1.7320508075688772935274463415059;
int R, H;

int maxNum() {
	H *= 2, R *= 2;
	int ans = 2 * (H / R);
	H %= R;
	if(H >= RT3 * (R / 2)) ans += 3;
	else if(H >= R / 2) ans += 2;
	else ans++;
	return ans;
}

void io(istream &in, ostream &out) {
	in >> R >> H;
	out << maxNum() << '\n';
}

int main() {
	ifstream fin ("342C.in");
	if(fin.good()) {
		ofstream fout ("342C.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}