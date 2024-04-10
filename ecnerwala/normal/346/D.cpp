/*
LANG: C++
ID: he.andr1
PROG: 346D
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

const int MAXN = 2000000;
const int MAXM = 2000000;

int N, M;
vector<int> nxt[MAXN];
vector<int> prv[MAXN];

int outDeg[MAXN];
bool vis[MAXN];
int numOrders(int s, int t) {
	for(int i = 0; i < N; i++) outDeg[i] = nxt[i].size();

	memset(vis, 0, sizeof(vis));


	deque<pii> dq;
	dq.push_back(pii(t, 0));

	while(!dq.empty()) {
		pii p = dq.front();
		//cerr << p.A << ' ' << p.B << '\n';
		if(p.A == s) {
			//cerr << "done" << '\n';
			return p.B;
		}
		dq.pop_front();
		if(vis[p.A]) continue;
		vis[p.A] = true;
		//cerr << prv[p.A].size() << '\n';
		
		ITER(i, prv[p.A]) {
			//cerr << (*i) << '\n';
			if(vis[*i]) continue;
			outDeg[*i] --;
			if(outDeg[*i] == 0) {
				//no orders!
				dq.push_front(pii(*i, p.B));
			} else {
				dq.push_back(pii(*i, p.B + 1));
			}
		}
	}

	return -1;
}

void io(istream &in, ostream &out) {
	in >> N >> M;
	for(int i = 0; i < M; i++) {
		int a, b;
		in >> a >> b;
		a--, b--;
		nxt[a].push_back(b);
		prv[b].push_back(a);
	}
	int s, t;
	in >> s >> t;
	s--, t--;
	out << numOrders(s, t) << '\n';
}

int main() {
	ifstream fin ("346D.in");
	if(fin.good()) {
		ofstream fout ("346D.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}