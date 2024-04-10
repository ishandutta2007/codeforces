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

const int maxn = 310000 * 31;
int tr[maxn][2];
int w[maxn];
i64 inv[30][2];

int tc = 2;

void add(int v, int x, int i) {
    ++w[v];
    if (i < 0) return;
    int b = (x >> i) & 1;
    if (!tr[v][b]) tr[v][b] = tc++;
    add(tr[v][b], x ^ (b << i), i - 1);
    int wx = w[tr[v][b ^ 1]];
    inv[i][b] += wx;
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
    int root = 1;
    forn(i, n) {
        int x;
        cin >> x;
        add(root, x, 29);
    }

    i64 minI = 0;
    int x = 0;
    forn(i, 30) {
        minI += min(inv[i][0], inv[i][1]);
        if (inv[i][1] < inv[i][0]) x += (1 << i);
    }
    cout << minI << ' ' << x << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}