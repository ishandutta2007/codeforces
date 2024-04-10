#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 4e18;

struct line {
    ll k, b;
    mutable double lx = -INF;

    bool operator < (const line &oth) const {
        if (b == INF)
            return k < oth.lx;
        if (oth.b == INF)
            return lx < oth.k;
        return k < oth.k;
    }
};

struct CHT : multiset<line> {
    bool bad(iterator y) {
        if (y == begin())
            return false;
        auto x = prev(y), z = next(y);
        if (z == end())
            return false;
        return (y->b - x->b) * (double)(y->k - z->k) >=
            (z->b - y->b) * (double)(x->k - y->k);
    }
    void calcLx(iterator y) {
        if (y == begin()) {
            y->lx = -INF;
        }
        else {
            auto x = prev(y);
            y->lx = (x->b - y->b) / (double)(y->k - x->k);
        }
    }
    void addLine(line a) {
        auto y = insert(a);
        if (bad(y)) {
            erase(y);
            return;
        }
        while (y != begin() && bad(prev(y)))
            erase(prev(y));
        while (next(y) != end() && bad(next(y)))
            erase(next(y));
        calcLx(y);
        if (next(y) != end())
            calcLx(next(y));
    }

    ll que(ll x) {
        auto it = prev(upper_bound({x, INF}));
        return it->k * x + it->b;
    }
};

struct rect {
    int x, y; 
    ll a;
    rect(int x, int y, ll a) : x(x), y(y), a(a) {}
    bool operator <(const rect &other) const {
        return y < other.y;
    }
};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <rect> r;
    for (int i = 0; i < n; ++i) {
        int x, y; 
        ll a;
        cin >> x >> y >> a;
        r.emplace_back(x, y, a);
    }
    sort(r.begin(), r.end());
    ll ans = -2e18;
    CHT H;
    for (int i = 0; i < n; ++i) {
        int x = r[i].x;
        int y = r[i].y;
        ll a = r[i].a;
        H.addLine({-y, (ll)x * y + -a + (i == 0 ? 0 : max((ll)0, H.que(x)))});
        ans = max(ans, H.que(0));
    }
    cout << ans << '\n';
}