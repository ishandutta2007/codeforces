#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

inline void srand() { srand(chrono::high_resolution_clock::now().time_since_epoch().count()); }

template <class T, class U>
ostream& operator << (ostream& os, const pair<T,U>& v) {
	os << "(" << v.first << "," << v.second << ")"; return os;
}

template <class T>
ostream& operator << (ostream& os, const vector<T>& v) {
	for (const T& it : v) os << it << " "; return os;
}

template <class T>
ostream& operator << (ostream& os, const set<T>& v) {
	os << "{ "; for (const T& it : v) os << it << " "; os << "}"; return os;
}

template <class T, class U>
ostream& operator << (ostream& os, const map<T,U>& v) {
	os << "{ ";
	for (const pair<T,U>& it : v) os << "{" << it.first << "," << it.second << "} "; 
	os << "}"; return os;
}

template <class T>
inline T sqr(T x) { return x*x; }

const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
//const ld PI = M_PIl;
////////////////////////////////////////////////////////////////////////

// MAGIC IO
#define USE_MAGIC_IO
#ifdef USE_MAGIC_IO
inline char get(void) {
	static char buf[100000], *S = buf, *T = buf;
	if (S == T) {
		T = (S = buf) + fread(buf, 1, 100000, stdin);
		if (S == T) return EOF;
	}
	return *S++;
}
inline void read(int &x) {
	static char c; x = 0; int sgn = 0;
	for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
	for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
	if (sgn) x = -x;
}
#else
#define get() getchar()
#define read(x) scanf("%d",&x)
#endif
void readchar(char& c) {
	while (isspace(c = get()));
}

const ll MOD = 1e9+7;
const ld EPS = 1e-9;

//////////////////////////////////////////
// vars
const int NN = 1e5+1;
map<int,int> cols[NN];
//////////////////////////////////////////

namespace SCC {
	const int N = 2e5+7;
int low[N],vis[N],scomp[N],scompNum,I;
vector<int> adj[N]; stack<int> verts;
void scc(int u) { low[u] = vis[u] = ++I; verts.push(u);
  for (int v : adj[u]) {
    if (!vis[v]) scc(v);
    if (scomp[v] == -1) low[u] = min(low[u], low[v]); }
  if (vis[u] <= low[u]) { int v;
    do { v=verts.top(); verts.pop(); scomp[v]=scompNum; } while (v != u);
    ++scompNum; }}
void get_scc(int n) { memset(vis,0,sizeof vis); memset(scomp,-1,sizeof scomp);
  scompNum=I=0; for (int i=0; i<n; ++i) if (!vis[i]) scc(i); }
////////////////////////////////////////////////////////////////////////////////
// 2-SAT using SCC (previous version was TESTED F - SouthAmerica03)
////////////////////////////////////////////////////////////////////////////////
bool truth[N/2]; // N must be at least 2 times the number of variables
// the clause a || b becomes !a => b and !b => a in the implication graph
void add_clause(int a, int b) { adj[a].push_back(b); } // IMPLICATION
bool two_sat(int n) { get_scc(n);
  for (int i = 0; i < n; i += 2) { if (scomp[i] == scomp[i^1]) return false;
    truth[i/2] = (scomp[i] < scomp[i^1]); } return true; }
// usage:   for (int i = 0; i < 2*num_vars; ++i) adj[i].clear();
//          add_clause(2*x, 2*y^1); // example for x || !y
//          if (two_sat(2*num_vars)) // satisfiable, truth[x] = assign. for x
//          else // no satisfying assignment exists
//*!
}

bool solve(int start, int end, int c) {
	//cerr << "try block " << start << " " << end << endl;
	map<int,int>::iterator it = cols[c].lower_bound(start);
	map<int,int>::iterator last = cols[c].lower_bound(end);
	if (it == last) {
		return true;
	}
	if (last == cols[c].end()) {
		return false;
	}

	//cerr << "iterator loop" << endl;
	int curblock = it->first;
	while (it != last) {
		map<int,int>::iterator nit = next(it);
		// check gap
		if (nit->first - it->first > 1) {
			return false;
		}
		// check block
		if (nit->second != it->second) {
			// add block
			if (!solve(curblock, it->first, c+1)) {
				return false;
			}
			curblock = nit->first;
			if (it->second > nit->second) {
				SCC::add_clause(2*it->second^1, 2*it->second);
				SCC::add_clause(2*nit->second, 2*nit->second^1);
			}
			else if (it->second < nit->second) {
				SCC::add_clause(2*nit->second, 2*it->second);
				SCC::add_clause(2*it->second^1, 2*nit->second^1);
			}
		}
		it = nit;
	}
	if (!solve(curblock, end, c+1)) {
		return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	srand();

	int n, m;
	//cin >> n >> m;
	read(n); read(m);

	int k, a;
	for (int i = 1; i <= n; i++) {
		//cin >> k;
		read(k);
		for (int j = 1; j <= k; j++) {
			//cin >> a;
			read(a);
			cols[j][i] = a;
		}
	}

	if (solve(1, n, 1) && SCC::two_sat(2*m + 2)) {
		cout << "Yes" << nl;
		vector<int> ans;
		for (int i = 1; i <= m; i++) {
			if (SCC::truth[i])
				ans.push_back(i);
		}
		cout << ans.size() << nl;
		for (int it : ans) {
			cout << it << " ";
		}
		cout << nl;
	}
	else {
		cout << "No" << nl;
	}

	return 0;
}