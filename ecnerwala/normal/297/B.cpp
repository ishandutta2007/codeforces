/*
LANG: C++
ID: he.andr1
PROG: B
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<cstring>
#include<cassert>
#include<stack>
#include<list>
#include<cstdio>
#include<numeric>
#include<complex>
#include<string>
#include<map>

using namespace std;

#define DEBUG 1

#ifdef DEBUG
	#define ERR cerr
#else
	#define ERR if(true); else cerr
#endif

#define ITER(v, i) for(__typeof(v.begin()) i = v.begin(); i != v.end(); i++) 
#define X real()
#define Y imag()

typedef pair<int, int> pii;
typedef complex<int> pt;
typedef long long ll;

template <class T> T cross(complex<T> a, complex<T> b) { return imag(a * conj(b)); }

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }

template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }

template <class T> void setmin(T &a, T b) { if(b < a) a = b; }

template <class T> void setmax(T &a, T b) { if(b > a) a = b; }

const int MAXN = 100010;

int N, M, K;
int A[MAXN], B[MAXN];

bool go() {
	if(N > M) return true;
	sort(A, A + N);
	sort(B, B + M);
	for(int i = 1; i <= N; i++) {
		if(A[N - i] > B[M - i]) return true;
	}
	return false;
}

void io(istream &in, ostream &out) {
	in >> N >> M >> K;
	for(int i = 0; i < N; i++) in >> A[i];
	for(int i = 0; i < M; i++) in >> B[i];
	if(go()) cout << "YES\n";
	else cout << "NO\n";
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