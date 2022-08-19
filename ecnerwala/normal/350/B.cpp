/*
LANG: C++
ID: he.andr1
PROG: 350B
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

int N;
bool hotel[MAXN];
int par[MAXN];
int outDeg[MAXN];

int len(int st) {
	int l = 1;
	while(par[st] >= 0 && outDeg[par[st]] == 1) {
		l++, st = par[st];
	}
	return l;
}

void io(istream &in, ostream &out) {
	in >> N;
	for(int i = 0; i < N; i++) {
		in >> hotel[i];
	}
	for(int i = 0; i < N; i++) {
		in >> par[i]; par[i] --;
		if(par[i] >= 0) outDeg[par[i]] ++;
	}
	int maxL = 0;
	int st = -1;
	for(int i = 0; i < N; i++) {
		if(hotel[i]) {
			int l = len(i);
			if(l > maxL) {
				st = i;
				maxL = l;
			}
		}
	}
	out << maxL << '\n';
	stack<int> s;
	s.push(st);
	while(par[st] >= 0 && outDeg[par[st]] == 1) {
		st = par[st];
		s.push(st);
	}
	while(!s.empty()) {
		out << (s.top() + 1);
		s.pop();
		if(s.empty()) out << '\n';
		else out << ' ';
	}
}

int main() {
	ifstream fin ("350B.in");
	if(fin.good()) {
		ofstream fout ("350B.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}