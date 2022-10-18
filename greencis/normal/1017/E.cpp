#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
vector<pii> a, b;

inline bool cw(const pii& a, const pii& b, const pii& c) {
    return a.first * ll(b.second - c.second) + b.first * ll(c.second - a.second) + c.first * ll(a.second - b.second) < 0;
}

inline bool ccw(const pii& a, const pii& b, const pii& c) {
    return a.first * ll(b.second - c.second) + b.first * ll(c.second - a.second) + c.first * ll(a.second - b.second) > 0;
}

vector<pii> convex_hull(vector<pii> v) {
    sort(all(v));
    vector<pii> up(1, v[0]), down(1, v[0]);
    for (size_t i = 1; i < v.size(); ++i) {
        if (i + 1 == v.size() || cw(v[0], v[i], v.back())) {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up.back(), v[i]))
                up.pop_back();
            up.push_back(v[i]);
        }
        if (i + 1 == v.size() || ccw(v[0], v[i], v.back())) {
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down.back(), v[i]))
                down.pop_back();
            down.push_back(v[i]);
        }
    }
    for (int i = (int)down.size() - 2; i >= 1; --i)
        up.push_back(down[i]);
    return up;
}

vector<pll> seq(vector<pii> v) {
    int n = (int)v.size();
    v.push_back(v[0]);
    v.push_back(v[1]);
    vector<pll> ans;
    for (int i = 0; i < n; ++i) {
        ll ax = v[i + 1].first - v[i].first;
        ll ay = v[i + 1].second - v[i].second;
        ll bx = v[i + 2].first - v[i + 1].first;
        ll by = v[i + 2].second - v[i + 1].second;
        ll dot_product = ax * bx + ay * by;
        ld qqq = dot_product / (sqrtl(ax * ax + ay * ay) * sqrtl(bx * bx + by * by));
        ans.push_back({ax * ax + ay * ay, (ll)roundl(qqq * (ll)1e16)});
    }
    return ans;
}

vector<pll> min_lex_shift(vector<pll> v) {
    vector<pll> ansv;
    int n = (int)v.size();
    for (int i = 0; i < n; ++i)
        v.push_back(v[i]);
    n *= 2;
    int ans = 0;
    for (int i = 0; i + i < n; ) {
        ans = i;
        int j = i + 1, k = i;
        while (j < n && v[k] <= v[j]) {
            if (v[k] < v[j])
                k = i;
            else
                ++k;
            ++j;
        }
        while (i <= k)
            i += j - k;
    }
    for (int i = 0; i + i < n; ++i)
        ansv.push_back(v[ans + i]);
    return ansv;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a.emplace_back(x, y);
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        b.emplace_back(x, y);
    }

    a = convex_hull(a);
    b = convex_hull(b);

    vector<pll> av = seq(a);
    vector<pll> bv = seq(b);

    av = min_lex_shift(av);
    bv = min_lex_shift(bv);

    if (av == bv)
        cout << "YES\n";
    else
        cout << "NO\n";
}