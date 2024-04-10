#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 110000;
vi e[maxn];
int m[maxn];
int col[maxn];

void match(int x, int y) {
    m[x] = y;
    m[y] = x;
    e[x].pb(y);
    e[y].pb(x);
}

void unmatch(int x) {
    int y = m[x];
    m[x] = m[y] = -1;
}

bool color(int v, int c) {
    if (col[v] != -1) return col[v] == c;
    col[v] = c;
    for (int u: e[v]) if (!color(u, c ^ 1)) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif
    
    int n;
    cin >> n;
    forn(i, n) m[i] = -1;

    vector<pii> evs;
    forn(i, n) {
        int l, r;
        cin >> l >> r;
        evs.pb(mp(2 * l, i));
        evs.pb(mp(2 * r + 1, -i - 1));
    }

    sort(all(evs));
    int unm = -1;
    for (auto [x, id]: evs) {
        bool add = true;
        if (id < 0) {
            id = -id - 1;
            add = false;
        }

        if (add) {
            if (unm != -1) {
                match(id, unm);
                unm = -1;
            } else unm = id;
        } else {
            if (id == unm) unm = -1;
            else {
                int other = m[id];
                unmatch(id);
                if (unm == -1) unm = other;
                else {
                    match(unm, other);
                    unm = -1;
                }
            }
        }
    }

    forn(i, n) col[i] = -1;
    forn(i, n) {
        if (col[i] != -1) continue;
        assert(color(i, 0));
    }

    forn(i, n) cout << col[i] << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}