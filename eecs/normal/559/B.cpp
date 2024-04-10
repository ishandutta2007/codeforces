#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, P = 998244353;
int hs[maxn], ht[maxn], pw[maxn];
char s[maxn], t[maxn];
mt19937 rnd(time(0));

int get1(int l, int r) {
    return (hs[r] - 1LL * hs[l - 1] * pw[r - l + 1] % P + P) % P;
}

int get2(int l, int r) {
    return (ht[r] - 1LL * ht[l - 1] * pw[r - l + 1] % P + P) % P;
}

bool chk(int l1, int r1, int l2, int r2) {
    int len = r1 - l1 + 1;
    if (len & 1) return get1(l1, r1) == get2(l2, r2);
    len /= 2;
    if (!(rnd() & 1)) return chk(l1, l1 + len - 1, l2, l2 + len - 1) && chk(l1 + len, r1, l2 + len, r2)
        || chk(l1, l1 + len - 1, l2 + len, r2) && chk(l1 + len, r1, l2, l2 + len - 1);
    return chk(l1, l1 + len - 1, l2 + len, r2) && chk(l1 + len, r1, l2, l2 + len - 1) ||
        chk(l1, l1 + len - 1, l2, l2 + len - 1) && chk(l1 + len, r1, l2 + len, r2);
}

int main() {
    scanf("%s %s", s + 1, t + 1);
    int n = strlen(s + 1);
    for (int i = pw[0] = 1; i <= n; i++) {
        hs[i] = (233LL * hs[i - 1] + s[i]) % P;
        ht[i] = (233LL * ht[i - 1] + t[i]) % P;
        pw[i] = 233LL * pw[i - 1] % P;
    }
    puts(chk(1, n, 1, n) ? "YES" : "NO");
    return 0;
}