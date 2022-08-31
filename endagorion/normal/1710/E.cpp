#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int N = 200002;

int n, m, md;
vector<int> a, b;
int apos, bpos, astart, bstart;

int c[N];
int d[N];

ll sc[N];   

ll eval(int x, int y) {
    int b = d[y];
    int wb = min(b, x);
    ll win = wb * ll(y) + sc[x] - sc[wb];
    int lb = max(b, x);
    ll lose = ll(n - lb) * (m - y) + ll(m) * (lb - x) - (sc[lb] - sc[x]);
    return win + lose; 
}

void build() {
    n = a.size(), m = b.size();

    c[n + 1] = 0;
    int bp = 0;
    for (int i = n - 1; i >= 0; --i) {
        while (bp < m && a[i] + b[bp] <= md) {
            ++bp;
        }

        c[i + 1] = bp;
    }

    c[0] = m;

    sc[0] = 0;
    for (int i = 1; i <= n; ++i) {
        sc[i] = sc[i - 1] + c[i];
    }

    d[m + 1] = 0;
    int ap = 0;
    for (int i = m - 1; i >= 0; --i) {
        while (ap < n && a[ap] + b[i] <= md) {
            ++ap;
        }

        d[i + 1] = ap;
    }

    d[0] = n;
}

ll full() {
    build();

    ll ans = 0;
    for (int x = 0; x <= n; ++x) {
        ans = max(ans, eval(x, c[n - x]));
    }

    return ans;
}

ll semi() {
    int ga = upper_bound(a.begin(), a.end(), md - bstart) - a.begin();
    int gb = upper_bound(b.begin(), b.end(), md - astart) - b.begin();

    build();

    ll ans = 0;
    for (int x = 0; x <= n; ++x) {
        { // not taken 
            int y = c[n - x + 1];
            ll cur = eval(x, y);
            int dy = max(y, gb);
            cur += m - dy;
            cur += max(min(ga, x), n - max(ga, x));
            ans = max(ans, cur);
        }

        { // taken
            int y = c[n - x];
            ll cur = eval(x, y);
            int dy = min(y, gb);
            cur += dy;
            cur += max(min(ga, x), n - max(ga, x));
            ans = max(ans, cur);
        }
    }

    return ans;
}

bool check(const vector<int>& a, const vector<int>& b) {
    ::a = a;
    ::b = b;

    ll fl = full();

    ::a.erase(::a.begin() + apos);
    ::b.erase(::b.begin() + bpos);

    ll sm = semi();
    assert(fl == sm + 1 || fl == sm);

    return fl != sm;
}

int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int& x:a) {
        cin >> x;
    }

    for (int& x: b) {
        cin >> x;
    }

    astart = a[0], bstart = b[0];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    apos = lower_bound(a.begin(), a.end(), astart) - a.begin();
    bpos = lower_bound(b.begin(), b.end(), bstart) - b.begin();

    int l = 0, r = astart + bstart;
    while (l + 1 < r) {
        md = (l + r) / 2;
        (check(a, b) ? l : r) = md;
    }

    cout << r << "\n";
}