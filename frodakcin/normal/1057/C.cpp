#include <cstdio>
#include <iostream>

#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 50 + 10;
const int MAXR = 50 + 10;
const int MAXK = 2e3 + MAXR + 100;
const int INF = 1e9 + 1e6;
int N, S, K;

int dp[MAXN][MAXK];
int r[MAXN];
char c[MAXN];

int o[MAXN];

int main() {
    scanf("%d%d%d", &N, &S, &K);
    S--;
    
    for(int i = 0;i < N;i++) scanf("%d", r + i), o[i] = i;
    scanf(" %s", c);
    
    sort(o, o + N, [](const int& a, const int& b){return r[a] < r[b];});
    
    for(int i = 0;i < N;i++) for(int j = 0;j <= K + MAXR;j++) dp[i][j] = INF;
    for(int i = 0;i < N;i++) dp[i][r[i]] = abs(S - i);
    
    int ans = INF;
    for(int i = 0, j, t;i < N;i = j) {
        for(j = i;j < N and r[o[j]] == r[o[i]];j++) {
            for(int k = 0;k < i;k++) if(c[o[j]] != c[o[k]]) for(int v = r[o[j]];v <= K + MAXR;v++) if((t = dp[o[k]][v - r[o[j]]] + abs(o[j] - o[k])) < dp[o[j]][v]) dp[o[j]][v] = t;
            for(int k = K + MAXR - 1;k >= 0;k--) if(dp[o[j]][k + 1] < dp[o[j]][k]) dp[o[j]][k] = dp[o[j]][k + 1];
        }
    }
    for(int i = 0, t;i < N;i++) if((t = dp[i][K]) < ans) ans = t;
    if(ans == INF) ans = -1;
    printf("%d\n", ans);
    
    return 0;
}