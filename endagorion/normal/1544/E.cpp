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
int n;

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
        cin >> s;
        n = s.size();
        vi cnt(26);
        for (char c: s) ++cnt[c - 'a'];
        bool done = s == string(n, s[0]);
        forn(c, 26) {
            if (done) break;
            if (cnt[c] == 1) {
                done = true;
                s[0] = 'a' + c;
                int p = 1;
                --cnt[c];
                forn(j, 26) forn(x, cnt[j]) s[p++] = (char)('a' + j);
            }
        }
        if (done) {
            cout << s << '\n';
            continue;
        }
        int nc1 = -1, nc2 = -1;
        forn(c1, 26) forn(c2, 26) {
            if (nc1 != -1) break;
            if (!cnt[c1] || !cnt[c2]) continue;
            if (c1 == c2 && cnt[c1] < 2) continue;
            bool can;
            if (c1 == c2) can = 2 * (cnt[c1] - 2) <= n - 2;
            else can = true;
            if (can) {
                nc1 = c1;
                nc2 = c2;
                break;
            }
        }

        int p = 0;
        s[p++] = (char)('a' + nc1);
        s[p++] = (char)('a' + nc2);
//        cerr << s[0] << s[1] << '\n';
        int lft = n - 2;
        --cnt[nc1]; --cnt[nc2];
        while (p < n) {
            bool done = false;
            forn(c, 26) {
                if (!cnt[c]) continue;
                if (c == nc2 && s[p - 1] == s[0]) continue;
                --cnt[c];
                bool can;
                if (nc1 == nc2) {
                    can = 2 * cnt[nc1] - 1 <= lft - 1 - int(c == nc1);
                } else {
                    can = c != nc1 || cnt[nc2] == 0 || cnt[nc1] + cnt[nc2] != lft - 1;
                }
                if (can) {
                    done = true;
                    s[p++] = 'a' + c;
//                    cerr << s[p++] << '\n';
                    --lft;
                    break;
                } else ++cnt[c];
            }
            assert(done);
        }
        cout << s << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}