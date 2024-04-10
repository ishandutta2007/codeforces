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

pii operator+(pii s1, pii s2) {
    return mp(s2.fi == -1 ? s1.fi : s2.fi, s2.se);
}

struct TState {
    pii p[2];

    TState operator+(TState rhs) const {
        TState res;
        forn(i, 2) res.p[i] = p[i] + rhs.p[p[i].se];
        return res;
    }
};

string colors[7] = {"red", "orange", "yellow", "green", "blue", "indigo", "violet"};

TState from_string(string s) {
    if (s == "lock") return {{{-1, 1}, {-1, 1}}};
    if (s == "unlock") return {{{-1, 0}, {-1, 0}}};
    int c = find(colors, colors + 7, s) - colors;
    return {{{c, 0}, {-1, 1}}};
}

const int maxn = 110000;
string s[maxn];

struct TNode {
    int L, R;
    int l, r;
    TState st;
};

TNode t[2 * maxn];
int tc = 0;

#define dn TNode &n = t[node]

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {}};
    if (R - L == 1) n.st = from_string(s[L]);
    else {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        n.st = t[n.l].st + t[n.r].st;
    }
    return node;
}

void change(int node, int i) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        n.st = from_string(s[i]);
        return;
    }
    change(n.l, i);
    change(n.r, i);
    n.st = t[n.l].st + t[n.r].st;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    TState init = from_string("blue");

    int n;
    cin >> n;
    forn(i, n) cin >> s[i];
    int node = buildTree(0, n);

    cout << colors[(init + t[node].st).p[0].fi] << '\n';

    int q;
    if (cin >> q) {
        while (q--) {
            int i;
            cin >> i >> s[--i];
            change(node, i);
            cout << colors[(init + t[node].st).p[0].fi] << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}