#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, A, B, a[maxn], b[maxn];
vector<int> cand;
long long ans = LLONG_MAX, f[maxn][3];

void chk(long long &x, long long y) {
    if (x > y) x = y;
}

int main() {
    scanf("%d %d %d", &n, &A, &B);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    auto fact = [&](int x) {
        for (int i = 2; i * i <= x; i++) if (!(x % i)) {
            cand.push_back(i);
            while (!(x % i)) x /= i;
        }
        if (x > 1) cand.push_back(x);
    };
    fact(a[1] - 1), fact(a[1]), fact(a[1] + 1);
    fact(a[n] - 1), fact(a[n]), fact(a[n] + 1);
    sort(cand.begin(), cand.end());
    cand.resize(unique(cand.begin(), cand.end()) - cand.begin());
    for (int p : cand) {
        memset(f, 0x3f, sizeof(f)), f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int x : {0, 1, 2}) {
                if (!(a[i] % p)) {
                    if (x == 1) {
                        chk(f[i][x], f[i - 1][x] + A);
                        chk(f[i][2], f[i - 1][x]);
                    } else {
                        chk(f[i][x], f[i - 1][x]);
                    }
                } else if ((a[i] - 1) % p && (a[i] + 1) % p) {
                    if (x < 2) chk(f[i][1], f[i - 1][x] + A);
                } else {
                    if (x == 1) {
                        chk(f[i][x], f[i - 1][x] + A),
                        chk(f[i][2], f[i - 1][x] + B);
                    } else {
                        if (!x) chk(f[i][1], f[i - 1][x] + A);
                        chk(f[i][x], f[i - 1][x] + B);
                    }
                }
            }
        }
        for (int x : {0, 1, 2}) {
            ans = min(ans, f[n][x]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}