/*
LANG: C++
ID: he.andr1
PROG: C
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

const int MAXN = 200000;
typedef pair<ll, ll> pll;
typedef pll line;

int N;
ll A[MAXN], B[MAXN];
ll dp[MAXN];
vector<line> lines;
vector<double> inter;

double intersect(line a, line b) {
    double out = b.B - a.B;
    out /= -(b.A - a.A);
    return out;
}

ll eval(line l, ll pt) {
    return l.A * pt + l.B;
}

void io(istream &in, ostream &out) {
	in >> N;
    for(int i = 0; i < N; i++) in >> A[i];
    for(int i = 0; i < N; i++) in >> B[i];
    for(int i = 0; i < N; i++) {
        if(i == 0) dp[i] = 0;
        else {
            int loc = lower_bound(inter.begin(), inter.end(), (double)A[i]) - inter.begin();
            dp[i] = eval(lines[loc], A[i]);
        }
        line l = line(B[i], dp[i]);
        while(!inter.empty() && intersect(l, lines.back()) <= inter.back()) {
            lines.pop_back();
            inter.pop_back();
        }
        if(!lines.empty()) inter.push_back(intersect(l, lines.back()));
        lines.push_back(l);
    }
    out << dp[N - 1] << '\n';
}

int main() {
	ifstream fin ("C.in");
	if(fin.good()) {
		ofstream fout ("C.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}