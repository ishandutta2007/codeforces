/*
LANG: C++
ID: he.andr1
PROG: A
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

const int MAXK = 200;

int K;
bool v[MAXK][MAXK][MAXK];

bool go() {
    if(K % 2 == 1) return false;
    for(int i = 0; i < K; i++) {
        for(int j = 0; j < K / 2; j++) {
            for(int k = j; k < K - j; k++) {
                v[i][j][k] = (i + j) % 2;
                v[i][K - j - 1][k] = (i + j) % 2;
                v[i][k][j] = (i + j) % 2;
                v[i][k][K - j - 1] = (i + j) % 2;
            }
        }
    }
    return true;
}

void io(istream &in, ostream &out) {
	in >> K;
    if(go()){
        for(int i = 0; i < K; i++) {
            for(int j = 0; j < K; j++) {
                for(int k = 0; k < K; k++) {
                    out << (v[i][j][k] ? 'b' : 'w');
                }
                out << '\n';
            }
            if(i + 1 < K) out << '\n';
        }
    } else {
        out << -1 << '\n';
    }
}

int main() {
	ifstream fin ("A.in");
	if(false && fin.good()) {
		ofstream fout ("A.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}