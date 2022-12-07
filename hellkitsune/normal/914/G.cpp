#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;
const int ALL = (1 << 17) - 1;

int n;
int s[1 << 17];
LL t[1 << 17];
int ab[1 << 17], c[1 << 17], de[1 << 17], fib[1 << 17];

void init() {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < (1 << 17); ++i) {
        fib[i] = (fib[i - 2] + fib[i - 1]) % MOD;
    }
}

void solve(int mask, int ind) {
    if (ind == 17) {
        int rem = ALL ^ mask;
        LL cnt = 0;
        for (int sub = rem; ; sub = (sub - 1) & rem) {
            cnt += t[sub] * t[rem ^ sub];
            if (sub == 0) break;
        }
        de[rem] = cnt % MOD;
        return;
    }
    solve(mask, ind + 1);

    int po = 1 << ind;

    mask ^= po;
    int rem = ALL ^ mask;

    for (int sub = rem; ; sub = (sub - 1) & rem) {
        t[sub] += t[sub ^ po];
        if (sub == 0) break;
    }

    solve(mask, ind + 1);

    for (int sub = rem; ; sub = (sub - 1) & rem) {
        t[sub] -= t[sub ^ po];
        if (sub == 0) break;
    }
}

inline void modAdd(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

inline void modSub(int &x, int y) {
    x -= y;
    if (x < 0) x += MOD;
}

int main() {
    init();
    scanf("%d", &n);
    forn(i, n) {
        int x;
        scanf("%d", &x);
        ++s[x];
    }
    for (int mask = 1; mask < (1 << 17); ++mask) {
        LL cnt = 0;
        for (int sub = mask; ; sub = (mask & (sub - 1))) {
            cnt += (LL)s[sub] * s[mask ^ sub];
            if (sub == 0) {
                break;
            }
        }
        ab[mask] = cnt % MOD * fib[mask] % MOD;
    }
    forn(i, 1 << 17) c[i] = (LL)s[i] * fib[i] % MOD;
    forn(i, 17) forn(mask, 1 << 17) if (!(mask & (1 << i))) {
        modAdd(ab[mask], ab[mask ^ (1 << i)]);
        modAdd(c[mask], c[mask ^ (1 << i)]);
    }

    forn(i, 1 << 17) t[i] = s[i];
    solve(0, 0);
    forn(i, 17) forn(mask, 1 << 17) if (!(mask & (1 << i))) {
        modSub(de[mask], de[mask ^ (1 << i)]);
    }
    forn(mask, 1 << 17) {
        de[mask] = (LL)de[mask] * fib[mask] % MOD;
    }
    forn(i, 17) forn(mask, 1 << 17) if (!(mask & (1 << i))) {
        modAdd(de[mask], de[mask ^ (1 << i)]);
    }

    int ans = 0;
    for (int mask = 1; mask < (1 << 17); ++mask) {
        int sg = __builtin_popcount(mask) % 2;
        if (sg == 0) sg = -1;
        sg *= __builtin_popcount(mask);
        ans = (ans + (LL)sg * ab[mask] % MOD * c[mask] % MOD * de[mask]) % MOD;
    }
    if (ans < 0) {
        ans += MOD;
    }
    cout << ans << endl;
    return 0;
}