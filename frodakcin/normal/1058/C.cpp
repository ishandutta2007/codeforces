#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100 + 10;

int N;

int a[MAXN], aps[MAXN];
bool dp[MAXN][MAXN * 9];

char str[MAXN];

int main() {
    scanf("%d", &N);
    
    scanf("%s", str);
    
    for(int i = 1;i <= N;i++) a[i] = static_cast<int> (str[i - 1]) - 48;
    
    for(int i = 0;i <= N;i++) for(int j = 0;j <= 9 * N;j++) dp[i][j] = false;
    
    aps[0] = a[0] = 0;
    for(int i = 1;i <= N;i++) {
        aps[i] = aps[i - 1] + a[i];
    }
    
    for(int i = 0;i <= 9 * N;i++) dp[0][i] = true;
    
    for(int i = 1;i <= N;i++) {
        for(int k = 0;k < i;k++) {
            for(int j = 0;j <= 9 * N;j++) {
                if(aps[i] - aps[k] == j and i - k != N and dp[k][j]) dp[i][j] = true;
            }
        }
    }
    
    bool ans = false;
    for(int i = 0;i <= N * 9;i++) if(dp[N][i]) ans = true;
    
    if(ans) printf("YES\n");
    else printf("NO\n");
    
    return 0;
}