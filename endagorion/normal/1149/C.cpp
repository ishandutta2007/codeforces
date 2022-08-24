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

struct TRes {
    int bal;
    int ans, ansp, anss, anssp;
    int maxpref, maxsuf;
    int minpref, minsuf;
    int maxpos, minneg;

    TRes operator+(const TRes &r) const { 
        TRes res;
        res.bal = bal + r.bal;
        res.maxpref = max(maxpref, bal + r.maxpref);
        res.minpref = min(minpref, bal + r.minpref);
        res.maxsuf = max(r.maxsuf, r.bal + maxsuf);
        res.minsuf = min(r.minsuf, r.bal + minsuf);
        res.maxpos = max({maxpos, r.maxpos, maxsuf + r.maxpref});
        res.minneg = min({minneg, r.minneg, minsuf + r.minpref});
        res.anssp = max({-bal + r.anssp, -minpref + r.maxsuf, anssp + r.bal});
        res.ansp = max({-bal + r.ansp, -minpref + r.maxpos, anssp + r.maxpref, ansp});
        res.anss = max({r.anss, -minsuf + r.anssp, -minneg + r.maxsuf, anss + r.bal});
        res.ans = max({r.ans, -minsuf + r.ansp, -minneg + r.maxpos, anss + r.maxpref, ans});
        return res;
    };

    TRes(int x = 1) {
        if (x == 1) {
            bal = ans = ansp = anss = anssp = 1;
            maxpref = maxsuf = maxpos = 1;
            minpref = minsuf = minneg = 0;
        } else {
            bal = -1;
            ans = ansp = anss = anssp = 1;
            maxpref = maxsuf = maxpos = 0;
            minpref = minsuf = minneg = -1;
        }
    }
};

struct TNode {
    int L, R;
    int l, r;

    TRes res;
};

const int maxn = 210000, maxt = 2 * maxn;
TNode t[maxt];
int tc = 0;

string s;

#define dn TNode &n = t[node]

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n.L = L;
    n.R = R;
    if (R - L == 1) n.res = TRes(s[L] == '(' ? 1 : -1);
    else {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        n.res = t[n.l].res + t[n.r].res;
    }
    return node;
}

void change(int node, int i, int x) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) n.res = TRes(x);
    else {
        change(n.l, i, x);
        change(n.r, i, x);
        n.res = t[n.l].res + t[n.r].res;
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

    int n, q;
    cin >> n >> q;
    cin >> s;
    buildTree(0, s.size());
    cout << t[0].res.ans << '\n';
    forn(i, q) {
        int p, q;
        cin >> p >> q;
        --p; --q;
        swap(s[p], s[q]);
        change(0, p, s[p] == '(' ? 1 : -1);
        change(0, q, s[q] == '(' ? 1 : -1);
        cout << t[0].res.ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}