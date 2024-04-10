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

i64 S;
int L;
i64 p10[19];
string let[19];
string repr;
pi64 stable[19];
i64 match[19];
i64 change[19];

pi64 operator+(pi64 a, pi64 b) {
    if (a.fi != b.fi) return max(a, b);
    return {a.fi, a.se + b.se};
}

i64 ins(i64 l, pi64 s) {
    if (l > s.fi) return 0;
    if (s.se > 1) return 2;
    return (s.fi == l ? 1 : 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    p10[0] = 1;
    forn(i, 18) p10[i + 1] = p10[i] * 10;

    int T;
    cin >> T;
    while (T--) {
        cin >> L >> S;
        ford(i, L) cin >> let[i];
        repr = string(L, '0');
        forn(i, L) repr[i] = let[i][S / p10[i] % 10];
        stable[L] = mp(1, 1);
        match[L] = 1;
        ford(i, L) {
            match[i] = 0;
            auto &now = stable[i], nxt = stable[i + 1];
            forn(d, 10) if (let[i][d] == repr[i]) match[i] += match[i + 1];
            if (let[i] == string(10, let[i][0])) {
                now = nxt;
                now.fi *= 10;
                continue;
            }
            now = mp(0, 0);
            forn(d, 10) {
                if (let[i][d] != repr[i]) continue;
                bool cross = false;
                int tr = 0;
                while (1) {
                    int dd = d + tr;
                    if (let[i][dd % 10] != repr[i]) break;
                    if (dd >= 10) {
                        if (nxt.fi == 1) break;
                        cross = true;
                        dd -= 10;
                    }
                    ++tr;
                }
                pi64 to_add;
                if (!cross) to_add = mp(tr, match[i + 1]);
                else to_add = {10 * (nxt.fi - 2) + tr, nxt.se};
                now = now + to_add;
            }
        }

        forn(i, L) {
            change[i] = p10[L];
            forn(d, 10) {
                if (let[i][d] == let[i][(d + 1) % 10]) continue;
                i64 x = S / p10[i + 1] * p10[i + 1] + (d + 1) * p10[i];
                if (x <= S) x += p10[i + 1];
                uin(change[i], x);
            }
//            cerr << change[i] << ' ';
        }
//        cerr << '\n';

        i64 l = -1, r = p10[L] - S;
        while (r - l > 1) {
            i64 M = (l + r) / 2;
            int last_change = -1;
            forn(i, L) if (change[i] <= S + M) last_change = i;
            i64 found = 0;
//            cerr << "M = " << M << ' ' << last_change << '\n';
            if (last_change == -1) found = ins(M + 1, stable[0]);
            else {
                i64 ls = (S + M) / p10[last_change] - S / p10[last_change] + 1;
//                cerr << ls << '\n';
                int ds = S / p10[last_change] % 10;
                string seen(min(10LL, ls), '0');
                forn(i, seen.size()) seen[i] = let[last_change][(ds + i) % 10];
//                i64 since = S + M - change[i];
                forn(d, 10) {
                    string must_see(seen.size(), 'a');
                    forn(i, seen.size()) must_see[i] = let[last_change][(d + i) % 10];
//                    cerr << ds << ' ' << d << ' ' << seen << ' ' << must_see << '\n';
                    if (seen != must_see) continue;
                    i64 efl = (d + ls - 1) / 10 + 1;
//                    cerr << d << ' ' << efl << ' ' << stable[last_change + 1].fi << ' ' << stable[last_change + 1].se << '\n';
                    found += ins(efl, stable[last_change + 1]);
                }
            }
//            cerr << M << ' ' << found << '\n';
            (found == 1 ? r : l) = M;
        }
        cout << r << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}