#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, x[300105], y[300105];
pii p[300105];
const int inf = 1e8;

struct node {
    node *L, *R;
    int mnx, mny, mxy;

    node() : L(nullptr), R(nullptr), mnx(1e9), mny(1e9), mxy(-1e9) { }
};

inline void recalc(node *t) {
    if (t) {
        if (t->L) {
            t->mnx = min(t->mnx, t->L->mnx);
            t->mny = min(t->mny, t->L->mny);
            t->mxy = max(t->mxy, t->L->mxy);
        }
        if (t->R) {
            t->mnx = min(t->mnx, t->R->mnx);
            t->mny = min(t->mny, t->R->mny);
            t->mxy = max(t->mxy, t->R->mxy);
        }
    }
}

void update(node *t, int tl, int tr, int idx, int x, int y) {
    if (tl == tr) {
        t->mnx = min(t->mnx, x);
        t->mny = min(t->mny, y);
        t->mxy = max(t->mxy, y);
    } else {
        int tm = (tl + tr) >> 1;
        if (idx <= tm) {
            if (!t->L) t->L = new node();
            update(t->L, tl, tm, idx, x, y);
        } else {
            if (!t->R) t->R = new node();
            update(t->R, tm + 1, tr, idx, x, y);
        }
        recalc(t);
    }
}

pair<int, pii> get(node *t, int tl, int tr, int l, int r) {
    if (!t || l > r) return {1e9, {1e9, -1e9}};
    if (l == tl && r == tr)
        return {t->mnx, {t->mny, t->mxy}};
    int tm = (tl + tr) >> 1;
    auto p1 = get(t->L, tl, tm, l, min(r, tm));
    auto p2 = get(t->R, tm + 1, tr, max(l, tm + 1), r);
    return {min(p1.first, p2.first), {min(p1.second.first, p2.second.first),
                                      max(p1.second.second, p2.second.second)}};
}

void destroy(node *t) {
    if (t) {
        destroy(t->L);
        destroy(t->R);
        delete t;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        p[i] = {x[i], y[i]};
    }
    int mnx = *min_element(x, x + n);
    int mxx = *max_element(x, x + n);
    int mny = *min_element(y, y + n);
    int mxy = *max_element(y, y + n);
    int bigans = 2 * (mxx - mnx + mxy - mny);

    int ans = -1e9;
    sort(p, p + n);
    for (int zzz = 0; zzz < 2; ++zzz) {
        node *t = new node();
        for (int i = 0; i < n; ++i) {
            auto qqq = get(t, -inf, inf, -inf, p[i].second);
            if (abs(qqq.first) < 1e9) {
                ans = max(ans, p[i].first - qqq.first + p[i].second - qqq.second.first);
            }
            qqq = get(t, -inf, inf, p[i].second, inf);
            if (abs(qqq.first) < 1e9) {
                ans = max(ans, p[i].first - qqq.first - p[i].second + qqq.second.second);
            }
            update(t, -inf, inf, p[i].second, p[i].first, p[i].second);
            p[i].first = -p[i].first;
        }
        reverse(p, p + n);
        destroy(t);
    }

    cout << ans * 2;
    for (int i = 4; i <= n; ++i)
        cout << " " << bigans;
    cout << endl;
}