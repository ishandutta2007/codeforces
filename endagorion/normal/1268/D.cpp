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

const int maxn = 1 << 11;
typedef bitset<maxn> bs;
bs e[maxn], re[maxn];
bs unvis;
int n;

void dfs(int v, bool rev) {
    unvis[v] = 0;
    while (1) {
        int u = ((rev ? re : e)[v] & unvis)._Find_first();
        if (u >= n) break;
        dfs(u, rev);
    }
}

bool sc() {
    forn(z, 2) {
       forn(i, n) unvis[i] = 1;
       dfs(0, z);
       if (unvis.any()) return false;
    }
    return true;
}

void flip(int i) {
    forn(j, n) if (i != j) e[i][j].flip(), e[j][i].flip(), re[i][j].flip(), re[j][i].flip();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif
    
    cin >> n;
    forn(i, n) {
        string s;
        cin >> s;
        forn(j, n) if (i != j) e[i][j] = (s[j] == '1'), re[i][j] = (s[j] == '0');
    }

    if (sc()) cout << "0 1\n";
    else {
        int c1 = 0;
        forn(i, n) {
            flip(i);
            if (sc()) ++c1;
            flip(i);
        }
        if (c1) cout << 1 << ' ' << c1 << '\n';
        else {
            assert(n <= 6);
            int c2 = 0;
            forn(i, n) forn(j, n) {
                flip(i);
                flip(j);
                if (sc()) ++c2;
                flip(i);
                flip(j);
            }
            if (c2) cout << 2 << ' ' << c2 << '\n';
            else cout << -1 << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}