/*
LANG: C++
ID: he.andr1
PROG: 346B
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

string s1, s2;

int L;
string V;
int F[MAXL];

void fail() {
	F[0] = -1, F[1] = 0;
	int pos = 2;
	int cnd = 0;
	while(pos < L) {
		if(V[pos - 1] == V[cnd]) {
			F[pos] = cnd + 1;
			pos++, cnd++;
		} else if(cnd == 0) {
			F[pos] = 0;
			pos++;
		} else {
			cnd = F[cnd];
		}
	}
}

int dp[MAXL][MAXL][MAXL];
int prv[MAXL][MAXL][MAXL];

const int JDOWN = -1;
const int IDOWN = -2;

string go() {
	memset(dp, 0, sizeof(dp));
	memset(prv, -1, sizeof(dp));
	for(int i = 0; i <= s1.size(); i++) {
		for(int j = 0; j <= s2.size(); j++) {
			for(int k = 0; k < L; k++) {
				int v = dp[i][j][k];
				if(v > dp[i][j + 1][k]) {
					dp[i][j + 1][k] = v;
					prv[i][j + 1][k] = JDOWN;
				}
				if(v > dp[i + 1][j][k]) {
					dp[i + 1][j][k] = v;
					prv[i + 1][j][k] = IDOWN;
				}
				if(i < s1.size() && j < s2.size() && s1[i] == s2[j]) {
					int nk = k;
					char c = s1[i]; // = s2[j]
					while(nk >= 0 && c != V[nk]) {
						nk = F[nk];
					}
					nk ++;
					v++;
					if(v > dp[i+1][j+1][nk]) {
						dp[i+1][j+1][nk] = v;
						prv[i+1][j+1][nk] = k;
					}
				}
			}
		}
	}
	int maxk = 0;
	for(int k = 1; k < L; k++) {
		if(dp[s1.size()][s2.size()][k] > dp[s1.size()][s2.size()][maxk]) {
			maxk = k;
		}
	}
	string ans = "";
	int i = s1.size(), j = s2.size(), k = maxk;
	cerr << dp[i][j][k] << '\n';
	while(i && j) {
		//cerr << i << ' ' << j << ' ' << k << ' ' << prv[i][j][k] << '\n';
		switch(prv[i][j][k]) {
			case IDOWN: 
				i--;
				break;
			case JDOWN:
				j--;
				break;
			default:
				k = prv[i][j][k];
				i--,j--;
				assert(s1[i] == s2[j]);
				ans += s1[i]; // s2[j]
		}
	}
	reverse(ans.begin(), ans.end());
	if(ans.length() == 0) ans = "0";
	return ans;
}

void io(istream &in, ostream &out) {
	in >> s1 >> s2 >> V;
	L = V.size();
	fail();
	out << go() << '\n';
}

int main() {
	ifstream fin ("346B.in");
	if(fin.good()) {
		ofstream fout ("346B.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}