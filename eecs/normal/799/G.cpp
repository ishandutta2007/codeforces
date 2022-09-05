#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld pi = acos((ld)-1);

struct P {
    ld x, y;
    P(ld x = 0, ld y = 0) : x(x), y(y) {}

    P operator + (const P &b) const { return P(x + b.x, y + b.y); }
    P operator - (const P &b) const { return P(x - b.x, y - b.y); }
    P operator * (const ld &b) const { return P(x * b, y * b); }
    P operator / (const ld &b) const { return P(x / b, y / b); }
    ld operator * (const P &b) const { return x * b.y - y * b.x; }
};

P intersect(P p0, P v0, P p1, P v1) {
    return p0 + v0 * ((p1 - p0) * v1 / (v0 * v1));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<P> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    reverse(p.begin(), p.end());
    p.push_back(p[0]);
    vector<ld> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + p[i] * p[i + 1];
    }
    while (m--) {
        P q;
        cin >> q.x >> q.y;
        auto check = [&](ld ang) {
            P v(cos(ang), sin(ang));
            int left, right;
            auto query = [&](bool sign, bool left) {
                int l = 1, r = n - 1, res = -1;
                while (l <= r) {
                    int mid = l + r >> 1;
                    if ((v * (p[mid] - q) <= 0) == sign) {
                        res = mid;
                        left ? r = mid - 1 : l = mid + 1;
                    } else {
                        (p[0] - q) * (p[mid] - q) > 0 ? l = mid + 1 : r = mid - 1;
                    }
                }
                return res;
            };
            if (v * (p[0] - q) > 0) {
                left = query(1, 1), right = query(1, 0);
            } else {
                left = query(0, 1), right = query(0, 0);
            }
            ld area = sum[right] - sum[left];
            P x = intersect(q, v, p[left - 1], p[left] - p[left - 1]);
            P y = intersect(q, v, p[right], p[right + 1] - p[right]);
            area += x * p[left];
            area += p[right] * y;
            area += y * x;
            if (v * (p[0] - q) > 0) return area * 2 - sum[n];
            return sum[n] - area * 2;
        };
        bool sign = check(0) < check(pi);
        ld l = 0, r = pi;
        for (int tt = 0; tt < 50; tt++) {
            ld mid = (l + r) / 2;
            (check(mid) >= 0) == sign ? r = mid : l = mid;
        }
        printf("%.20lf\n", (double)l);
    }
    return 0;
}