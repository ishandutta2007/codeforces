/*
LANG: C++
ID: he.andr1
PROG: 360A
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

const int MAXN = 10000;
const int MAXM = 10000;

const ll INF = 1000000000;

int N, M;

ll D[MAXN];
ll A[MAXN];

int T[MAXM];
int L[MAXM];
int R[MAXM];
ll V[MAXM];

bool go() {
	for(int i = 0; i < N; i++) D[i] = 0, A[i] = INF;
	for(int j = 0; j < M; j++) {
		if(T[j] == 1) {
			for(int i = L[j]; i <= R[j]; i++) {
				D[i] += V[j];
			}
		} else {
			for(int i = L[j]; i <= R[j]; i++) {
				setmin(A[i], V[j] - D[i]);
			}
		}
	}
	for(int i = 0; i < N; i++) D[i] = 0;
	for(int j = 0; j < M; j++) {
		if(T[j] == 1) {
			for(int i = L[j]; i <= R[j]; i++) {
				D[i] += V[j];
			}
		} else {
			bool good = false;
			for(int i = L[j]; i <= R[j]; i++) {
				if(D[i] + A[i] == V[j]) {
					good = true; break;
				}
			}
			if(!good) return false;
		}
	}
	return true;
}

void io(istream &in, ostream &out) {
	in >> N >> M;
	for(int i = 0; i < M; i++) {
		in >> T[i] >> L[i] >> R[i] >> V[i];
		L[i]--, R[i]--;
	}
	if(go()) {
		out << "YES\n";

		for(int i = 0; i < N; i++) out << A[i] << ' '; out << '\n';
	} else {
		out << "NO\n";
	}
}

int main() {
	ifstream fin ("360A.in");
	if(fin.good()) {
		ofstream fout ("360A.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}