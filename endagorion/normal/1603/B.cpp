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

i64 GCD(i64 a, i64 b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long Euclid(long long A, long long B, long long &X, long long &Y) {
    if (B == 0) {
        X = 1;
        Y = 0;
        return A;
    }
    long long res = Euclid(B, A % B, X, Y);
    long long nX = Y;
    long long nY = X - Y * (A / B);
    X = nX; Y = nY;
    return res;
}

inline long long InvMod(long long N, long long P) {
//    cerr << N  << ' ' << P << '\n';
    N %= P;
    if (N < 0) N += P;
    long long X, Y;
    assert(Euclid(N, P, X, Y) == 1);
    return (X % P + P) % P;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    while (T--) {
        i64 x, y;
        cin >> x >> y;
        i64 ans = x > y ? x + y : y - (y % x) / 2;
/*        if (y % x == 0) ans = x;
        else {
            i64 g = GCD(x, y);
            i64 X = x / g, Y = y / g;
            i64 k = InvMod(Y, X);
            cerr << Y << ' ' << X << ' ' << k << ' ' << k * Y % X <<'\n';
            ans = (1 + (1 - k + X) * Y) * g;
//            cerr << (1 + (1 - k + X) * Y) % X << ' ' << Y % (1 + (1 - k + X) * Y) << '\n';
        }*/
//        cerr << ans % x << ' ' << y % ans << '\n';
        assert(ans % x == y % ans);
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}