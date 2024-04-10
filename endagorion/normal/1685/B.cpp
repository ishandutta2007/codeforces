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
        int a, b, c, d;
        string s;
        cin >> a >> b >> c >> d >> s;
        int X = count(all(s), 'A'), Y = count(all(s), 'B');
        if (X != a + c + d || Y != b + c + d) {
            cout << "NO\n";
            continue;
        }

        int S = 0;
        vvi gr(2);
        int p = 0;
        int n = s.size();
        while (p < n) {
            int q = p + 1;
            while (q < n && s[q] != s[q - 1]) ++q;
            S += (q - p - 1) / 2;
            if ((q - p) % 2 == 0) gr[s[p] - 'A'].pb((q - p) / 2);
            p = q;
        }
//        cerr << c << ' ' << d << ' ' << S << '\n';
        forn(z, 2) {
            sort(rall(gr[z]));
//            for (int x: gr[z]) cerr << x << ' ';
//            cerr << '\n';
            int &V = z ? d : c;
            while (!gr[z].empty()) {
                int t = gr[z].back();
                if (t > V) break;
                V -= t;
                S -= t - 1;
                gr[z].pop_back();
            }
        }
//        cerr << c << ' ' << d << ' ' << S << '\n';
        cout << (S >= c + d ? "YES" : "NO") << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}