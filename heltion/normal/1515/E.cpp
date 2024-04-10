#include<bits/stdc++.h>
using namespace std;
using LL = long long;
LL M;
void add(LL& x, LL y){
    x += y;
    if(x >= M) x -= y;
}
constexpr int maxn = 500;
LL DP[maxn][maxn];
LL F[maxn], G[maxn], P[maxn];
LL power(LL a, LL r){
    LL res = 1;
    for(; r; r >>= 1, a = a * a % M)
        if(r & 1) res = res * a % M;
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n >> M;
    for(int i = 0; i <= n; i += 1){
        G[i] = power(F[i] = i ? F[i - 1] * i % M : 1, M - 2);
        P[i] = power(2, i);
    }
    DP[0][0] = 1;
    for(int i = 1; i <= n + 1; i += 1)
        for(int j = 1; j <= n; j += 1)
            for(int k = 0; k + 1 < i; k += 1)
                DP[i][j] = (DP[i][j] + DP[k][j - 1] * P[i - k - 2] % M * G[i - k - 1]) % M;
    LL ans = 0;
    for(int j = 0; j <= n; j += 1){
        ans = (ans + DP[n + 1][j] * F[n - j + 1]) % M;
    }
    cout << ans;
    return 0;
}