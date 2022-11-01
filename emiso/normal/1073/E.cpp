#include <bits/stdc++.h>

#define MOD 998244353

using namespace std;
typedef long long ll;

ll dp[20][1<<11][2][2], dps[20][1<<11][2][2], k, l, r, lim, pot[20], ans;
vector<int> dig;

ll solve(int pos, int mask, int eq, int ze) {
    if(__builtin_popcount(mask) > k) return 0;
    if(pos == dig.size()) return 1;

    ll &x = dp[pos][mask][eq][ze];
    if(x != -1) return x;

    x = 0;
    if(eq) {
        for(int i = 0; i < dig[pos]; i++) {
            int nmask = mask;
            if(i != 0 || ze == 0) nmask |= (1 << i);

            x += solve(pos + 1, nmask, 0, (ze && i == 0));
            if(x >= MOD) x -= MOD;
        }
        int nmask = mask;
        if(dig[pos] != 0 || ze == 0) nmask |= (1 << dig[pos]);

        x += solve(pos + 1, nmask, 1, (ze && dig[pos] == 0));
        if(x >= MOD) x -= MOD;
    } else {
        for(int i = 0; i <= 9; i++) {
            int nmask = mask;
            if(i != 0 || ze == 0) nmask |= (1 << i);

            x += solve(pos + 1, nmask, 0, (ze && i == 0));
            if(x >= MOD) x -= MOD;
        }
    }
    return x;
}

ll solve2(int pos, int mask, int eq, int ze) {
    if(pos == dig.size() || __builtin_popcount(mask) > k) return 0;
    ll &x = dps[pos][mask][eq][ze];
    if(x != -1) return x;

    x = 0;
    if(eq) {
        for(int i = 0; i < dig[pos]; i++) {
            int nmask = mask;
            if(i != 0 || ze == 0) nmask |= (1 << i);

            ll q = solve(pos + 1, nmask, 0, (ze && i == 0));
            x = (x + i * pot[dig.size() - pos - 1] % MOD * q) % MOD;

            x += solve2(pos + 1, nmask, 0, (ze && i == 0));
            if(x >= MOD) x -= MOD;
        }

        int nmask = mask;
        if(dig[pos] != 0 || ze == 0) nmask |= (1 << dig[pos]);

        ll q = solve(pos + 1, nmask, eq, (ze && dig[pos] == 0));
        x = (x + dig[pos] * pot[dig.size() - pos - 1] % MOD * q) % MOD;

        x += solve2(pos + 1, nmask, eq, (ze && dig[pos] == 0));
        if(x >= MOD) x -= MOD;
    } else {

        for(int i = 0; i <= 9; i++) {
            int nmask = mask;
            if(i != 0 || ze == 0) nmask |= (1 << i);

            ll q = solve(pos + 1, nmask, 0, (ze && i == 0));
            x = (x + i * pot[dig.size() - pos - 1] % MOD * q) % MOD;

            x += solve2(pos + 1, nmask, 0, (ze && i == 0));
            if(x >= MOD) x -= MOD;
        }
    }

    return x;
}

int main() {
    scanf("%lld %lld %lld", &l, &r, &k);

    pot[0] = 1;
    for(int i = 1; i < 20; i++)
        pot[i] = pot[i-1] * 10LL % MOD;

    memset(dp, -1, sizeof dp);
    memset(dps, -1, sizeof dps);
    lim = r;
    dig.clear();
    while(lim) {
        dig.push_back(lim % 10);
        lim /= 10;
    }
    reverse(dig.begin(), dig.end());

    ans = solve2(0, 0, 1, 1);

    memset(dp, -1, sizeof dp);
    memset(dps, -1, sizeof dps);
    lim = l-1;
    dig.clear();
    while(lim) {
        dig.push_back(lim % 10);
        lim /= 10;
    }
    reverse(dig.begin(), dig.end());

    ans -= solve2(0, 0, 1, 1);
    if(ans < 0) ans += MOD;

    printf("%lld\n", ans);
    return 0;
}