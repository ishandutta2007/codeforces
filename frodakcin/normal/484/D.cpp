#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e6 + 100;

typedef long long ll;

int N, a[MAXN], b[MAXN];
bool u [MAXN];
ll dp[MAXN];

int main() {
    scanf("%d", &N);
    for(int i = 0;i < N;i++) scanf("%d", a + i);
    
    for(int i = 0;i < N;i++) u[i] = false;
    
    for(int i = 0;i < N;i++) u[i] = i == 0 or i == N - 1 or (a[i-1] < a[i] and not (a[i] < a[i+1])) or (a[i] < a[i-1] and not (a[i+1] < a[i]));
    int M = 0;
    b[M++] = a[0];
    for(int i = 1;i < N - 1;i++) if(u[i-1] or u[i] or u[i+1]) b[M++] = a[i];
    b[M++] = a[N-1];
    
    //for(int i = 0;i < M;i++) printf("%d\n", b[i]);
    
    dp[0] = 0;
    for(int i = 1;i <= M;i++) {
        dp[i] = 0;
        for(int j = 0;i - j > 0 and j < 5;j++) {
            dp[i] = max(dp[i], dp[i-j-1] + abs(b[i-1] - b[i-j-1]));
        }
    }
    
    printf("%lld\n", dp[M]);
    return 0;
}