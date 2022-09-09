#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
LL f(LL r, LL c, LL w, LL h) {
    if (w == r and h == c) return r * c;
    LL nw = w * 2 - r, nh = h * 2 - c;
    if (nw <= 0 or nh <= 0) return r * c - w * h;
    return r * c - 2 * w * h + nw * nh + f(w, h, nw, nh);
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    LL n, m, k, r, c;
    cin >> n >> m >> k >> r >> c;
    LL ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    LL w = min(ax + r - 1, bx + r - 1) - max(ax, bx) + 1;
    LL h = min(ay + c - 1, by + c - 1) - max(ay, by) + 1;
    if (w <= 0 or h <= 0) {
        cout << power(k, n * m - r * c);
        return 0;
    }
    cout << power(k, n * m - 2 * r * c + w * h + f(r, c, w, h));
    return 0;
}