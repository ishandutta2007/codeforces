#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T>
bool uin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

struct TNode {
    int nxt[4];
    int len, link;

    TNode() {
        forn(i, 4) nxt[i] = -1;
        len = link = -1;
    }
};

const int MAXT = 300000;
TNode t[MAXT];

int tc = 0;
int newNode() {
    return tc++;
}

int append(int last, int c) {
    c -= 'A';
    int nlast = newNode();
    t[nlast].len = t[last].len + 1;
    int p;
    for (p = last; p >= 0 && t[p].nxt[c] == -1; p = t[p].link) {
        t[p].nxt[c] = nlast;
    }
    if (p == -1) {
        t[nlast].link = 0;
        return nlast;
    }
    int q = t[p].nxt[c];
    if (t[q].len == t[p].len + 1) {
        t[nlast].link = q;
        return nlast;
    }
    int clone = newNode();
    forn(i, 4) t[clone].nxt[i] = t[q].nxt[i];
    t[clone].len = t[p].len + 1;
    t[clone].link = t[q].link;
    t[q].link = t[nlast].link = clone;
    for (; p >= 0 && t[p].nxt[c] == q; p = t[p].link) {
        t[p].nxt[c] = clone;
    }
    return nlast;
}

int d[MAXT];
const i64 LIM = 2e18;

i64 prod_large(i64 a, i64 b, i64 c) {
    return a >= (c + b - 1) / b;
}

vvi64 mul(const vvi64 &a, const vvi64 &b) {
    int n = a.size();
    vvi64 c(n, vi64(n, LIM));
    forn(i, n) forn(j, n) forn(k, n) {
        uin(c[i][k], a[i][j] + b[j][k]);
    }
    return c;
}

vvi64 id() {
    vvi64 res(4, vi64(4, LIM));
    forn(i, 4) res[i][i] = 0;
    return res;
}

bool fits(const vvi64 &a, i64 N) {
    for (vi64 b: a) for (i64 x: b) if (x <= N) return true;
    return false;
}

void maxd(vvi64 &a, i64 N, i64 &d) {
    if (!fits(a, N)) {
        d = 0;
        a = id();
        return;
    }
    vvi64 b = a;
    a = mul(a, a);
    maxd(a, N, d);
    d *= 2;
    if (fits(mul(a, b), N)) {
        a = mul(a, b);
        ++d;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int last = newNode();
    t[last].len = 0;
    i64 N;
    string s;
    cin >> N >> s;
    for (char c: s) {
        last = append(last, c);
    }
    vvi64 m(4, vi64(4, LIM));
    forn(i, 4) {
        if (t[0].nxt[i] == -1) {
            cout << N << '\n';
            return 0;
        }
        vi q;
        int cur = 0;
        q.pb(t[0].nxt[i]);
        forn(v, tc) d[v] = 1e9;
        d[q[0]] = 1;
        while (cur < q.size()) {
            int v = q[cur++];
            forn(j, 4) {
                int u = t[v].nxt[j];
                if (u == -1) uin(m[i][j], (i64)d[v]);
                else if (d[u] > d[v] + 1) {
                    d[u] = d[v] + 1;
                    q.pb(u);
                }
            }
        }
    }
/*    forn(i, 4) {
        forn(j, 4) cerr << m[i][j] << ' ';
        cerr << '\n';
    }*/
    i64 d = 0;
    maxd(m, N - 1, d);
    cout << d + 1 << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}