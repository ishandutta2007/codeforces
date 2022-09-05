#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 30010;
int d, M, n, tot, gen[21], B[maxn];
ll pw[maxn], L, R;
struct node {
    ll len, ans;
    bitset<maxn> pre, suf;
} f[63][63];
bitset<maxn> all;

node operator + (const node &A, const node &B) {
    if (!A.len) return B;
    node C; C.len = A.len + B.len;
    C.ans = A.ans + B.ans, C.pre = A.pre, C.suf = B.suf;
    if (A.len < n - 1) C.pre &= (B.pre >> A.len) | (all << (n - 1 - A.len));
    if (B.len < n - 1) C.suf &= (A.suf << B.len) | (all >> (n - 1 - B.len));
    if (A.len + B.len >= n) {
        auto b = A.suf & B.pre;
        if (A.len < n - 1) b &= all >> (n - 1 - A.len);
        if (B.len < n - 1) b &= all << (n - 1 - B.len);
        C.ans += b.count();
    }
    return C;
}

int main() {
    scanf("%d %d", &d, &M);
    for (int i = 1; i <= d; i++) {
        scanf("%d", &gen[i]);
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &B[i]);
    }
    scanf("%lld %lld", &L, &R);
    for (int i = pw[0] = 1; i < n; i++) {
        all.set(i);
    }
    for (int i = 0; i < M; i++) {
        f[0][i].len = 1, f[0][i].ans = n == 1 && B[1] >= i;
        for (int j = 1; j < n; j++) {
            f[0][i].pre[j] = B[j + 1] >= i;
            f[0][i].suf[j] = B[j] >= i;
        }
    }
    while (pw[tot] <= R / d) {
        pw[tot + 1] = pw[tot] * d, tot++;
        for (int i = 0; i < M; i++) {
            for (int j = 1; j <= d; j++) {
                f[tot][i] = f[tot][i] + f[tot - 1][(i + gen[j]) % M];
            }
        }
    }
    auto solve = [&](ll x) {
        node A; A.len = A.ans = 0;
        for (int i = tot, inc = 0; ~i; i--) {
            for (int j = 1; j <= d; j++) {
                if (x >= pw[i]) x -= pw[i], A = A + f[i][(inc + gen[j]) % M];
                else { (inc += gen[j]) %= M; break; }
            }
        }
        return A.ans;
    };
    printf("%lld\n", solve(R) - solve(L + n - 2));
    return 0;
}