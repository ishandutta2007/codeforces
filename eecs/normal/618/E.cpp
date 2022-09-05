#include <bits/stdc++.h>
using namespace std;

typedef complex<double> complex_t;
typedef pair<complex_t, complex_t> T;
const int maxn = 300010;
const double PI = acos(-1);
int n, m;
T t[maxn << 2];

T operator + (T a, T b) {
    return {a.first * b.first, a.first * b.second + a.second};
}

#define mid (l + r >> 1)
void modify(int k, int l, int r, int p, T v) {
    if (l == r) { t[k] = v + t[k]; return; }
    if (mid >= p) modify(k << 1, l, mid, p, v);
    else modify(k << 1 | 1, mid + 1, r, p, v);
    t[k] = t[k << 1] + t[k << 1 | 1];
}

T get(int k, int l, int r, int p) {
    if (l == r) return t[k];
    if (mid >= p) return get(k << 1, l, mid, p);
    return get(k << 1 | 1, mid + 1, r, p);
}

int main() {
    scanf("%d %d", &n, &m);
    fill(t, t + (n << 2) + 1, T{1, 0});
    for (int _ = 1, op, x, y; _ <= m; _++) {
        scanf("%d %d %d", &op, &x, &y);
        if (op == 1) {
            modify(1, 1, n, x, T{1, complex_t(y) * get(1, 1, n, x).first});
        } else {
            double z = y / 360.0 * PI * 2;
            auto foo = complex_t(cos(-z), sin(-z));
            modify(1, 1, n, x, T{foo, (1.0 - foo) * complex_t(x - 1, 0)});
        }
        auto ans = t[1].first * complex_t(n, 0) + t[1].second;
        printf("%.10f %.10f\n", ans.real(), ans.imag());
    }
    return 0;
}