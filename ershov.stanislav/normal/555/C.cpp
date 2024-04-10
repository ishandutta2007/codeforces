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

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 5e5 + 100;

int treeU[N * 4], treeL[N * 4];

void upd(int * tree, int v, int vl, int vr, int l, int r, int mx) {
    if (vr <= l || vl >= r) {
        return;
    }
    if (l <= vl && r >= vr) {
        tree[v] = max(tree[v], mx);
    } else {
        int mid = (vl + vr) / 2;
        upd(tree, v * 2 + 1, vl, mid, l, r, mx);
        upd(tree, v * 2 + 2, mid, vr, l, r, mx);
    }
}

int get(int * tree, int v, int vl, int vr, int i) {
    if (vl > i || vr <= i) {
        return 0;
    }
    if (vl == i && vr == i + 1) {
        return tree[v];
    } else {
        int mid = (vl + vr) / 2;
        return max(tree[v], max(get(tree, v * 2 + 1, vl, mid, i), get(tree, v * 2 + 2, mid, vr, i)));
    }
}

int n, q;
pair<int, char> qs[N];
vector<int> v;

int geti(int a) {
    return (int) (lower_bound(all(v), a) - v.begin());
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &q);
    for (int i = 0; i < q; i++) {
        int a;
        scanf("%d%d %c", &qs[i].fs, &a, &qs[i].sc);
        v.pb(qs[i].fs);
    }
    v.pb(-10);
    v.pb(1e9 + 100);
    sort(all(v));
    v.resize(distance(v.begin(), unique(all(v))));
    int all = (int) v.size();
    for (int i = 0; i < q; i++) {
        if (qs[i].sc == 'U') {
            int up = get(treeU, 0, 0, all, geti(qs[i].fs));
            printf("%d\n", n + 1 - qs[i].fs - up);
            upd(treeL, 0, 0, all, geti(qs[i].fs), geti(n + 1 - up), qs[i].fs);
            upd(treeU, 0, 0, all, geti(qs[i].fs), geti(qs[i].fs) + 1, n + 1 - qs[i].fs);
        } else {
            int left = get(treeL, 0, 0, all, geti(qs[i].fs));
            printf("%d\n", qs[i].fs - left);
            upd(treeU, 0, 0, all, geti(left), geti(qs[i].fs) + 1, n + 1 - qs[i].fs);
            upd(treeL, 0, 0, all, geti(qs[i].fs), geti(qs[i].fs) + 1, qs[i].fs);
        }
    }
    return 0;
}