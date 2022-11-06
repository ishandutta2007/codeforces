#include<bits/stdc++.h>
using LL = long long;
const LL inf = 4.5e18;

void solve(void) {
    int n, m;
    std::cin >> n >> m;
    struct P {
        int x, v, id;
        bool operator<(const P &b) const {
            return x < b.x;
        }
    };
    std::vector<P> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i].x >> p[i].v;
        p[i].id = i;
    }
    std::sort(p.begin(), p.end());
    std::vector<int> loc(n), xid(n);
    int idc = 0;
    for (int i = 0; i < (int)p.size(); i++) {
        if (i == 0 || p[i].x > p[i - 1].x) {
            loc[i] = idc++, xid[loc[i]] = p[i].x;
        } else {
            loc[i] = loc[i - 1];
        }
    }
    std::vector<LL> val(idc);
    std::multiset<LL> vs;
    LL sum = 0;
    for (int i = 0, j = 0; i < idc; i++) {
        int x = xid[i];
        for (; j < n && p[j].x <= x; ++j) {
            vs.insert(p[j].v + p[j].x), sum += p[j].v + p[j].x;
        }
        while (!vs.empty() && *vs.begin() <= x) {
            sum -= *vs.begin();
            vs.erase(vs.begin());
        }
        val[i] += sum - 1ll * x * vs.size();
    }
    vs.clear(), sum = 0;
    for (int i = idc - 1, j = n - 1; i >= 0; i--) {
        int x = xid[i];
        for (; j >= 0 && p[j].x > x; --j) {
            vs.insert(p[j].v - p[j].x), sum += p[j].v - p[j].x;
        }
        while (!vs.empty() && *vs.begin() + x <= 0) {
            sum -= *vs.begin();
            vs.erase(vs.begin());
        }
        val[i] += sum + 1ll * x * vs.size();
    }
    std::vector<LL> need(idc);
    LL preneed = -inf, lstx = xid[0];
    for (int i = 0; i < idc; i++) {
        preneed += xid[i] - lstx;
        lstx = xid[i];
        if (val[i] > m) {
            preneed = std::max(preneed, val[i] - m);
        }
        need[i] = std::max(need[i], preneed);
    }
    LL sufneed = -inf;
    lstx = xid[idc - 1];
    for (int i = idc - 1; i >= 0; i--) {
        sufneed += lstx - xid[i];
        lstx = xid[i];
        if (val[i] > m) {
            sufneed = std::max(sufneed, val[i] - m);
        }
        need[i] = std::max(need[i], sufneed);
    }
    std::vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (p[i].v >= need[loc[i]]) {
            ans[p[i].id] = 1;
        } else {
            ans[p[i].id] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d", ans[i]);
    }
    puts("");
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}