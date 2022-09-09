#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxm = 2520;
constexpr int maxn = 48;
LL DP[20][2][maxn][maxm];
int inv[maxm + 1], d[maxn], mp[maxn][10], dn, a[20], trick[20];
LL dp(LL n){
    for(int i = 18; i >= 0; i -= 1){
        a[i] = n % 10;
        n /= 10;
    }
    memset(DP, 0, sizeof DP);
    DP[0][0][0][0] = 1;
    for(int i = 0; i <= 18; i += 1)
        for(int j = 0; j < 2; j += 1)
            for(int p = 0; p < maxn; p += 1)
                for(int q = 0; q < trick[i]; q += 1){
                    if(not DP[i][j][p][q]) continue;
                    for(int d = 0; d < 10; d += 1){
                        if(j == 0 and d > a[i]) continue;
                        int ni = i + 1;
                        int nj = j or a[i] > d;
                        int np = mp[p][d];
                        int nq = (q * 10 + d) % trick[i];
                        DP[ni][nj][np][nq] += DP[i][j][p][q];
                    }
                }
    LL res = 0;
    for(int j = 0; j < 2; j += 1)
        for(int p = 0; p < maxn; p += 1)
            for(int q = 0; q < maxm; q += 1)
                if(q % d[p] == 0)
                    res += DP[19][j][p][q];
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int i = 1; i <= maxm; i += 1)
        if(maxm % i == 0){
            d[dn] = i;
            inv[i] = dn;
            dn += 1;
        }
    for(int i = 0; i < maxn; i += 1)
        for(int j = 0; j < 10; j += 1)
            mp[i][j] = inv[d[i] * max(j, 1) / gcd(d[i], max(j, 1))];
    for(int i = 0; i <= 15; i += 1) trick[i] = 63;
    trick[16] = trick[15] * 2;
    trick[17] = trick[16] * 2;
    trick[18] = 2520;
    int t;
    for(cin >> t; t; t -= 1){
        LL l, r;
        cin >> l >> r;
        cout << dp(r) - dp(l - 1) << "\n";
    }
    return 0;
}