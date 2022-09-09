#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 35000 + 1;
int pL[maxn], pR[maxn];
int a[maxn], p[maxn];
int dp[100 + 1][maxn];
int cL = 1, cR = 0, q = 0;
int query(int L, int R){
    while(cR < R){
        cR += 1;
        if(pL[cR] >= cL) q += cR - pL[cR];
    }
    while(cL > L){
        cL -= 1;
        if(pR[cL] <= cR) q += pR[cL] - cL;
    }
    while(cR > R){
        if(pL[cR] >= cL) q -= cR - pL[cR];
        cR -= 1;
    }
    while(cL < L){
        if(pR[cL] <= cR) q -= pR[cL] - cL;
        cL += 1;
    }
    //cout << L << " " << R << " " << q << endl;
    return q;
}
void find(int L, int R, int l, int r, int k){
    if(L > R) return;
    int M = (L + R) >> 1;
    int m = l;
    dp[k][M] = dp[k - 1][m] + query(m + 1, M);
    for(int i = l + 1; i <= r and i < R; i += 1){
        int y = dp[k - 1][i] + query(i + 1, M);
        if(y <= dp[k][M]){
            dp[k][M] = y;
            m = i;
        }
    }
    find(L, M - 1, l, m, k);
    find(M + 1, R, m, r, k);
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i += 1) cin >> a[i];
    for(int i = 1; i <= n; i += 1) p[i] = 0;
    for(int i = 1; i <= n; i += 1){
        pL[i] = p[a[i]];
        p[a[i]] = i;
    }
    for(int i = 1; i <= n; i += 1) p[i] = n + 1;
    for(int i = n; i >= 1; i -= 1){
        pR[i] = p[a[i]];
        p[a[i]] = i;
    }
    for(int i = 1; i <= n; i += 1) dp[1][i] = query(1, i);
    for(int j = 2; j <= k; j += 1) find(1, n, 1, n, j);
    cout << dp[k][n];
	return 0;
}