/*
LANG: C++
ID: he.andr1
PROG: 329B
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

const int mx[] = {-1, 1, 0, 0};
const int my[] = {0, 0, -1, 1};

const int MAXN = 2000;

int R, C;
int grid[MAXN][MAXN];
pii S, E;

int go() {
	queue<pii> q;
	q.push(E);
	int ans = 0;
	int found = false;
	for(int i = 0; !found; i++) {
		for(int j = q.size(); j > 0; j--) {
			pii cur = q.front(); q.pop();
			int x = cur.A, y = cur.B;
			grid[x][y] = -1;
			for(int m = 0; m < 4; m++) {
				int nx = x + mx[m], ny = y + my[m];
				if(grid[nx][ny] != -1) {
					ans += grid[nx][ny];
					grid[nx][ny] = -1;
					if(pii(nx, ny) == S) {
						found = true;
					}
					q.push(pii(nx, ny));
				}
			}
		}
	}
	return ans;
}

void io(istream &in, ostream &out) {
	memset(grid, -1, sizeof(grid));
	in >> R >> C;
	for(int i = 1; i <= R; i++) {
		string s; in >> s;
		for(int j = 1; j <= C; j++) {
			char c = s[j - 1];
			if(c == 'S') {
				grid[i][j] = 0;
				S = pii(i, j);
			} else if(c == 'E') {
				grid[i][j] = 0;
				E = pii(i, j);
			} else if(c == 'T') {
				grid[i][j] = -1;
			} else {
				grid[i][j] = c - '0';
			}
		}
	}
	out << go() << '\n';
}

int main() {
	ifstream fin ("329B.in");
	if(fin.good()) {
		ofstream fout ("329B.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}