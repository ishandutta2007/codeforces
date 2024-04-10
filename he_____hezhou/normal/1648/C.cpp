#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline int power(int a, int b) {
    long long res = a, ans = 1;
    for (; b; b >>= 1, res = res * res % mod) if (b & 1) ans = ans * res % mod;
    return ans;
}
inline int Mod(int x) {return x >= mod ? x - mod : x;}
struct mint {
    int x;
    mint() {x = 0;}
    mint(int y) {x = y;}
    inline mint inv() const { return mint{power(x, mod - 2)}; }
    explicit inline operator int() { return x; }
    friend inline mint operator + (const mint &a, const mint& b) { return mint(Mod(a.x + b.x)); }
    friend inline mint operator - (const mint &a, const mint& b) { return mint(Mod(a.x - b.x + mod)); }
    friend inline mint operator * (const mint &a, const mint& b) { return mint(1ll * a.x * b.x % mod); }
    friend inline mint operator - (const mint &a) { return mint(Mod(mod - a.x)); }
    friend inline mint& operator += (mint &a, const mint& b) { return a = a + b; }
    friend inline mint& operator -= (mint &a, const mint& b) { return a = a - b; }
    friend inline mint& operator *= (mint &a, const mint& b) { return a = a * b; }
    inline int operator == (const mint &b) { return x == b.x; }
    inline int operator != (const mint &b) { return x != b.x; }
    inline int operator < (const mint &a) { return x < a.x; }
    inline int operator <= (const mint &a) { return x <= a.x; }
    inline int operator > (const mint &a) { return x > a.x; }
    inline int operator >= (const mint &a) { return x >= a.x; }
};
inline mint power(mint a, int b) {
    mint ans = 1;
    for (; b; b >>= 1, a = a * a) if (b & 1) ans = ans * a;
    return ans;
}
int n, m;
int cnt[200010];
mint fac[200010], facinv[200010], inv[200010];
inline void init() {
    inv[1] = 1;
    for (int i = 2; i <= 200000; i++) inv[i] = (mod - mod / i) * inv[mod % i];
    fac[0] = facinv[0] = 1;
    for (int i = 1; i <= 200000; i++) fac[i] = fac[i - 1] * i, facinv[i] = facinv[i - 1] * inv[i];
}
const int k = 200000;
mint c[200010];
void add(int x, mint v) {
    for (; x <= k; x += x & -x) c[x] += v;
}
mint query(int x) {
    mint ans;
    for (; x; x -= x & -x) ans += c[x];
    return ans;
}
mint ans, cur;
int main() {
    init();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
        add(x, 1);
    }
    cur = 1;
    for (int i = 1; i <= k; i++) {
        cur *= facinv[cnt[i]];
    }
    for (int i = 1; i <= m; i++) {
        int x;
        scanf("%d", &x);
        // cerr << (int)cur << ' ' << (int)query(x - 1) << ' ' << (int)fac[n - i] << endl;
        ans += cur * query(x - 1) * fac[n - i];
        if (cnt[x] == 0) {
            if (i == n + 1) ans += 1;
            break;
        }
        cur *= cnt[x];
        add(x, mod - 1);
        cnt[x]--;
    }
    cout << (int)ans << endl;
}