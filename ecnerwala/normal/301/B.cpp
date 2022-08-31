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
#define X first
#define Y second

typedef complex<int> pt;
typedef long long ll;
typedef pair<ll, ll> pii;

template <class T> T cross(complex<T> a, complex<T> b) { return imag(a * conj(b)); }

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }

template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }

template <class T> void setmin(T &a, T b) { if(b < a) a = b; }

template <class T> void setmax(T &a, T b) { if(b > a) a = b; }

const int MAXN = 105;

int N;
ll D;
ll A[MAXN];
pii loc[MAXN];

bool vis[MAXN];

ll dist(int a, int b) {
	return abs(loc[a].X - loc[b].X) + abs(loc[a].Y - loc[b].Y);
}

ll go() {
	int S = 0, E = N - 1;
	priority_queue< pii > pq;
	pq.push(pii(0, S));
	while(!pq.empty()) {
		ll v = pq.top().X;
		int c = pq.top().Y;
		pq.pop();
		if(c == E) return -v;
		if(vis[c]) continue;
		vis[c] = true;
		for(int i = 0; i < N; i++) {
			if(vis[i]) continue;
			pq.push(pii(v + A[c] - dist(c, i) * D, i));
		}
	}
}

void io(istream &in, ostream &out) {
	in >> N >> D;
	A[0] = 0;
	for(int i = 1; i < N - 1; i++) {
		in >> A[i];
	}
	for(int i = 0; i < N; i++) {
		in >> loc[i].X >> loc[i].Y;
	}
	out << go() << '\n';
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