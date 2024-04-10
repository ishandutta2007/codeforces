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

const int maxn = 210000;
int f[maxn];

void fenwAdd(int i, int x) {
    for (; i < maxn; i |= i + 1) f[i] += x;
}

int fenwSum(int i) {
    int s = 0;
    for (; i >= 0; i &= i + 1, --i) s += f[i];
    return s;
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
    vi p(n);
    forn(i, n) cin >> p[i], --p[i];
    vi q(n);
    forn(i, n) q[p[i]] = i;
    set<int> lh, rh;
    i64 ls = 0, rs = 0;

    i64 inv = 0;
    forn(i, n) {
        inv += i - fenwSum(q[i]);
        fenwAdd(q[i], 1);
        if (lh.empty() || q[i] <= *lh.rbegin()) lh.insert(q[i]), ls += q[i];
        else rh.insert(q[i]), rs += q[i];
        while (rh.size() > lh.size()) {
            int x = *rh.begin();
            rs -= x;
            ls += x;
            rh.erase(x);
            lh.insert(x);
        }
        while (lh.size() > rh.size() + 1) {
            int x = *lh.rbegin();
            ls -= x;
            rs += x;
            lh.erase(x);
            rh.insert(x);
        }

        i64 ans = inv;
        i64 x = *lh.rbegin();
        i64 L = lh.size(), R = rh.size();
//        cerr << x << ' ' << L << ' ' << R << ' ' << inv << '\n';
        ans += x * L - L * (L - 1) / 2 - ls;
        ans += rs - x * R - R * (R + 1) / 2;
        cout << ans << ' ';
    }
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}