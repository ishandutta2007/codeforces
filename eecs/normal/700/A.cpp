#include <bits/stdc++.h>
using namespace std;

int n, K;
long double L, v1, v2;

int main() {
    cin >> n >> L >> v1 >> v2 >> K;
    auto chk = [&](long double x) {
        long double cur = 0;
        long double tim = 0;
        for (int i = 1; i <= (n + K - 1) / K; i++) {
            long double t = tim * v1;
            tim += (cur - t) / (v1 + v2);
            cur = t + (cur - t) / (v1 + v2) * v1;
            cur += x * v2, tim += x;
            if (cur > L) return 0;
        }
        return 1;
    };
    long double l = 0, r = 1e9;
    for (int i = 1; i <= 3000; i++) {
        long double mid = (l + r) / 2;
        chk(mid) ? l = mid : r = mid;
    }
    cout << setprecision(10) << fixed << l + (L - v2 * l) / v1 << '\n';
    return 0;
}