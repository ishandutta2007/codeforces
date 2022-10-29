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

const int MAXN = (int)1e5 + 5;

int n;
int a[MAXN];

bool read() {
    if (scanf("%d\n", &n) < 1) {
        return 0;
    }
    forn(i, n) {
    	scanf("%d", &a[i]);
    }
    return 1;
}

map<int, int> cnt;

bool solve() {
	cnt.clear();
	forn(i, n) {
		cnt[a[i]]++;
	}	

	for (auto p: cnt) {
		if (p.snd % 2 == 1) {
			return 1;
		}
	}
	return 0;
}

int main() {
#ifdef LOCAL
    freopen(FILE_NAME ".in", "r", stdin);
//    freopen(FILE_NAME ".out", "w", stdout);
#endif

    while (read()) {
        cout << (solve() ? "Conan" : "Agasa") << '\n';
    }

    return 0;
}