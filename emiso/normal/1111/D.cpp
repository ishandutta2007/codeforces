#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD 1000000007
#define MN 100100

ll expo(ll a, ll b) {
    if(!b) return 1;
    a %= MOD;
    if(b & 1) return a * expo(a * a, b >> 1) % MOD;
    return expo(a * a, b >> 1);
}

ll inv_mod(ll x) {return expo(x, MOD - 2);}

ll fat[MN], ways, dp[MN], tmp[MN], ans[52][52];
int sz, f[52], q, a, b;
char s[MN];
string str;

int main() {
    scanf("%s", s); str = s;
    sz = str.size() / 2;

    fat[0] = 1;
    for(int i = 1; i < MN; i++)
        fat[i] = fat[i-1] * i % MOD;

    for(char c : str) {
        if('a' <= c && c <= 'z') f[c-'a']++;
        else f[c-'A'+26]++;
    }

    ways = fat[sz] * fat[sz] % MOD;
    for(int i = 0; i < 52; i++)
        ways = ways * inv_mod(fat[f[i]]) % MOD;

    dp[0] = 1;
    for(int c = 0; c < 52; c++) {
        for(int v = sz; v >= f[c]; v--) {
            if(!f[c]) continue;
            dp[v] += dp[v-f[c]];
            if(dp[v] >= MOD) dp[v] -= MOD;
        }
    }

    for(int i = 0; i < 52; i++) {
        for(int j = i; j < 52; j++) {
            if(!f[i] || !f[j]) continue;
            memcpy(tmp, dp, sizeof dp);

            for(int v = f[i]; v <= sz; v++) {
                tmp[v] -= tmp[v-f[i]];
                if(tmp[v] < 0) tmp[v] += MOD;
            }
            for(int v = f[j]; i != j && v <= sz; v++) {
                tmp[v] -= tmp[v-f[j]];
                if(tmp[v] < 0) tmp[v] += MOD;
            }
            ans[i][j] = tmp[sz];
        }
    }

    scanf("%d", &q);
    while(q--) {
        scanf("%d %d", &a, &b);
        a--; b--;

        if('a' <= str[a] && str[a] <= 'z') a = str[a] - 'a';
        else a = str[a] - 'A' + 26;

        if('a' <= str[b] && str[b] <= 'z') b = str[b] - 'a';
        else b = str[b] - 'A' + 26;

        if(a > b) swap(a, b);
        printf("%lld\n", ans[a][b] * ways % MOD * 2 % MOD);
    }
    return 0;
}