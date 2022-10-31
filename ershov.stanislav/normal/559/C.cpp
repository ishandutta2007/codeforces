#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define fs first
#define sc second
#define all(x) x.begin(), x.end()

#define y1 hrhrthrtethet

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;
typedef long long ll;

const int N = 2e3 + 200;
const int M = 5e5 + 100;
const int MOD = 1e9 + 7;

ll power(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * a) % MOD;
        }
        b >>= 1;
        a = (a * a) % MOD;
    }
    return ans;
}

ll dp[N];
ll fact[M], inv_fact[M];

int h, w, n;
pair<int, int> rc[N];

ll inv(ll a) {
    return power(a, MOD - 2);
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d%d", &h, &w, &n);
    fact[0] = 1;
    inv_fact[0] = 1;
    for (int i = 1; i < M; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv_fact[i] = inv(fact[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &rc[i].fs, &rc[i].sc);
        rc[i].fs--;
        rc[i].sc--;
    }
    rc[0] = make_pair(0, 0);
    rc[n + 1].fs = h - 1;
    rc[n + 1].sc = w - 1;
    int cnt = n + 2;
    sort(rc, rc + cnt);
    dp[0] = 1;
    for (int i = 1; i < cnt; i++) {
        dp[i] = fact[rc[i].fs + rc[i].sc] * inv_fact[rc[i].fs] % MOD * inv_fact[rc[i].sc] % MOD;
        for (int j = 1; j < i; j++) {
            int a = rc[i].fs - rc[j].fs;
            int b = rc[i].sc - rc[j].sc;
            if (a >= 0 && b >= 0) {
                dp[i] -= dp[j] * fact[a + b] % MOD * inv_fact[a] % MOD * inv_fact[b] % MOD;
                dp[i] += MOD;
                dp[i] %= MOD;
            }
        }
    }
    printf("%d\n", (int) ((dp[cnt - 1] % MOD + MOD) % MOD));
    return 0;
}