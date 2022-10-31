#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 3e5 + 100;

struct node {
    int mn, cnt, add;
    node (int mn = INF, int cnt = 0, int add = 0) : mn(mn), cnt(cnt), add(add) {}
};

node tree[N * 4];

void push(int v) {
    tree[v * 2 + 1].add += tree[v].add;
    tree[v * 2 + 2].add += tree[v].add;
    tree[v].add = 0;
}

node operator+ (node a, node b) {
    if (a.mn + a.add == b.mn + b.add) {
        return node(a.mn + a.add, a.cnt + b.cnt);
    } else {
        return (a.mn + a.add < b.mn + b.add) ? node(a.mn + a.add, a.cnt) : node(b.mn + b.add, b.cnt);
    }
}

void build(int v, int vl, int vr) {
    if (vl == vr) {
        tree[v] = node(INF, 0);
    } else if (vr == vl + 1) {
        tree[v] = node(0, 1);
    } else {
        int mid = (vl + vr) / 2;
        build(v * 2 + 1, vl, mid);
        build(v * 2 + 2, mid, vr);
        tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
    }
}

void upd(int v, int vl, int vr, int l, int r, int add) {
    if (vl >= r || vr <= l) {
        return;
    } else if (vl >= l && vr <= r) {
        tree[v].add += add;
    } else {
        int mid = (vl + vr) / 2;
        push(v);
        upd(v * 2 + 1, vl, mid, l, r, add);
        upd(v * 2 + 2, mid, vr, l, r, add);
        tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
    }
}

int n;
vector<pair<int, int> > v;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    v.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &v[i].fs, &v[i].sc);
    }
    sort(all(v));

    vector<int> val(n);
    for (int i = 0; i < n; i++) {
        val[i] = v[i].sc;
    }

    build(0, 0, n + 1);

    vector<int> mx, mn;
    ll ans = 0;
    mx.pb(-1);
    mn.pb(-1);
    for (int i = 0; i < n; i++) {
        while (mx.back() != -1 && val[mx.back()] <= val[i]) {
            upd(0, 0, n + 1, mx[mx.size() - 2] + 1, mx.back() + 1, -val[mx.back()]);
            mx.pop_back();
        }
        upd(0, 0, n + 1, mx.back() + 1, i + 1, val[i]);
        mx.pb(i);

        while (mn.back() != -1 && val[mn.back()] >= val[i]) {
            upd(0, 0, n + 1, mn[mn.size() - 2] + 1, mn.back() + 1, val[mn.back()]);
            mn.pop_back();
        }
        upd(0, 0, n + 1, mn.back() + 1, i + 1, -val[i]);
        mn.pb(i);
        upd(0, 0, n + 1, 0, i, -1);

        ans += tree[0].cnt - n + i;
    }

    cout << ans << endl;

    return 0;
}