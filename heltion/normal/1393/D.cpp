#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 2000;
char s[maxn + 2][maxn + 2];
int F[4][maxn + 2][maxn + 2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i += 1) cin >> (s[i] + 1);
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= m; j += 1)
            if(s[i - 1][j] == s[i][j] and s[i][j - 1] == s[i][j]) F[0][i][j] = 1 + min(F[0][i - 1][j], F[0][i][j - 1]);
    for(int i = 1; i <= n; i += 1)
        for(int j = m; j >= 1; j -= 1)
            if(s[i - 1][j] == s[i][j] and s[i][j + 1] == s[i][j]) F[1][i][j] = 1 + min(F[1][i - 1][j], F[1][i][j + 1]);
    for(int i = n; i >= 1; i -= 1)
        for(int j = 1; j <= m; j += 1)
            if(s[i + 1][j] == s[i][j] and s[i][j - 1] == s[i][j]) F[2][i][j] = 1 + min(F[2][i + 1][j], F[2][i][j - 1]);
    for(int i = n; i >= 1; i -= 1)
        for(int j = m; j >= 1; j -= 1)
            if(s[i + 1][j] == s[i][j] and s[i][j + 1] == s[i][j]) F[3][i][j] = 1 + min(F[3][i + 1][j], F[3][i][j + 1]);
    LL ans = 0;
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= m; j += 1)
            ans += min({F[0][i][j], F[1][i][j], F[2][i][j], F[3][i][j]}) + 1;
    cout << ans;
    return 0;
}