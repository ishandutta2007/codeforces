#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;
#define tll(x) static_cast<ll>(x)
#define ti(x) static_cast<int>(x)

const int MAXN = 500 + 10;
const int MOD = 1e9 + 7;

int sum(const int& a, const int& b) {
    return ti((tll(a) + tll(b))%MOD);
}
int inc(int& a, const int& b) {
    return (a = sum(a, b));
}
int prod(const int& a, const int& b) {
    return ti((tll(a) * tll(b))%MOD);
}

int N, b[MAXN];
int dp[MAXN][MAXN];         //ways to do nodes i..j as one tree where i is root [inclusive]
int dp2[MAXN][MAXN];         //ways to partition i..j rooting anywhere [inclusive]

int main() {
    scanf("%d", &N);
    for(int i = 1;i <= N;i++) scanf("%d", b + i);
    
    for(int i = 0;i <= N;i++) for(int j = 0;j <= N;j++) dp[i][j] = dp2[i][j] = 0;
    
    for(int i = N;i >= 1;i--) {
        for(int j = i;j <= N;j++) {
            if(j > i) dp[i][j] = dp2[i+1][j]; else dp[i][j] = 1;
        }
        for(int j = i;j <= N;j++) {
            if(j > i) {
                dp2[i][j] = dp[i][j];
                for(int k = i + 1;k <= N;k++) if(b[i] < b[k]) inc(dp2[i][j], prod(dp[i][k-1], dp2[k][j]));
            } else dp2[i][j] = 1;
        }
    }
    
    printf("%d\n", dp[1][N]);
    
    
    return 0;
}