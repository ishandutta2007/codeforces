#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
const int N = 107;
const int LG = 33;
int mod(int n) {
    return (n % MOD + MOD) % MOD;
}
int n;
int pw[N];
int dp[LG][N][N];
int res[N][N], tmp[N][N];
int getp(int w) {
    for (int i = 0; i < n; ++i) {
        dp[0][i][0] = pw[i];
        if (i + 1 < n) {
            dp[0][i][i + 1] = 1;
        }   
    }   
    for (int p = 1; p < LG; ++p) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    dp[p][i][j] += dp[p - 1][i][k] * dp[p - 1][k][j];
                    dp[p][i][j] %= MOD - 1;
                }   
            }   
        }   
    }      
    for (int i = 0; i < n; ++i) {
        res[i][i] = 1;
    }   
    for (int p = 0; p < LG; ++p) {
        if ((w >> p) & 1) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    tmp[i][j] = 0;
                }   
            }   
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < n; ++k) {
                        tmp[i][j] += res[i][k] * dp[p][k][j];
                        tmp[i][j] %= MOD - 1;
                    }   
                }   
            }   
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    res[i][j] = tmp[i][j];
                }   
            }   
        }   
    }   
    return res[0][0];
}
int fp(int n, int p) {
    if (p == 0) return 1;
    int t = fp(n, p >> 1);
    if (p & 1) return mod(mod(t * t) * n);
    else return mod(t * t);
}
int mdiv(int a, int b) {
    return mod(a * fp(b, MOD - 2));
}   
int R = 3;  
const int K = 4 * 10000;
int mlog(int a, int w) {
    map <int, int> d;
    for (int i = 0; i < K; ++i) {
        d[fp(a, i)] = i;
    }   
    for (int i = 0; i < K; ++i) {
        int f = fp(a, i * K);
        int want = mdiv(w, f);
        if (d.find(want) != d.end()) {
            return i * K + d[want];
        }   
    }   
    return -1;
} 
int solve(int w, int p) {
    //R^x^p=w
    //(R^p)^x=w
    int a = fp(R, p);
    int x = mlog(a, w);
    if (x == -1) return -1;
    else return fp(R, x);
}   
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> pw[i];
    int p, m;
    cin >> p >> m;
    int t = getp(p - n);
    cout << solve(m, t) << '\n';
}