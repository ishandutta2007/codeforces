#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;
int T, n, m, rb, cb, rd, cd, p;

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d %d %d %d", &n, &m, &rb, &cb, &rd, &cd, &p);
        p = 1LL * p * qp(100, P - 2) % P;
        int dx = 1, dy = 1;
        vector<bool> V;
        int _rb = rb, _cb = cb;
        if (rb + dx == 0 || rb + dx > n) dx *= -1;
        if (cb + dy == 0 || cb + dy > m) dy *= -1;
        int _dx = dx, _dy = dy;
        do {
            V.push_back(rb == rd || cb == cd);
            rb += dx, cb += dy;
            if (rb + dx == 0 || rb + dx > n) dx *= -1;
            if (cb + dy == 0 || cb + dy > m) dy *= -1;
        } while (rb != _rb || cb != _cb || dx != _dx || dy != _dy);
        int prod = 1, sum = 0;
        for (int i = 0; i < V.size(); i++) {
            if (V[i]) prod = 1LL * prod * (P + 1 - p) % P;
            (sum += prod) %= P;
        }
        printf("%lld\n", 1LL * sum * qp(P + 1 - prod, P - 2) % P);
    }
    return 0;
}