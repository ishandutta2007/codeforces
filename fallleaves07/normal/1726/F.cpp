#include<bits/stdc++.h>
using namespace std;
using LL = long long;

struct List {
    int n;
    map<int, pair<LL, LL>> lst;
    List(int n) {
        this->n = n;
        lst[0] = make_pair(0ll, 0ll);
    }
    void cover(int cl, int cr, LL k, LL b) {
        auto p = lst.lower_bound(cl);
        pair<LL, LL> rval;
        if (p != lst.begin()) {
            auto q = p;
            rval = (--q)->second;
        }
        while (p != lst.end() && p->first <= cr) {
            rval = p->second;
            lst.erase(p++);
        }
        if (cr + 1 < n && !lst.count(cr + 1)) {
            lst[cr + 1] = rval;
        }
        lst[cl] = make_pair(k, b);
    }
    LL get(int x) {
        auto [k, b] = (--lst.upper_bound(x))->second;
        return 1ll * k * x + b;
    }
    LL query() {
        LL val = 4.5e18;
        int lbound = 0;
        pair<LL, LL> lf;
        for (auto [x, f] : lst) {
            if (lbound < x) {
                val = min(val, min(lf.first * lbound, lf.first * (x - 1)) + lf.second);
            }
            lbound = x, lf = f;
        }
        if (lbound < n) {
            val = min(val, min(lf.first * lbound, lf.first * (n - 1)) + lf.second);
        }
        return val;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, t;
    cin >> n >> t;
    vector<int> g(n), c(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i] >> c[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> d[i];
    }
    List tr(t);

    auto cover = [&](int l, int r, LL val) {
        if (l <= r) {
            tr.cover(l, r, -1, val + r + 1);
        } else {
            tr.cover(l, t - 1, -1, val + r + t + 1);
            tr.cover(0, r, -1, val + r + 1);
        }
    };
    LL dtot = 0;
    for (int i = n - 1; i >= 0; i--) {
        dtot += d[i];
        int l = ((0ll - c[i] + dtot + g[i]) % t + t) % t, r = (l + t - g[i]) % t;
        cover(l, (r - 1 + t) % t, tr.get(r));
    }
    printf("%lld\n", tr.query() + dtot);
    return 0;
}