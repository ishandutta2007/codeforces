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
#define A first
#define B second

typedef pair<int, int> pii;
typedef complex<int> pt;
typedef long long ll;

template <class T> T cross(complex<T> a, complex<T> b) { return imag(a * conj(b)); }

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }

template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }

template <class T> void setmin(T &a, T b) { if(b < a) a = b; }

template <class T> void setmax(T &a, T b) { if(b > a) a = b; }

const int MAXN = 100010;

int N, M;
int deg[MAXN];

string go() {
	if(M == N) {
		bool good = true;
		for(int i = 0; good && i < N; i++) {
			if(deg[i] != 2) good = false;
		}
		if(good) return "ring";
		else return "unknown";
	} else if(M == N - 1) {
		int n1 = 0, n2 = 0, nA = 0;
		bool good = true;
		for(int i = 0; good && i < N; i++) {
			if(deg[i] == 1) n1++;
			else if(deg[i] == 2) n2++;
			else if(deg[i] == N - 1) nA++;
			else good = false;
		}
		if(!good) return "unknown";
		else if(n1 == 2 && n2 == N - 2) return "bus";
		else if(n1 == N - 1 && nA == 1) return "star";
		else return "unknown";
	} else return "unknown";
}

void io(istream &in, ostream &out) {
	in >> N >> M;
	memset(deg, 0, sizeof(deg));
	for(int i = 0; i < M; i++) {
		int a, b;
		in >> a >> b;
		deg[a - 1] ++;
		deg[b - 1]++;
	}
	out << go() << ' ' << "topology" << '\n';
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