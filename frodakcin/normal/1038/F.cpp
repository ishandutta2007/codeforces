#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

typedef long long ll;

const int MAXN = 50;

int N, S;
char sr[MAXN];

ll dp[MAXN][MAXN][2];

int z[MAXN], s[MAXN];

int next(int n, int c) {
    while(n != 0 and s[n] != c) n = z[n - 1];
    if(s[n] == c) n++;
    return n;
}
void init() {
    z[0] = 0;
    for(int i = 1;i < S;i++) {
        z[i] = next(z[i - 1], s[i]);
    }
}
int t;
ll rundp(int s) {
    for(int i = 0;i <= N;i++) for(int j = 0;j <= N;j++) for(int k = 0;k < 2;k++) dp[i][j][k] = 0;
    
    dp[0][s][0] = 1;
    for(int l = 0;l <= N;l++) {
        for(int k = 0;k <= S;k++) {
            for(int d = 0;d < 2;d++) {
                if((t = next(k, d)) == S) dp[l + 1][t][1] += dp[l][k][0];
                else dp[l + 1][t][0] += dp[l][k][0];
                dp[l + 1][t][1] += dp[l][k][1];
            }
        }
    }
    
    return dp[N][s][1];
}

int main() {
    scanf("%d", &N);
    scanf("%s", sr);
    
    for(S = 0;sr[S] != '\0';S++) {
        assert(S < N);
        s[S] = static_cast<int> (sr[S]) - 48;
    }
    s[S] = -1;
    
    init();
    
    
    //for(int i = 0;i <= S;i++) printf("%d: %d\n", i, next(i, 0));
    
    ll ans = 0;
    for(int i = 0;i <= S;i++) ans += rundp(i);
    printf("%lld\n", ans);
    
    return 0;
}