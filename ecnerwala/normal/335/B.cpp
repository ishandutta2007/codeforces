/*
LANG: C++
ID: he.andr1
PROG: 335B
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

const int MAXL = 200;
const int MAXN = 100000;
const int M = 26;

const int L = 50;

int N;
char S[MAXN];
vector<int> ind[M];

int maxLoc[MAXL];
int start[MAXL];

int prv[MAXN][MAXL];

string reconstruct(int len, int pos) { 
	string s;
	s.resize(len);
	int l = len / 2 + len % 2;
	for(; l > 0; pos = prv[pos][l], l--) {
		s[l - 1] = s[len - l] = char(S[pos] + 'a');
	}
	return s;
}

string go() {

	//for convenience
	for(int i = 0; i < N; i++) {
		S[i] -= 'a';
	}

	//create the reverse index for each letter
	for(int i = 0; i < N; i++) {
		ind[S[i]].push_back(i);
	}

	memset(maxLoc, -1, sizeof(maxLoc));
	
	maxLoc[0] = N;
	start[0] = -1;

	int maxLen = 0;
	int startPos = -1;

	for(int i = 0; i < N && maxLen < 2 * L; i++) {
		for(int l = L - 1; l >= 0 && maxLen < 2 * L; l--) {
			if(maxLoc[l] <= i) continue;
			//j is the matching location
			int j = *(lower_bound(ind[S[i]].begin(), ind[S[i]].end(), maxLoc[l]) - 1);
			//cerr << i << ' ' << j << ' ' << l + 1 << '\n';
			if(j > maxLoc[l + 1]) {
				maxLoc[l + 1] = j;
				start[l + 1] = i;
				prv[i][l + 1] = start[l];
				int len = 2 * l + 2;
				if(i == j) len--;
				if(len > maxLen) {
					maxLen = len;
					startPos = i;
				}
			}
		}
	}
	
	return reconstruct(maxLen, startPos);

}

void io(istream &in, ostream &out) {
	in >> S;
	N = strlen(S);
	out << go() << '\n';
}

int main() {
	ifstream fin ("335B.in");
	if(fin.good()) {
		ofstream fout ("335B.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}