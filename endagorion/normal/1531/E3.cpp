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

string s;
int pos;

bool compare() {
    if (pos < s.size()) return s[pos++] == '0';
    pos = 1e9;
    return true;
}

void merge_sort(vi &a, int L, int R) {
    if (R - L <= 1) return;
    int M = (L + R) / 2;
    merge_sort(a, L, M);
    merge_sort(a, M, R);
    vi buf(R - L);
    int i = L, j = M, p = 0;
    while (i < M && j < R) buf[p++] = (compare() ? a[i++] : a[j++]);
    while (i < M) buf[p++] = a[i++];
    while (j < R) buf[p++] = a[j++];
    forn(z, R - L) a[L + z] = buf[z];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> s;
    int L = 0, R = 200000;
    while (R - L > 1) {
        int M = (L + R) / 2;
        pos = 0;
        vi a(M);
        iota(all(a), 0);
        merge_sort(a, 0, M);
        (pos < 1e8 ? L : R) = M;
    }

    vi a(L);
    iota(all(a), 0);
    pos = 0;
    merge_sort(a, 0, L);
    assert(pos == s.size());

    vi inv(L);
    forn(i, L) inv[a[i]] = i + 1;

    cout << L << '\n';
    for (int x: inv) cout << x << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}