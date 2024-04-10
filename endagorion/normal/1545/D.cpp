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

const int maxx = 1000001;
typedef bitset<maxx> bs;

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
    vvi a(k, vi(n));
    vector<bs> b(k);
    vi64 sum(k), sum2(k);
    forn(i, k) forn(j, n) {
        int x;
        cin >> x;
        a[i][j] = x;
        sum[i] += x;
        sum2[i] += 1LL * x * x;
        b[i][x] = 1;
    }

    int ti, mis;
    i64 delta;
    forn(i, k - 1) {
        int misaligned = -1;
        i64 d = sum[i + 1] - sum[i];
        forn(j, k) {
            i64 psum = sum[i] + 1LL * d * (j - i);
            if (psum != sum[j]) {
                delta = psum - sum[j];;
                if (misaligned == -1) misaligned = j;
                else misaligned = -2;
            }
        }
        if (misaligned >= 0) {
            ti = i;
            mis = misaligned;
//            cerr << misaligned << '\n';
            break;
        }
    }

    ti = 0;
    while (mis >= ti && mis <= ti + 2) ++ti;

    i64 psum2 = 0;
    forn(k, 3) {
        i64 v = sum2[ti + k];
        forn(l, 3) {
            if (l != k) v *= mis - (ti + l);
        }
        forn(l, 3) if (l != k) {
            assert(v % (k - l) == 0);
            v /= k - l;
        }
        psum2 += v;
    }

//    cerr << delta << '\n';
//    cerr << sum2[mis] << ' ' << psum2 << '\n';

    int mj = -1;
    forn(j, n) {
        i64 x = a[mis][j];
        i64 nsum2 = sum2[mis] - 1LL * x * x + 1LL * (x + delta) * (x + delta);
        if (nsum2 == psum2) {
            mj = x + delta;
            break;
        }
    }
    cout << mis << ' ' << mj << endl;

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}