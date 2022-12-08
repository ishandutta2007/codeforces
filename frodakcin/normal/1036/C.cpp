#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

typedef long long ll;

const int MAXT = 10100;
const ll MAXN = 1e18;
const int L10N = 20;
const int CL = 3;

ll dp[L10N][10][CL + 1];       //len, lastdigit, classy
ll p10[L10N];

void init() {
    for(int i = 0;i < L10N;i++) for(int j = 0;j < 10;j++) for(int k = 0;k <= CL;k++) dp[i][j][k] = 0;
    
    for(int i = 1;i < 10;i++) dp[1][i][1] = 1;
    dp[1][0][0] = 1;
    
    for(int i = 2;i < L10N;i++) {
        for(int j = 0;j < 10;j++) {
            for(int k = 0;k <= CL;k++) {
                if(k == 0 and j > 0) continue;
                for(int l = 0;l < 10;l++) dp[i][j][k] += dp[i - 1][l][k - (j > 0)];
            }
        }
    }
}

int L10(ll n) {
    ll a = 1;
    for(int i = 0;i <= 18;i++, a *= 10) {
        if(a >= n) return i - 1;
    }
    assert(false);
    return -1;
}

ll count(ll m, int z) {
    if(z <= 0) return 0;
    if(m < 10) return m;
    int l = L10(m), fd = m/p10[l];
    ll ans = 0;
    
    for(int i = 0;i < fd;i++) for(int j = z;j >= 0;j--) ans += dp[l + 1][i][j];
    return ans + count(m%p10[l], z - 1);
}

ll solve(ll l, ll r) {
    return count(r, 3) - count(l - 1, 3);
}

int T;
ll L, R;

int main() {
    scanf("%d", &T);
    
    p10[0] = 1;
    for(int i = 1;i <= 18;i++) p10[i] = p10[i - 1] * 10;
    
    init();
    
    for(int t = 0;t < T;t++) {
        scanf("%lld%lld", &L, &R);
        printf("%lld\n", solve(L, R));
    }
    
    return 0;
}