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
    int a, b, c, ab, bc, abc;

    TRes()
        : a(0)
        , b(0)
        , c(0)
        , ab(0)
        , bc(0)
        , abc(0)
    {
    }

    TRes(char C) {
        a = b = c = ab = bc = abc = 0;
        if (C == 'a') a = 1;
        if (C == 'b') b = 1;
        if (C == 'c') c = 1;
    }

    TRes operator+(const TRes &r) const {
/*        print();
        cerr << "+\n";
        r.print();
        cerr << "=\n";*/
        TRes res;
        res.a = a + r.a;
        res.b = b + r.b;
        res.c = c + r.c;
        res.ab = min(a + r.ab, ab + r.b);
        uin(res.ab, a + r.b);
        res.bc = min(b + r.bc, bc + r.c);
        uin(res.bc, b + r.c);
        res.abc = min(a + r.abc, min(ab + r.bc, abc + r.c));
        uin(res.abc, a + r.bc);
        uin(res.abc, ab + r.c);
        uin(res.ab, min(res.a, res.b));
        uin(res.bc, min(res.b, res.c));
        uin(res.abc, min(res.ab, res.bc));
        res.print();
        return res;
    }

    void print() const {
//        cerr << a << ' ' << b << ' ' << c << ' ' << ab << ' ' << bc << ' ' << abc << '\n';
    }
};

struct TNode {
    int L, R;
    int l, r;
    TRes res;
};

const int maxn = 110000;
TNode t[2 * maxn];
int tc = 0;

string s;

#define dn TNode &n = t[node]

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, TRes()};
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        n.res = t[n.l].res + t[n.r].res;
    } else n.res = TRes(s[L]);
    return node;
}

void change(int node, int i, char c) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        n.res = TRes(c);
        return;
    }
    change(n.l, i, c);
    change(n.r, i, c);
    n.res = t[n.l].res + t[n.r].res;
//    cerr << n.L << ' ' << n.R << '\n';
//    n.res.print();
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
    cin >> n >> q >> s;
    int root = buildTree(0, n);
    while (q--) {
        int p;
        char c;
        cin >> p >> c;
        --p; 
        s[p] = c;
        change(root, p, c);
        t[root].res.print();
        cout << t[root].res.abc << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}