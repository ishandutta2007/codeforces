#include <bits/stdc++.h>
using namespace std;

int qp(int x, int y, int P) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    for (int i = 2; i * i <= n + 1; i++) {
        if (!((n + 1) % i)) puts("-1"), exit(0);
    }
    vector<int> V;
    for (int i = 1; i * i <= n; i++) if (!(n % i)) {
        if (i > 1) V.push_back(i);
        if (i > 1) V.push_back(n / i);
    }
    for (int b = x - 1; b > 1; b--) if (b % (n + 1)) {
        bool flag = 1;
        for (int x : V) {
            if (qp(b, x, n + 1) == 1) { flag = 0; break; }
        }
        if (flag) printf("%d\n", b), exit(0);
    }
    puts("-1");
    return 0;
}