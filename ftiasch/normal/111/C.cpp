// Codeforces Beta Round #85
// Problem C -- Petya and Spiders
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

int dp[2][1 << 12];

void update(int &x, int a){
    x = min(x, a);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    if(n < m){
        swap(n, m);
    }
    int p = 0, maxMask = 1 << (m << 1);
    for(int mask = 0; mask < maxMask; ++ mask){
        dp[p][mask] = INF;
    }
    dp[p][0] = 0;
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < m; ++ j){
            p ^= 1;
            for(int mask = 0; mask < maxMask; ++ mask){
                dp[p][mask] = INF;
            }
            for(int mask = 0; mask < maxMask; ++ mask){
                int bit = (mask >> (j << 1)) & 3,
                    tmpMask = (mask ^ ((((bit << 1) & 3) ^ bit) << (j << 1)));
                if(i > 0){                
                    update(dp[p][tmpMask], dp[p ^ 1][mask] + !((bit >> 1) & 1));
                }
                update(dp[p][tmpMask | (2 << (j << 1))], dp[p ^ 1][mask] + !(bit & 1));
                if(i + 1 < n){
                    update(dp[p][tmpMask | (1 << (j << 1))], dp[p ^ 1][mask] + 1);
                }
                if(j > 0){
                    update(dp[p][tmpMask | (2 << ((j - 1) << 1))], dp[p ^ 1][mask] + !(((mask >> ((j - 1) << 1)) >> 1) & 1));
                }
                if(j + 1 < m){
                    update(dp[p][tmpMask | (1 << ((j + 1) << 1))], dp[p ^ 1][mask] + !((mask >> ((j + 1) << 1)) & 1));
                }
            }
        }
    }
    int result = INF; 
    for(int mask = 0; mask < maxMask; ++ mask){
        update(result, dp[p][mask]);
    }
    printf("%d\n", n * m - result);
    return 0;
}