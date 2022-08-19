/*
LANG: C++
ID: he.andr1
PROG: B
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

const int MAXN = 2000;

int N, M;
bool banX[MAXN], banY[MAXN];

int go() {
    int ans = 0;
    if(N == 0) return 0;
    for(int i = 0; i + i < N; i++) {
        int j = N - 1 - i;
        if(i == j) {
            ans += (!banX[i] || !banY[i]);
        } else {
            int x1 = !banX[i], x2 = !banX[j], y1 = !banY[i], y2 = !banY[j];
            int numPoss = x1 + x2 + y1 + y2;
            ans += numPoss;
        }
    }
    return ans;
}

void io(istream &in, ostream &out) {
	in >> N >> M;
    N -= 2;
    for(int i = 0; i < M; i++) {
        int x, y;
        in >> x >> y;
        x -= 2, y -= 2;
        banX[x] = true;
        banY[y] = true;
    }
    out << go() << '\n';
}

int main() {
	ifstream fin ("B.in");
	if(fin.good()) {
		ofstream fout ("B.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}