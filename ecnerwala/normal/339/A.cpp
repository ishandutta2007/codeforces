/*
LANG: C++
ID: he.andr1
PROG: 339A
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

void io(istream &in, ostream &out) {
	string s; in >> s;
	int num[4];

	memset(num, 0, sizeof(num));
	
	for(int i = 0; i < s.size(); i += 2) {
		num[s[i] - '0'] ++;
	}
	
	int i = 0;
	for(int v = 1; v <= 3; v++){
		for(int k = 0; k < num[v]; k++, i += 2) {
			s[i] = char(v + '0');
		}
	}

	out << s << '\n';
}

int main() {
	ifstream fin ("339A.in");
	if(fin.good()) {
		ofstream fout ("339A.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}