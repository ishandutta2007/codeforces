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

const int maxn = 101;
int n;
i64 pang[maxn], chou[maxn];

pi64 eval(const vi64 &a) {
    i64 p = 0, c = 0;
    forn(i, n) p += a[i] * (a[i] - 1) * (a[i] - 2) / 6;
    forn(i, n - 2) c += a[i] * a[i + 1] * a[i + 2];
    return mp(p, c);
}

void rec(vi64 &a, vvi64 &s, pi64 p) {
    if (a.size() == n) {
        if (eval(a) == p) s.pb(a);
        return;
    }
    forn(j, n + 1) {
        a.pb(j);
        rec(a, s, p);
        a.pop_back();
    }
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
    if (n > 5) {
        cin >> pang[0] >> chou[0];
        for1(i, n) {
            cout << "+ " << i << endl;
            cin >> pang[i] >> chou[i];
        }

        vvi64 ans;
        forn(y, n + 1) forn(z, n + 1) {
            vi64 res(n);
            res[n - 1] = y;
            res[n - 2] = z;
            bool ok = true;
            for (int i = n - 1; i >= 2; --i) {
                i64 d = chou[i + 1] - chou[i];
                if (i + 1 < n) d -= (res[i - 1] + 1) * res[i + 1];
                if (i + 2 < n) d -= res[i + 1] * res[i + 2];
                if (d < 0 && d % (res[i - 1] + 1)) {
                    ok = false;
                    break;
                }
                res[i - 2] = d / (res[i - 1] + 1) - 1;
                if (res[i - 2] > n || res[i - 2] < 0) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
    //        cerr << y << ' ' << z << '\n';

            i64 p = 0, c = 0;
            forn(i, n) p += res[i] * (res[i] - 1) * (res[i] - 2) / 6;
            forn(i, n - 2) c += res[i] * res[i + 1] * res[i + 2];
            ok &= p == pang[0] && c == chou[0];
            forn(i, n) {
                p += res[i] * (res[i] - 1) / 2;
                if (i >= 2) c += (res[i - 2] + 1) * (res[i - 1] + 1);
                if (i >= 1 && i + 1 < n) c += (res[i - 1] + 1) * res[i + 1];
                if (i + 2 < n) c += res[i + 1] * res[i + 2];
                ok &= p == pang[i + 1] && c == chou[i + 1];
            }
            if (ok) ans.pb(res);
        }

        assert(ans.size() == 1);
        cout << "!";
        for (auto x: ans[0]) cout << ' ' << x;
        cout << '\n';
    } else {
        pi64 ip;
        cin >> ip.fi >> ip.se;
        vvi64 s;
        vi64 a;
        rec(a, s, ip);
        vi64 add(n);
        while (s.size() > 1) {
            cerr << s.size() << '\n';
            int bs = 1e9, bi = -1;
            forn(i, n - 1) {
                map<pi64, int> cnt;
                for (auto w: s) {
                    w[i]++;
                    ++cnt[eval(w)];
                }

                int sc = 0;
                for (auto w: cnt) uax(sc, w.se);
                if (uin(bs, sc)) bi = i;
            }

            cout << "+ " << bi + 1 << endl;
            pi64 p;
            cin >> p.fi >> p.se;

            ++add[bi];
            vvi64 ns;
            for (auto w: s) {
                ++w[bi];
                if (eval(w) == p) ns.pb(w);
            }
            s = ns;
        }

        cout << "!";
        forn(i, n) cout << ' ' << s[0][i] - add[i];
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}