#include <iostream>
#include <cstdio>

using namespace std;

const int INF = 1000000000;
const int MAXN = 5050;
const int MAXK = MAXN/2;

int N, K, dp1[MAXN][MAXK], dp2[MAXN][MAXK], h[MAXN];

int geth(int hh, int oh) {
    return hh > oh ? 0 : oh - hh + 1;
}
void iss(int& a, int b) {
    if(b < a) a = b;
}

int main() {
    scanf("%d", &N);
    K = (N+1)/2;
    for(int i = 1;i <= N;i++) {
        scanf("%d", &h[i]);
    }
    h[0] = h[N+1] = -INF;
    
    for(int i = 0;i <= N;i++) {
        for(int j = 0;j <= K;j++) {
            dp1[i][j] = dp2[i][j] = INF;
        }
    }
    
    dp2[0][0] = dp2[1][0] = 0;
    dp1[1][1] = 0;
    
    for(int n = 2;n <= N;n++) {
        dp2[n][0] = 0;
        for(int k = 1;k <= K;k++) {
            dp2[n][k] = min(dp2[n-1][k], dp1[n-1][k] + geth(h[n-1], h[n]));
        }
        
        for(int k = 1;k <= K;k++) {
            iss(dp1[n][k], dp1[n-2][k-1] + geth(h[n-2], h[n-1]) + geth(h[n], min(h[n-1], h[n-2]-1)));
            iss(dp1[n][k], dp2[n-2][k-1] + geth(h[n], h[n-1]));
        }
    }
    
    for(int k = 1;k <= K;k++) {
        printf("%d ", min(dp1[N][k], dp2[N][k]));
    }
    printf("\n");
    
}