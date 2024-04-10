#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int P = 1000000007;
int n, tot, cnt[8], prob[7][7], popcnt[1 << 7];
ll tr[1 << 7][1 << 7], mp[1 << 7];
unordered_map<ll, int> f, g;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &prob[j][i]);
            prob[j][i] = 570000004LL * prob[j][i] % P;
        }
    }
    for (int i = 0; i < 1 << n; i++) {
        mp[i] = 1LL << cnt[popcnt[i] = __builtin_popcount(i)]++;
    }
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < 1 << n; j++) {
            for (int k = 0; k < n; k++) if (j >> k & 1) {
                if (!(i >> k & 1)) tr[i][j] |= mp[i | (1 << k)];
            }
        }
    }
    f[1] = 1;
    for (int i = 0; i < n; i++, swap(f, g)) {
        g.clear();
        for (int j = 0; j < 1 << n; j++) {
            int t = 1;
            for (int k = 0; k < n; k++) {
                if (j >> k & 1) t = 1LL * t * prob[i][k] % P;
                else t = 1LL * t * (P + 1 - prob[i][k]) % P;
            }
            for (auto p : f) {
                ll S = 0;
                for (int T = 0; T < 1 << n; T++) if (popcnt[T] == i) {
                    if (p.first & mp[T]) S |= tr[T][j];
                }
                g[S] = (g[S] + 1LL * t * p.second) % P;
            }
        }
    }
    printf("%d\n", f[mp[(1 << n) - 1]]);
    return 0;
}