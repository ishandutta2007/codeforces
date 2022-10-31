#define FNAME ""

#undef __STRICT_ANSI__

#include <bits/stdc++.h> 

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (int)(n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (int)(b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
	#define U64 "%I64u"
#else
	#define I64 "%lld"
	#define U64 "%llu"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int N = 2e5 + 100;

int ans[N], n, k;

vector<int> g[N];
vector<int> *vs[N];

int last[N], par[N];
pii maxPath[N][2];
vector<pii> todo;

int p(int v) {
	return par[v] == v ? v : par[v] = p(par[v]);
}

void merge(int v, int u) {
	//cerr << v << " and " << u << '\n';
	v = p(v);
	u = p(u);
	par[v] = u;
}

void dfsBin(int v, int pp) {
	ans[v] = 1 - ans[pp];
	for (int to : g[v]) {
		if (to != pp) {
			dfsBin(to, v);
		}
	}
}

void dfsMax(int v, int pp) {
	maxPath[v][0] = maxPath[v][1] = mp(1, -1);
	for (int to : g[v]) {
		if (to != pp) {
			dfsMax(to, v);
			int len = maxPath[to][0].fst + 1;
			if (len > maxPath[v][0].fst) {
				maxPath[v][1] = maxPath[v][0];
				maxPath[v][0] = mp(len, to);
			} else if (len > maxPath[v][1].fst) {
				maxPath[v][1] = mp(len, to);
			}
		}
	}
}

bool cmp(int a, int b) {
	return maxPath[a][0].fst > maxPath[b][0].fst;
}

void dfs(int v, int pp, int maxLenUp) {
	//cerr << v << " : " << maxLenUp << '\n';
	vs[v] = new vector<int>(0);
	vs[v]->pb(v);
	last[v]++;
	sort(all(g[v]), &cmp);
	int added = 0;
	forn(i, sz(g[v])) {
		int to = g[v][i];
		if (to == pp) continue;
		int maxLen = 0;
		if (maxPath[v][0].snd == to) maxLen = max(maxLenUp + 1, maxPath[v][1].fst);
		else maxLen = max(maxLenUp + 1, maxPath[v][0].fst);

		dfs(to, v, maxLen);

		//cerr << v << " -> " << to << " " << i << '\n';
		if (!added) {
			added = 1;
			//cerr << "HERE\n";
			vs[v] = vs[to];
			last[v] = last[to] + 1;
			vs[v]->pb(v);
			if (last[v] > k) {
				merge((*vs[v])[last[v] - k - 1], v);
			}
			//cerr << last[v] << " | " << v << '\n';
		} else {
			maxLen = maxLenUp + 1;
			if (i + 1 < sz(g[v])) {
				maxLen = max(maxLen, maxPath[g[v][i + 1]][0].fst + 1);
			}
			if (last[v] + last[to] >= k) {
//				cout << v + 1 << " " << to + 1 << '\n';
//				cout << last[to] << " " << maxLen << " " << last[v] << '\n';
				if (last[to] + maxLen >= k && maxLen > 1) {
					cout << "No\n";
					exit(0);
				}
				//cerr << last[v] << " " << last[to] << '\n';
				int cur = last[v] - k;
				forn(j, min(k, last[to])) {
					//cerr << last[to] -1 - j << " " << cur << '\n';
					if (cur >= 0) merge((*vs[to])[last[to] - 1 - j], (*vs[v])[cur]);
					cur++;
				}
				todo.pb(mp(v, to));
			} else {
				//cerr << "In " << to << " " << last[to] << '\n';
			//	if (last[to] + maxLen >= k) {
					//cerr << "In " << to << " " << last[to] << " " << last[v] << '\n';
					int cur = last[v] - 2;
					forn(j, min(k, last[to])) {
						merge((*vs[to])[last[to] - 1 - j], (*vs[v])[cur]);
						cur--;
					}
			//	}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	forn(i, n - 1) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		g[v].pb(u);
		g[u].pb(v);
	}
	if (k == 2) {
		cout << "Yes\n";
		dfsBin(0, 0);
		forn(i, n) cout << ans[i] + 1 << " ";
		cout << '\n';
		return 0;
	}
	int root = 0;
	dfsMax(root, root);
//	forn(i, n) cout << maxPath[i][0].fst << '\n';
	forn(i, n) par[i] = i;
	dfs(root, root, 0);
	forn(i, min(k, last[root])) {
		ans[p((*vs[root])[last[root] - 1 - i])] = i + 1;
	}
	reverse(all(todo));
	for (pii vto : todo) {
		int v = vto.fst;
		int to = vto.snd;
	//	cout << v + 1 << " " << to + 1 << '\n';
		int initColor = (ans[p(v)] - 2 + k) % k;
	//	cout << initColor << '\n';
		forn(i, min(k, last[to])) {
			ans[p((*vs[to])[last[to] - 1 - i])] = ((initColor - i + k) % k) + 1;
		}
	}
	cout << "Yes\n";
	forn(i, n) {
		int anss = ans[p(i)];
//		if (!anss) anss = 1;
		assert(ans);
		cout << anss << " ";
	}
	cout << '\n';
	return 0;
}