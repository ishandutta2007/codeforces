/*
LANG: C++
ID: he.andr1
PROG: 339C
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

int M;
bool has[10];
vector<int> ans;

bool go(int start) {
	int diff = start;
	int prev = start;
	ans[0] = start;
	for(int i = 1; i < M; i++) {
		bool found = false;
		for(int j = diff + 1; !found && j <= 10; j++) {
			if(has[j - 1] && j != prev) {
				found = true;
				ans[i] = j;
				prev = j;
				diff = j - diff;
				//cerr << j << ' ' << diff << '\n';
			}
		}
		if(!found) return false;
	}
	return true;
}

void io(istream &in, ostream &out) {
	string s;

	in >> s;
	for(int i = 0; i < 10; i++) has[i] = (s[i] == '1');

	in >> M;
	ans.resize(M);
	for(int s = 1; s <= 10; s++) {
		if(has[s - 1] && go(s)) {
			out << "YES" << '\n';
			for(int i = 0; i < M; i++) out << ans[i] << ' ';
			out << '\n';
			return;
		}
		//cerr << '\n';
	}
	out << "NO" << '\n';
}

int main() {
	ifstream fin ("339C.in");
	if(fin.good()) {
		ofstream fout ("339C.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}