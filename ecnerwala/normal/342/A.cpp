/*
LANG: C++
ID: he.andr1
PROG: 342A
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

int N;
int A[200000];
int num[10];

bool isGood() {
	return (num[5] == 0 && num[7] == 0 && num[1] == N / 3 && num[2] >= num[4] && num[6] >= num[3] && num[2] - num[4] == num[6] - num[3]);
}

void io(istream &in, ostream &out) {
	in >> N;
	memset(num, 0, sizeof(num));
	for(int i = 0; i< N; i++) {
		int a; in >> a; num[a]++;
	}
	if(isGood()) {
		while(num[4]) {
			out << 1 << ' ' << 2 << ' ' << 4 << '\n';
			num[1] --;
			num[2] --;
			num[4] --;
		}
		while(num[3]) {
			out << 1 << ' ' << 3 << ' ' << 6 << '\n';
			num[1] --;
			num[3] --;
			num[6] --;
		}
		while(num[1]) {
			out << 1 << ' ' << 2 << ' ' << 6 << '\n';
			num[1] --;
			num[2] --;
			num[6] --;
		}
	} else {
		out << -1 << '\n';
	}
}

int main() {
	ifstream fin ("342A.in");
	if(fin.good()) {
		ofstream fout ("342A.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}