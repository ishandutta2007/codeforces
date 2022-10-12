#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

using ld = long double;

ld eps = 1e-9;

struct func {
    ld a, b, c; // ax^2 + bx + c
    ld l, r; // on the interval [l, r]

    func shift(ld d) {
        return {a, b-2*a*d, a*d*d-b*d+c, l+d, r+d};
    }

    void shift_in_place(ld d) {
        c += a*d*d-b*d;
        b -= 2*a*d;
        l += d;
        r += d;
    }

    ld vertex() {
        return a == 0 ? (l+r)/2 : -b/(2*a);
    }

    ld eval(ld x) {
        return a*x*x+b*x+c;
    }

    bool check() {
        if (a == 0) return 0;
        return -b > (r+eps)*2*a;
    }
};

const int N = 20000;
func v[N];
int v_len = 1;

ld find_vertex() {
    int j = 0;
    while (j+1 < v_len && v[j].check())
        j++;
    return min(v[j].r, max(v[j].l, v[j].vertex()));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    ld k, a, b; cin >> k >> a >> b;
    v[0] = {0, 0, 0, -inf_ll, inf_ll};
    vector<ll> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    vector<ld> m(n);
    for (int i = 0; i < n; i++) {
        // split the function at vertex, fill the gap with horizontal line
        if (i%100 == 0) debug(i);
        m[i] = find_vertex();
        // debug(m[i]);
        bool did_expand = 0;
        for (int j = 0; j < v_len; j++) {
            // debug(j, v[j].l, v[j].r);
            if (m[i] < v[j].l || did_expand) {
                v[j].shift_in_place(b);
            } else if (m[i] > v[j].r) {
                v[j].shift_in_place(a);
            } else {
                did_expand = 1;
                auto f = v[j];
                auto p = f.shift(a), q = f.shift(b);
                p.r = m[i]+a, q.l = m[i]+b;
                int mv = m[i] == f.l || m[i] == f.r ? 1 : 2;
                // debug(j, mv, v_len);
                memmove(v+j+mv, v+j, (v_len-j) * sizeof(func));
                if (m[i] != f.l) v[j++] = p;
                v[j++] = {0, 0, f.eval(m[i]), m[i]+a, m[i]+b};
                if (m[i] != f.r) v[j++] = q;
                j--;
                v_len += mv;
            }
        }
        int jj = 0;
        int tmp = 0;
        for (int j = 0; j < v_len; j++) {
            auto& f = v[j];
            f.a += 1;
            f.b -= 2*x[i];
            f.c += x[i]*x[i];
            f.l = max(f.l, ld(1));
            f.r = max(f.r, ld(1));
            f.l = min(f.l, ld(k));
            f.r = min(f.r, ld(k));
            if (f.l != f.r) v[jj++] = v[j];
            else tmp++;
        }
        v_len -= tmp;
        // debug(v_len);
        // for (int j = 0; j < v_len; j++)
        //     debug(v[j].l, v[j].r);
    }
    vector<ld> y(n+1);
    y[n] = find_vertex();
    for (int i = n; i > 0; i--)
        y[i-1] = min(max(m[i-1], y[i]-b), y[i]-a);
    ld ans = 0;
    cout << setprecision(10) << fixed;
    for (int i = 1; i <= n; i++) {
        cout << y[i] << " ";
        ans += (y[i]-x[i-1])*(y[i]-x[i-1]);
    }
    cout << "\n" << ans << "\n";
}