#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 3e5+5;
pair<int, int> p[N];
int n;

struct hx {
    int xl, xr, yl, yr, zl, zr;
};

hx intersect(hx a, hx b) {
    return {max(a.xl, b.xl), min(a.xr, b.xr), max(a.yl, b.yl), min(a.yr, b.yr), max(a.zl, b.zl), min(a.zr, b.zr)};
}

bool empty(hx a) {
    if (a.xl > a.xr || a.yl > a.yr || a.zl > a.zr || a.zl+a.xl > a.yr || a.zr+a.xr < a.yl) return 1;
    if (a.xr == 0 && (a.yr == 0 || a.zr == 0)) return 1;
    if (a.yr == 0 && (a.xr == 0 || a.zl == 0)) return 1;
    return 0;
}

hx from(int x, int y, int r) {
    return {max(0, x-r), x+r, max(0, y-r), y+r, y-r-x, y+r-x};
}

bool chk(int r) {
    hx h = from(p[0].first, p[0].second, r);
    for (int i = 1; i < n; i++)
        h = intersect(h, from(p[i].first, p[i].second, r));
    return !empty(h);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (auto& c : s) {
            if (c == 'B') p[i].first++;
            if (c == 'N') p[i].second++;
        }
    }
    int l = 0, r = 1e6;
    while (l < r) {
        int m = (l+r)/2;
        if (chk(m)) r = m;
        else l = m+1;
    }
    hx h = from(p[0].first, p[0].second, l);
    for (int i = 1; i < n; i++)
        h = intersect(h, from(p[i].first, p[i].second, l));
    pair<int, int> q;
    if (h.zr+h.xl >= h.yl)
        q = {h.xl, min(h.yr, h.zr+h.xl)};
    else
        q = {min(h.xr, h.yl-h.zr), h.yl};
    if (q == pair{0, 0}) q = {1, 1};
    string s = "";
    for (int i = 0; i < q.first; i++)
        s += 'B';
    for (int i = 0; i < q.second; i++)
        s += 'N';
    cout << l << "\n" << s << "\n";
}