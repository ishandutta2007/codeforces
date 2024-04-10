#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, a, b, c, popcnt[64];
int f[200], g[64], lst[64], px[64], py[64], pz[64], tmp[8];
vector<int> d[maxn];

int solve(int x, int y, int z) {
    int ans = 0, j = 0, k = 0;
    for (register int i = 0; i < d[y].size(); i++) {
        while (j < d[x].size() && d[x][j] <= d[y][i]) j++;
        f[i] = j;
    }
    j = 0;
    for (int &x : d[z]) {
        while (j < d[y].size() && d[y][j] <= x) k += f[j++];
        ans += k;
    }
    return ans;
}

int main() {
    scanf("%d", &T);
    for (int i = 0; i < 64; i++) {
        popcnt[i] = __builtin_popcount(i) & 1;
    }
    for (int i = 1; i <= 100000; i++) {
        for (int j = i; j <= 100000; j += i) d[j].push_back(i);
    }
    map<tuple<int, int, int>, int> S;
    for (int i = 1; i < 64; i++) {
        int x = 0, y = 0, z = 0;
        if (i & 1) x |= 1, y |= 2, z |= 4;
        if (i & 2) x |= 1, y |= 4, z |= 2;
        if (i & 4) x |= 2, y |= 1, z |= 4;
        if (i & 8) x |= 2, y |= 4, z |= 1;
        if (i & 16) x |= 4, y |= 1, z |= 2;
        if (i & 32) x |= 4, y |= 2, z |= 1;
        px[i] = x, py[i] = y, pz[i] = z;
        auto p = make_tuple(x, y, z);
        if (S.count(p)) lst[i] = S[p];
        else S[p] = i;
    }
    while (T--) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == b && b == c && d[a].size() == 128) {
            puts("357760"); continue;
        }
        for (int i = 0; i < 8; i++) {
            tmp[i] = 0;
            if (i & 1) tmp[i] = __gcd(tmp[i], a);
            if (i & 2) tmp[i] = __gcd(tmp[i], b);
            if (i & 4) tmp[i] = __gcd(tmp[i], c);
        }
        int ans = 0;
        for (int i = 1; i < 64; i++) {
            if (lst[i]) {
                g[i] = g[lst[i]];
            } else {
                g[i] = solve(tmp[px[i]], tmp[py[i]], tmp[pz[i]]);
            }
            ans += g[i] * (popcnt[i] ? 1 : -1);
        }
        printf("%d\n", ans);
    }
    return 0;
}