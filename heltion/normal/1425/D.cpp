#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 2000;
constexpr int maxm = 1000;
constexpr LL mod = 1'000'000'007;
int sum[maxm + 1][maxm + 1];
int X[maxn], Y[maxn];
LL B[maxn];
LL C[maxn + 1][maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M, R;
    cin >> N >> M >> R;
    for(int i = 0; i < N; i += 1){
        cin >> X[i] >> Y[i] >> B[i];
        sum[X[i]][Y[i]] = 1;
    }
    for(int i = 0; i <= N; i += 1)
        for(int j = 0; j <= i; j += 1)
            C[i][j] = j ? (C[i - 1][j - 1] + C[i - 1][j]) % mod: 1;
    for(int i = 1; i <= maxm; i += 1)
        for(int j = 1; j <= maxm; j += 1)
            sum[i][j] += sum[i - 1][j];
    for(int i = 1; i <= maxm; i += 1)
        for(int j = 1; j <= maxm; j += 1)
            sum[i][j] += sum[i][j - 1];
    LL ans = 0;
    for(int i = 0; i < N; i += 1){
        int xL = max(X[i] - R, 1), xR = min(X[i] + R, maxm);
        int yL = max(Y[i] - R, 1), yR = min(Y[i] + R, maxm);
        int s = sum[xR][yR] - sum[xL - 1][yR] - sum[xR][yL - 1] + sum[xL - 1][yL - 1];
        ans += (C[N][M] - C[N - s][M] + mod) * B[i] % mod * B[i] % mod;
    }
    for(int i = 0; i < N; i += 1)
        for(int j = i + 1; j < N; j += 1){
            int xLi = max(X[i] - R, 1), xRi = min(X[i] + R, maxm);
            int yLi = max(Y[i] - R, 1), yRi = min(Y[i] + R, maxm);
            int xLj = max(X[j] - R, 1), xRj = min(X[j] + R, maxm);
            int yLj = max(Y[j] - R, 1), yRj = min(Y[j] + R, maxm);
            int xL = max(xLi, xLj), yL = max(yLi, yLj);
            int xR = min(xRi, xRj), yR = min(yRi, yRj);
            int si = sum[xRi][yRi] - sum[xLi - 1][yRi] - sum[xRi][yLi - 1] + sum[xLi - 1][yLi - 1];
            int sj = sum[xRj][yRj] - sum[xLj - 1][yRj] - sum[xRj][yLj - 1] + sum[xLj - 1][yLj - 1];
            int s = xL <= xR and yL <= yR ? sum[xR][yR] - sum[xL - 1][yR] - sum[xR][yL - 1] + sum[xL - 1][yL - 1] : 0;
            LL f = (C[N][M] - C[N - si][M] - C[N - sj][M] + C[N - (si + sj - s)][M] + 2 * mod) % mod;
            ans += 2 * f * B[i] % mod * B[j] % mod;
        }
    cout << ans % mod;
    return 0;
}