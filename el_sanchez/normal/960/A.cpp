#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define FILE "a"

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stdout)
#else
#define eprintf(args...) ;
#endif

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

string s;

bool read() {
    if (!(cin >> s)) {
        return 0;
    }
    return 1;
}

bool solve() {
    int cnt[3];
    forn(i, 3) {
        cnt[i] = 0;
    }
    forn(i, sz(s)) {
        cnt[s[i] - 'a']++;
    }
    forn(i, 3) {
        if (cnt[i] == 0) {
            return 0;
        }
    }
    if (cnt[2] != cnt[0] && cnt[2] != cnt[1]) {
        return 0;
    }

    string t;
    forn(i, 3) {
        forn(j, cnt[i]) {
            t += (char)('a' + i);
        }
    }

    return s == t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifdef LOCAL
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
#endif

    while (read()) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }

#ifdef LOCAL
    eprintf("Time %.5f\n", clock() * 1.0 / CLOCKS_PER_SEC);
#endif
}