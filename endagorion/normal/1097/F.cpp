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

const int maxv = 7001, maxn = 100011;
typedef bitset<maxv> bs;
bs b[maxv], bb[maxv], a[maxn];
int mu[maxv];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    for1(i, maxv - 1) for1(j, (maxv - 1) / i) b[j * i][i] = 1;
    mu[1] = 1;
    for1(i, maxv - 1) fore(j, 2, (maxv - 1) / i) mu[i * j] -= mu[i];
    for1(i, maxv - 1) for1(j, (maxv - 1) / i) if (mu[j] != 0) bb[i][i * j] = 1;
    int n, q;
    scanf("%d%d", &n, &q);
    forn(i, q) {
        int type;
        scanf("%d", &type);
        if (type == 1 || type == 4) {
            int x, v;
            scanf("%d%d", &x, &v);
            if (type == 1) a[x] = b[v];
            else printf("%d", int((a[x] & bb[v]).count() % 2));
        } else {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            if (type == 2) a[x] = a[y] ^ a[z];
            else a[x] = a[y] & a[z];
        }
    }
    printf("\n");

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}