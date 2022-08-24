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

unordered_map<i64, string> shortest;
set<i64> shortL[11];

bool update(i64 n, string s) {
    if (s.size() >= to_string(n).size()) return false;
    bool have = shortest.count(n);
    if (!have || shortest[n].size() > s.size()) {
        if (have) {
            int oldL = shortest[n].size();
            shortL[oldL].erase(n);
        }
        shortest[n] = s;
        shortL[s.size()].insert(n);
        return true;
    }
    return false;
}

i64 deg(i64 x, i64 d) {
    i64 y = 1;
    while (d) {
        if (d & 1) y *= x;
        d /= 2; x *= x;
    }
    return y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    i64 n;
    cin >> n;
    for (int b = 2; b <= 40; ++b) {
        for (i64 p = 2; deg(p, b) <= n; ++p) update(deg(p, b), to_string(p) + "^" + to_string(b));
    }
    for1(l1, 7) for1(l2, 8 - l1) {
        for (auto n1: shortL[l1]) {
            auto s1 = shortest[n1];
            for (auto n2: shortL[l2]) {
                if (n1 * n2 > n) break;
                auto s2 = shortest[n2];
                update(n1 * n2, s1 + "*" + s2);
            }
        }
    }

    vi64 d10(11);
    forn(i, 11) d10[i] = deg(10, i);

    for1(l, 10) cerr << l << ' ' << shortL[l].size() << '\n';
/*    for (int l = 8; l >= 3; --l) {
        cerr << l << '\n';
        for (auto x: shortL[l]) {
            string sx = shortest[x];
            for1(l1, 9 - l) {
                i64 lb = d10[l1], ub = d10[l1 + 1] - 1;
                uin(ub, n / x);
                uax(lb, (d10[l + l1 + 1] - 1) / x + 1);
//                uin(ub, (d10[l + l1 + 1] - 1) / x);
                for (i64 m = lb; m <= ub; ++m) update(m * x, sx + "*" + to_string(m));
            }
        }
    }*/

    string ans = to_string(n);
    auto update_ans = [&](const string &s){if (s.size() < ans.size()) ans = s;};
    auto get_shortest = [&](i64 n){return shortest.count(n) ? shortest[n] : to_string(n);};

    if (shortest.count(n)) ans = shortest[n];
    for (auto [x, s]: shortest) {
        if (x < n) update_ans(s + "+" + get_shortest(n - x));
    }

    for (i64 x = 2; x * x <= n; ++x) {
        if (n % x) continue;
        string s1 = get_shortest(x);
        string s2 = get_shortest(n/x);
        for (i64 y = 2; y * y <= n / x; ++y) {
            if (n / x % y) continue;
            string t1 = get_shortest(y);
            string t2 = get_shortest(n / x / y);
            string u = t1 + "*" + t2;
            if (u.size() < s2.size()) s2 = u;
        }
        update_ans(s1 + "*" + s2);
    }

    for1(l, 5) {
        cerr << l << '\n';
        for (auto x: shortL[l]) {
            i64 ub = d10[6 - l] - 1;
            uin(ub, n / x);
            auto sx = shortest[x];
            for (i64 y = 2; y <= ub; ++y) {
                i64 md = n - x * y;
                string s = get_shortest(y) + "*" + sx;
                if (md) s += "+" + get_shortest(md);
                update_ans(s);
            }
        }
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}