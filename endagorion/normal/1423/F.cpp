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

bool play(vi a) {
    int n = a.size();
    forn(its, 1000) {
        bool any = false;
        forn(i, a.size()) if (a[i] >= 2) {
            any = true;
            int z = a[i] / 2;
            a[i] -= 2 * z;
            a[(i + n - 1) % n] += z;
            a[(i + 1) % n] += z;
        }
        if (!any) return true;
    }
    return false;
}

int n;

bool decide(vi a) {
    int total = accumulate(all(a), 0);
    if (total < n) return true;
    if (total > n) return false;
    int sum = 0;
    forn(i, n) (sum += 1LL * a[i] * i) %= n;
    int need = n % 2 == 0 ? n / 2 : 0;
    return sum == need;
}

void rec(vi &a, int left) {
    if (a.size() == n) {
        if (play(a) != decide(a)) {
            for (int x: a) cerr << x << ' ';
            cerr << '\n';
            cerr << play(a) << ' ' << decide(a) << '\n';
            assert(false);
        }
        return;
    }
    forn(i, left + 1) {
        a.pb(i);
        rec(a, left - i);
        a.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, k;
    cin >> n >> k;
    i64 total = 0, sum = 0;
    forn(i, k) {
        i64 pos, c;
        cin >> pos >> c;
        total += c;
        (sum += pos * c) %= n;
    }

    bool good;
    if (total < n) good = 1;
    else if (total > n) good = 0;
    else good = sum == (n % 2 == 0 ? n / 2 : 0LL);
    cout << (good ? 1 : -1) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}