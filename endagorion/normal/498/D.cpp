#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

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
    int times[60];
    int L, R;
    int left, right;

    TNode(int L = 0, int R = 0, int x = 2)
        : L(L)
        , R(R)
        , left(-1)
        , right(-1)
    {
        forn(i, 60) times[i] = (i % x == 0 ? 2 : 1);
    }

    void set_sum(TNode &l, TNode &r) {
        forn(i, 60) {
            times[i] = l.times[i] + r.times[(i + l.times[i]) % 60];
        }
    }
};

TNode t[300000];
int tc = 0;
int a[100000];

int build_tree(int L, int R) {
    int node = tc++;
    if (R - L == 1) {
        t[node] = TNode(L, R, a[L]);
        return node;
    }
    t[node] = TNode(L, R);
    int M = (L + R) / 2;
    t[node].left = build_tree(L, M);
    t[node].right = build_tree(M, R);
    t[node].set_sum(t[t[node].left], t[t[node].right]);
    return node;
}

void make_query(int node, int L, int R, int &tt) {
    if (max(L, t[node].L) >= min(R, t[node].R)) return;
    if (L <= t[node].L && t[node].R <= R) {
        tt += t[node].times[tt % 60];
        return;
    }
    make_query(t[node].left, L, R, tt);
    make_query(t[node].right, L, R, tt);
}

void change(int node, int i, int x) {
    if (i < t[node].L || i >= t[node].R) return;
    if (i == t[node].L && t[node].R - t[node].L == 1) {
        t[node] = TNode(t[node].L, t[node].R, x);
        return;
    }
    change(t[node].left, i, x);
    change(t[node].right, i, x);
    t[node].set_sum(t[t[node].left], t[t[node].right]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N;
    cin >> N;
    forn(i, N) cin >> a[i];
    build_tree(0, N);
    int Q;
    cin >> Q;
    forn(i, Q) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        if (c == 'A') {
            --x; --y;
            int tt = 0;
            make_query(0, x, y, tt);
            cout << tt << '\n';
        } else {
            --x;
            change(0, x, y);
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}