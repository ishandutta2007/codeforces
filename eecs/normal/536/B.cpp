#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010, P = 1000000007;
int n, m, nxt[maxn], h[maxn], pw[maxn];
char s[maxn], ans[maxn];
vector<int> V;

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int find(int x) {
    return x == nxt[x] ? x : nxt[x] = find(nxt[x]);
}

int main() {
    scanf("%d %d %s", &n, &m, s + 1);
    int len = strlen(s + 1);
    iota(nxt + 1, nxt + n + 2, 1);
    while (m--) {
        int p; scanf("%d", &p);
        V.push_back(p);
        for (int i = find(p); i <= p + len - 1; i = find(i)) {
            ans[i] = s[i - p + 1], nxt[i] = i + 1;
        }
    }
    for (int i = pw[0] = 1; i <= n; i++) {
        pw[i] = 233LL * pw[i - 1] % P;
        h[i] = (233LL * h[i - 1] + ans[i]) % P;
    }
    auto get = [&](int l, int r) {
        return (h[r] - 1LL * h[l - 1] * pw[r - l + 1] % P + P) % P;
    };
    int hs = 0;
    for (int i = 1; i <= len; i++) {
        hs = (233LL * hs + s[i]) % P;
    }
    for (int p : V) {
        if (get(p, p + len - 1) ^ hs) puts("0"), exit(0);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i == find(i)) cnt++;
    }
    printf("%d\n", qp(26, cnt));
    return 0;
}