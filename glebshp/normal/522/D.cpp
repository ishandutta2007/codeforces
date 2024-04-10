#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
#endif

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define forv(i,v) for (auto i = v.begin(); i != v.end(); ++i)
#define forr(i,v) for (auto i = v.end(); i != v.begin() && (--i, 1); )
#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T> inline T abs (T x) {return x > T() ? x : -x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 500000;
const int M = 500000;

struct Input {
	int n, m;
	int a[N];
	int l[M], r[M];
	
	bool read () {
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
		}
		forn (i, m) {
			scanf("%d%d", &l[i], &r[i]);
			--l[i];
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans[M];
	
	void write () {
		forn (i, m) {
			printf("%d\n", (ans[i] == N) ? -1 : ans[i]);
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	int tree[N + 1];
	
	int get (int i) {
		int res = N;
		for (; i; i &= (i - 1)) {
			umn(res, tree[i]);
		}
		return res;
	}
	
	void upd (int i, int x) {
		for (; i < N; i |= (i + 1)) {
			umn(tree[i + 1], x);
		}
	}

	ve<pii> rq[N];
	
	int nx[N];
	
	void solve () {
		forn (i, m) {
			rq[l[i]].pb(mp(r[i], i));
		}
		
		forn (i, n) {
			nx[i] = N;
		}
		
		{
			ve<pii> q;
			forn (i, n) {
				q.pb(mp(a[i], i));
			}
			sort(all(q));
			for (int i = 0; i < sz(q); ) {
				int j = i + 1;
				while (j < sz(q) && q[i].fs == q[j].fs) {
					nx[q[j - 1].sc] = q[j].sc;
					++j;
				}
				i = j;
			}
		}
		
		forn (i, N + 1) {
			tree[i] = N;
		}
		
		ford (i, n) {
			upd(nx[i], nx[i] - i);
			forn (j, sz(rq[i])) {
				ans[rq[i][j].sc] = get(rq[i][j].fs);
			}
		}
	}
	
	void clear () {
		*this = Solution();
	}
};

Solution sol;

int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);
#ifdef SG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	while (sol.read()) {
		sol.solve();
		sol.write();
		sol.clear();
		puts("");
	}
#else
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}