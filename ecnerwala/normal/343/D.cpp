/*
LANG: C++
ID: he.andr1
PROG: 343D
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

const int MAXN = 1000000;

int N;
vector<int> adj[MAXN];
int par[MAXN];
int size[MAXN];

bool heavy[MAXN];
int hnext[MAXN];
int hpar[MAXN];

void decomp(int cur) {
	heavy[cur] = false;
	hnext[cur] = -1;
	size[cur] = 1;
	ITER(i, adj[cur]) {
		int nxt = *i;
		if(nxt == par[cur]) continue;
		par[nxt] = cur;
		decomp(nxt);
		size[cur] += size[nxt];
	}
	ITER(i, adj[cur]) {
		int nxt = *i;
		if(nxt == par[cur]) continue;
		if(size[nxt] > size[cur] / 2) {
			heavy[nxt] = true;
			hnext[cur] = nxt;
			break;
		}
	}
}

typedef vector<int> vi;

int cnum[MAXN];
int uind[MAXN];
int dind[MAXN];

vector<vi> uchains;
vector<vi> ubit;
vector<vi> dchains;
vector<vi> dbit;

void buildChains() {
	for(int i = 0; i < N; i++) {
		if(!heavy[i]) {
			vi ch;
			for(int cur = i; cur != -1; cur = hnext[cur]) {
				cnum[cur] = uchains.size();
				uind[cur] = ch.size() + 1;
				hpar[cur] = par[i];
				ch.push_back(cur);
			}
			for(int cur = i; cur != -1; cur = hnext[cur]) {
				dind[cur] = ch.size() + 1 - uind[cur];
			}
			uchains.push_back(ch);
			reverse(ch.begin(),ch.end());
			dchains.push_back(ch);
			vi bt(ch.size() + 1);
			ubit.push_back(bt);
			dbit.push_back(bt);
		}
	}
}

void init() {
	par[0] = -1;
	decomp(0);
	buildChains();
}

int bmax(vi &bit, int ind) {
	int ans = 0;
	for(; ind; ind &= ind - 1) {
		setmax(ans, bit[ind]);
	}
	return ans;
}

int bins(vi &bit, int ind, int v) {
	for(; ind < bit.size(); ind += (ind & -ind)) {
		setmax(bit[ind], v);
	}
}

int umax(int i) {
	int ans = 0;
	for(; i >= 0; i = hpar[i]) {
		int cn = cnum[i];
		int ind = uind[i];
		setmax(ans, bmax(ubit[cn], ind));
	}
	return ans;
}

void uins(int i, int v) {
	int cn = cnum[i];
	int ind = uind[i];
	bins(ubit[cn], ind, v);
}

int dmax(int i) {
	int cn = cnum[i];
	int ind = dind[i];
	return bmax(dbit[cn], ind);
}

void dins(int i, int v) {
	for(; i >= 0; i = hpar[i]) {
		int cn = cnum[i];
		int ind = dind[i];
		bins(dbit[cn], ind, v);
	}
}

int Q;
int C[MAXN], V[MAXN];

void io(istream &in, ostream &out) {
	in >> N;
	for(int i = 0; i < N - 1; i++) {
		int a, b; in >> a >> b; a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	in >> Q;
	for(int i = 0; i < Q; i++) {
		in >> C[i] >> V[i];
		V[i] --;
	}

	init();

	//for(int i = 0; i < N; i++)
		//cerr << i << ' ' << par[i] << ' ' << hpar[i] << ' ' << heavy[i] << '\n';
	
	for(int i = 0; i < Q; i++) {
		int c = C[i], v = V[i];
		if(c == 1) uins(v, i + 1);
		else if(c == 2) dins(v, i + 1);
		else {
			//cerr << v << '\n';
			int fill = umax(v);
			int empt = dmax(v);
			//cerr << fill << ' ' << empt << '\n';
			out << (fill > empt) << '\n';
			//cerr << '\n';
		}
	}
}

int main() {
	ifstream fin ("343D.in");
	if(fin.good()) {
		ofstream fout ("343D.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}