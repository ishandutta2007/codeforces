/*
LANG: C++
ID: he.andr1
PROG: 337D
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

const int MAXN = 200000, MAXM = MAXN;

int N, M, D;
int P[MAXM];
bool bad[MAXN];
vector<int> adj[MAXN];

int bestPos;
int bestDist;

void dfsP(int cur, int prev, int dist) {
	if(bad[cur] && dist > bestDist) {
		bestDist = dist;
		bestPos = cur;
	}
	ITER(i, adj[cur]) {
		int nxt = *i;
		if(nxt == prev) continue;
		dfsP(nxt, cur, dist + 1);
	}
}

int maxP(int start) {
	bestPos = -1;
	bestDist = -1;
	dfsP(start, -1, 0);
	return bestPos;
}

int maxDist[MAXN];

void dfs(int cur, int prev, int dist) {
	setmax(maxDist[cur], dist);
	ITER(i, adj[cur]) {
		int nxt = *i;
		if(nxt == prev) continue;
		dfs(nxt, cur, dist + 1);
	}
}


int go() {
	int a = maxP(0);
	int b = maxP(a);
	// a - b is a diameter
	dfs(a, -1, 0);
	dfs(b, -1, 0);
	int ans = 0;
	for(int i = 0; i < N; i++) if(maxDist[i] <= D) ans++;
	return ans;
}

void io(istream &in, ostream &out) {
	in >> N >> M >> D;
	for(int i = 0; i < M; i++) in >> P[i], P[i] --, bad[P[i]] = true;
	for(int i = 0; i < N - 1; i++) {
		int a, b; in >> a >> b; a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	out << go() << '\n';
}

int main() {
	ifstream fin ("337D.in");
	if(fin.good()) {
		ofstream fout ("337D.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}