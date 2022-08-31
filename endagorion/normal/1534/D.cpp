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

int n;
set<pii> s;

void add_edge(int a, int b) {
    if (a > b) swap(a, b);
    s.insert(mp(a, b));
}

set<int> asked;

vi query(int v) {
    asked.insert(v);
    cout << "? " << v + 1 << endl;
    vi a(n);
    forn(i, n) cin >> a[i];
    forn(i, n) if (a[i] == 1) add_edge(i, v);
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
//    freopen("input.txt", "rt", stdin);
#endif

    cin >> n;
    vi a0 = query(0);
    vi cnt(2);
    forn(i, n) ++cnt[a0[i] % 2];
    int m2 = min_element(all(cnt)) - cnt.begin();
    forn(i, n) {
        if (a0[i] % 2 == m2 && !asked.count(i)) query(i);
    }

    assert(s.size() == n - 1);
    cout << "!\n";
    for (auto [a, b]: s) cout << a + 1 << ' ' << b + 1 << '\n';
    cout.flush();

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}