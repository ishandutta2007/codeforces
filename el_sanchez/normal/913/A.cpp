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

int n, m;

bool read() {
	if (!(cin >> n >> m)) {
		return 0;
	}

	return 1;
}

int solve() {
	ll pwn = 1;
	forn(i, n) {
		pwn *= 2;
		if (pwn > m) {
			break;
		}
	}

	return (m % pwn);
}

int main() {
#ifdef LOCAL
    freopen(FILE_NAME ".in", "r", stdin);
//    freopen(FILE_NAME ".out", "w", stdout);
#endif

    while (read()) {
    	cout << solve() << '\n';
    }

    return 0;
}