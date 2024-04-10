#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 18, P = 1000000007;
int n, rt[maxn], pw[maxn], mp[maxn][20];
char str[maxn];
vector<int> h[maxn << 2];

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void build(int k, int l, int r) {
    if (l == r) { h[k] = {str[l]}; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    int t = __lg(r - l + 1);
    h[k].resize(1 << t);
    for (int i = 0; i < 1 << t; i++) {
        if (i >> (t - 1) & 1) {
            h[k][i] = (h[rs][i ^ (1 << (t - 1))] + 1LL * pw[1 << (t - 1)] * h[ls][i ^ (1 << (t - 1))]) % P;
        } else {
            h[k][i] = (h[ls][i] + 1LL * pw[1 << (t - 1)] * h[rs][i]) % P;
        }
    }
    mp[l][t] = k;
}

int main() {
    scanf("%d %s", &n, str);
    for (int i = pw[0] = 1; i < 1 << n; i++) {
        pw[i] = 10007LL * pw[i - 1] % P;
    }
    build(1, 0, (1 << n) - 1);
    auto get = [&](int x, int l, int r) -> int {
        if (l == r) return str[x ^ l];
        int k = __lg(r - l + 1);
        int y = x & ((1 << k) - 1);
        return h[mp[l ^ (x ^ y)][k]][y];
    };
    int ans = 0;
    for (int i = 1; i < 1 << n; i++) {
        int cur = 0;
        for (int j = n - 1; ~j; j--) {
            if (get(ans, cur, cur + (1 << j) - 1) == get(i, cur, cur + (1 << j) - 1)) cur |= 1 << j;
        }
        if (cur == (1 << n)) continue;
        if (str[ans ^ cur] > str[i ^ cur]) ans = i;
    }
    for (int i = 0; i < 1 << n; i++) {
        putchar(str[i ^ ans]);
    }
    return 0;
}