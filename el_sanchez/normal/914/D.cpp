#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define forab(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define fst first
#define snd second

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using vvi = vector<vi>;

#define FILE_NAME "a"

const int MAXN = (int)5e5 + 10;

int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a%b);
}

struct seg_tree {
	static const int K = 19;
	static const int MAXK = 1 << K;

	int t[2 * MAXK + 3];

	seg_tree() {
		//cerr << 1 << endl;
	};

	seg_tree(int n, int *a) {
		//cerr << 1 << endl;

		memset(t, 0, sizeof(t));

		forn(i, n) {
			t[MAXK + i] = a[i];
		}
		for (int i = n; MAXK + i < 2 * MAXK + 3; i++) {
			t[MAXK + i] = 0;
		}

		for (int v = MAXK - 1; v >= 1; v--) {
			t[v] = gcd(t[v * 2], t[v * 2 + 1]);
		}

		//cerr << 2 << endl;		
	}

	void change(int i, int y) {
		int v = MAXK + i;
		t[v] = y;
		while (v > 1) {
			v >>= 1;
			t[v] = gcd(t[v * 2], t[v * 2 + 1]);
		}
	}

	void bf(int v, int vL, int vR, int qL, int qR, int x, int &bad) {
		if (bad >= 2) {
			return;
		}

		if (vR <= qL || qR <= vL) {
			return;
		}
		if (qL <= vL && vR <= qR) {
			if (t[v] % x == 0) {
				return;
			}
			if (vL + 1 == vR) {
				bad += (t[v] % x != 0);
				return;
			}
		}

		bf(v * 2, vL, (vL + vR) >> 1, qL, qR, x, bad);
		bf(v * 2 + 1, (vL + vR) >> 1, vR, qL, qR, x, bad);
	}

	bool can(int L, int R, int x) {
		int bad = 0;
		bf(1, 0, MAXK, L, R + 1, x, bad);
		return bad <= 1;
	}
};

int n, q;
int a[MAXN];
seg_tree t;

bool read() {
    if (scanf("%d", &n) != 1) {
        return 0;
    }
    forn(i, n) {
    	scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    
    return 1;
}

void solve() {
	//cout << "!!!!!!!!" << endl;

	t = seg_tree(n, a);
	forn(ii, q) {
		//cerr << ii << endl;
		int tq;
		scanf("%d", &tq);
		if (tq == 1) {
			int L, R, x;
			scanf("%d%d%d", &L, &R, &x);
			L--, R--;
			//cerr << L << ".." << R << ' ' << x << endl;
			cout << (t.can(L, R, x) ? "YES" : "NO") << '\n';
		} else {
			int i, y;
			scanf("%d%d", &i, &y);
			i--;
			t.change(i, y);
		}
	}
}

int main() {
#ifdef LOCAL
    freopen(FILE_NAME ".in", "r", stdin);
//    freopen(FILE_NAME ".out", "w", stdout);
#endif

    while (read()) {
        solve();
    }

    return 0;
}