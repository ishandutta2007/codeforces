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
#define all(s) (s).begin(), (s).end()

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

const int N = 2e5 + 200;

int n, m;
pair<int, int> tree[N * 5];
struct segm {
    int l, r, i, len;
    segm(int l = 0, int r = 0, int i = 0, int len = 0) : l(l), r(r), i(i), len(len) {};
};
vector<segm> segms, good;
vector<int> gl, gr;

bool operator< (segm a, segm b) {
    return a.l < b.l || (a.l == b.l && a.r < b.r);
}

void build(int v, int vl, int vr) {
    if (vr <= vl) {
        return;
    } else if (vl == vr - 1) {
        tree[v] = mp(good[vl].len, good[vl].i);
    } else {
        int mid = (vl + vr) / 2;
        build(v * 2 + 1, vl, mid);
        build(v * 2 + 2, mid, vr);
        tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}

pair<int, int> get(int v, int vl, int vr, int l, int r) {
    if (vl >= r || vr <= l) {
        return mp(0, 0);
    } else if (vl >= l && vr <= r){
        return tree[v];
    } else {
        int mid = (vl + vr) / 2;
        return max(get(v * 2 + 1, vl, mid, l, r), get(v * 2 + 2, mid, vr, l, r));
    }
}

int inter(int l1, int r1, int l2, int r2) {
    return max(0, min(r1, r2) - max(l1, l2));
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    segms.resize(n);
    for (int i = 0; i < n; i++) {
        segms[i].i = i + 1;
        scanf("%d%d", &segms[i].l, &segms[i].r);
        segms[i].len = segms[i].r - segms[i].l;
    }
    sort(all(segms));

    for (int i = 0, mx = 0; i < (int) segms.size(); i++) {
        bool flag = false;
        while (good.size() > 0 && good.back().l == segms[i].l) {
            good.pop_back();
            flag = true;
        }
        if (segms[i].r <= mx && !flag) {
            continue;
        }
        good.pb(segms[i]);
        mx = good.back().r;
    }
    gl.resize(good.size());
    gr.resize(good.size());
    for (int i = 0; i < (int) good.size(); i++) {
        gl[i] = good[i].l;
        gr[i] = good[i].r;
    }
    build(0, 0, (int) good.size());

    ll ans = 0;
    int ans_segm = 0, ans_tele = 0;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int l = (int) (upper_bound(all(gl), a) - gl.begin());
        int r = (int) (lower_bound(all(gr), b) - gr.begin());
        pair<int, int> mx = mp(0, 0);
        if (r > l) {
            mx = get(0, 0, (int) good.size(), l, r);
        }
        if (l > 0) {
            mx = max(mx, mp(inter(a, b, good[l - 1].l, good[l - 1].r), good[l - 1].i));
        }
        if (r < (int) good.size()) {
            mx = max(mx, mp(inter(a, b, good[r].l, good[r].r), good[r].i));
        }
        if (mx.fs * 1ll * c > ans) {
            ans = mx.fs * 1ll * c;
            ans_segm = mx.sc;
            ans_tele = i;
        }
    }

    cout << ans << endl;
    if (ans > 0) {
        cout << ans_segm << ' ' << ans_tele << endl;
    }

    return 0;
}