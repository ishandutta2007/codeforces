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

const int N = 3e5 + 100;
const int INF = 1e9 + 7;

vector <int> g[N];
int d[N], used[N], x[N], sup[N];
map<pii, int> cnt_e;
map<int, int> cnt;

void fail() {
	cout << "NO\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	forn(i, m) {
		int u ,v;
		cin >> u >> v;
		u--, v--;
		g[v].pb(u);
		g[u].pb(v);
	}
	forn(i, n)
		d[i] = INF;
	queue<int> q;
	q.push(0);
	d[0] = 0;
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(int to : g[v]) {
			if (d[to] > d[v] + 1) {
				d[to] = d[v] + 1;
				if (!used[to]) {
					used[to] = 1;
					q.push(to);
				}
			}
		}
	}
	int c = 0;
	forn(v, n)
		if (d[v] == 1)
			c++;
	forn(v, n) {
		if (d[v] == 1) {
			int cc = 0, cm = 0, bad = 0;
			for (int to : g[v]) {
				if (d[to] == 1) {
					cc++;
				} else if (d[to] > 1)
					bad = 1;
			}
			if (bad)
				continue;
			if (cc == c - 1)
				sup[v] = 1;
		}
	}
	forn(v, n) {
		if (d[v] == 1 && !sup[v]) {
			x[v] = 1;
			for (int to : g[v]) {
				if (d[to] == 1 && !sup[to]) {
					x[to] = 1;
				}
			}
			break;
		}
	}
	forn(v, n) {
		if (d[v] == 1 && !x[v] && !sup[v]) {
			x[v] = -1;
		}
	}
	vector <pii> vs;
	
	forn(i, n) {
		vs.pb(mp(d[i], i));
	}
	sort(all(vs));
	forn(i, n) {
		int dd = vs[i].fst;
		if (dd > 1) {
			int v = vs[i].snd;
			for(int to : g[v]) {
				if (d[to] == dd - 1) {
					if (x[to] < 0)
						x[v] = x[to] - 1;
					else
						x[v] = x[to] + 1;
				break;
				}
			}
		}
	}
	forn(i, n) {
		cnt[x[i]]++;
		for (int to : g[i]) {
			if (i < to)
				cnt_e[mp(min(x[i], x[to]), max(x[i], x[to]))]++;
		}
	}
	forn(i, n) {
		for (int to : g[i]) {
			if (abs(x[i] - x[to]) > 1) {
				fail();
			}
		}
	}
	ll sum = 0;
	for (auto p : cnt) {
		int val = p.fst, num = p.snd;
		if (cnt_e[mp(val, val)] != num * 1ll * (num - 1) / 2)
			fail();
		sum += num * 1ll * (num - 1) / 2;
		int num1 = 0;
		if (cnt.find(val - 1) != cnt.end()) 
			num1 = cnt[val - 1];
		if (cnt_e[mp(val - 1, val)] != num * 1ll * num1)
			fail();
		int num2 = 0;
		if (cnt.find(val + 1) != cnt.end()) 
			num2 = cnt[val + 1];
		if (cnt_e[mp(val, val + 1)] != num * 1ll * num2)
			fail();
		sum += num * 1ll * num2;
	}
	if (sum != m)
		fail();
	cout << "YES\n";
	int mn = cnt.begin()->fst;
	forn(i, n) {
		cout << x[i] - mn + 1 << " ";
	}
	cout << '\n';
	return 0;
}