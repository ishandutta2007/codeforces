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

const int MAXN = 1111;

int n;
int a[MAXN];
set<int> squares;

bool read() {
    if (scanf("%d\n", &n) < 1) {
        return 0;
    }
    forn(i, n) {
    	scanf("%d", &a[i]);
    }
    return 1;
}

void solve() {
	for (int i = 0; i < MAXN; i++) {
		squares.insert(i * i);
	}

	int mx = -(int)1e9;
	forn(i, n) {
		if (squares.find(a[i]) == squares.end()) {
			mx = max(mx, a[i]);
		}
	}

	cout << mx << '\n';
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