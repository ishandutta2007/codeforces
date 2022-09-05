#include <bits/stdc++.h>
using namespace std;

const int maxn = 510, P = 998244353;
int n, ans = 1;
long long a[maxn];
map<long long, int> mp;
bool eq[maxn][maxn];

int main() {
    scanf("%d", &n);
    auto get = [&](long long x, int y) {
        long long z = x;
        while (--y) z *= x;
        return z;
    };
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        for (int j = 4; j >= 2; j--) {
            long long y = max(0LL, (long long)pow(a[i], 1.0 / j) - 10);
            assert(get(y, j) <= a[i]);
            while (get(y + 1, j) <= a[i]) y++;
            if (get(y, j) == a[i]) { mp[y] += j, a[i] = 1; break; }
        }
    }
    for (int i = 1; i <= n; i++) if (a[i] > 1) {
        bool flag = 0;
        for (auto p : mp) {
            if (!(a[i] % p.first)) mp[p.first]++, a[i] /= p.first, flag = 1;
        }
        if (flag == 1 && a[i] > 1) mp[a[i]]++, a[i] = 1;
    }
    for (int i = 1; i <= n; i++) if (a[i] > 1) {
        for (int j = i + 1; j <= n; j++) if (a[j] > 1) {
            if (a[i] == a[j]) { eq[i][j] = 1; continue; }
            long long g = __gcd(a[i], a[j]);
            if (g > 1) mp[g] = 0;
        }
    }
    for (int i = 1; i <= n; i++) if (a[i] > 1) {
        bool flag = 0;
        for (auto p : mp) {
            if (!(a[i] % p.first)) mp[p.first]++, a[i] /= p.first, flag = 1;
        }
        if (a[i] > 1) {
            for (int j = 1; j < i; j++) if (eq[j][i]) {
                mp[(long long)3e18 + j]++;
                if (!flag) mp[(long long)4e18 + j]++;
                goto nxt;
            }
            mp[(long long)3e18 + i]++;
            if (!flag) mp[(long long)4e18 + i]++;
            nxt:;
        }
    }
    for (auto p : mp) {
        ans = 1LL * ans * (p.second + 1) % P;
    }
    printf("%d\n", ans), fflush(stdout);
    return 0;
}