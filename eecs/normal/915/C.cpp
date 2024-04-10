#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b;
int n, m, x[20], y[20], z[20];

bool chk(int p) {
    int c = 0;
    for (int i = n; i; i--) {
        if (x[i] < 10) z[++c] = x[i];
    }
    for (int i = p; i; i--) {
        if (z[i] < y[i]) return 1;
        if (z[i] > y[i]) return 0;
    }
    return 1;
}

int main() {
    scanf("%lld %lld", &a, &b);
    while (a) x[++n] = a % 10, a /= 10;
    while (b) y[++m] = b % 10, b /= 10;
    if (m > n) {
        sort(x + 1, x + n + 1, greater<int>());
        for (int i = 1; i <= n; i++) printf("%d", x[i]);
    } else {
        sort(x + 1, x + n + 1);
        bool flag = 0;
        for (int i = n; i; i--) {
            for (int j = n; j; j--) {
                if (flag && x[j] < 10 || x[j] < y[i]) {
                    printf("%d", x[j]), x[j] = 10;
                    flag = 1; break;
                } else if (x[j] == y[i]) {
                    x[j] = 10;
                    if (!chk(i - 1)) x[j] = y[i];
                    else { printf("%d", y[i]); break; }
                }
            }
        }
    }
    return 0;
}