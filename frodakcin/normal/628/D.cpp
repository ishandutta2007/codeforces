#include <iostream>
#include <cstdio>

#include <iomanip>
#include <cassert>

using namespace std;

const int MAXM = 2e3 + 100;
const int MAXL = 2e3 + 100;

char tmp[MAXL];
int a[MAXL], b[MAXL];
int M, D, L;
const int MOD = 1e9 + 7;

typedef long long ll;
#define tll(x) static_cast<ll>(x)
#define ti(x) static_cast<int>(x)

int sum(const int& a, const int& b) {
    return ti((tll(a) + tll(b))%MOD);
}
int inc(int& a, const int& b) {
    a = sum(a, b);
    return a;
}
int dif(const int& a, const int& b) {
    return ti((tll(a) - tll(b) + tll(MOD) * 10)%MOD);
}
int prod(const int& a, const int& b) {
    return ti((tll(a) * tll(b))%MOD);
}
int difM(const int& a, const int& b) {
    return (a - b + M * 1000)%M;
}

int dp[MAXL][11][MAXM];
int p10[MAXL];

void init() {
    p10[0] = 1;
    for(int i = 1;i <= L;i++) p10[i] = (p10[i - 1] * 10)%M;
    for(int i = 0;i <= L;i++) for(int j = 0;j <= 10;j++) for(int k = 0;k < M;k++) dp[i][j][k] = 0;
    
    bool P = (L&1);
    
    if(P) {
        for(int d = 0;d < 10;d++) if(d != D) {
            dp[0][d][d%M] = 1;
            inc(dp[0][10][d%M], 1);
        }
    } else {
        dp[0][D][D%M] = 1;
        inc(dp[0][10][D%M], 1);
    }
    for(int i = 1;i <= L;i++) {
        if(P xor (i&1)) {       //odd digit
            for(int d = 0;d < 10;d++) {
                if(d == D) continue;
                for(int m = 0;m < M;m++) {
                    inc(dp[i][d][m], dp[i - 1][10][difM(m, d*p10[i])]);
                    inc(dp[i][10][m], dp[i - 1][10][difM(m, d*p10[i])]);
                }
            }
        } else {                //even digit
            for(int m = 0;m < M;m++) {
                inc(dp[i][D][m], dp[i - 1][10][difM(m, D*p10[i])]);
                inc(dp[i][10][m], dp[i - 1][10][difM(m, D*p10[i])]);
            }
        }
    }
}

int calcZ(int * n, int l, int m, bool ub = false) {
    int d = n[l];
    if(ub) d = 10;
    
    int r = 0;
    for(int i = 0;i < d;i++) {
        inc(r, dp[l][i][m]);
    }
    if(ub) return r;
    if(l == 0) {
        inc(r, dp[0][d][m]);
    }
    if(l > 0) {
        if((d == D) xor ((l&1) xor (L&1))) inc(r, calcZ(n, l - 1, difM(m, d*p10[l]), false));
    }
    return r;
}
int calcNZ(int * n, int l, int m) {
    int d = n[l];
    if(d == 0) return 0;
    
    int r = 0;
    for(int i = 1;i < d;i++) {
        inc(r, dp[l][i][m]);
    }
    if(l == 0) return sum(r, dp[0][d][m]);
    if((d == D) xor ((l&1) xor (L&1))) inc(r, calcZ(n, l - 1, difM(m, d*p10[l]), false));
    return r;
}

int main() {
    cerr << setprecision(3);
    scanf("%d%d", &M, &D);
    
    scanf(" %s", tmp);
    for(L = 0;tmp[L] != '\0';L++);
    for(int i = 0;i < L;i++) a[L - i - 1] = ti(tmp[i]) - ti('0');
    scanf(" %s", tmp);
    for(int i = 0;i < L;i++) b[L - i - 1] = ti(tmp[i]) - ti('0');
    
    clock_t timer = clock();
    
    init();
    
    for(int i = 0;i < L;i++) {          //equivalent to a--;
        if(a[i]) {
            a[i]--;
            break;
        } else a[i] = 9;
    }
    
    //cerr << calcNZ(b, L - 1, 0) << " - " << calcNZ(a, L - 1, 0) << "\n";
    printf("%d\n", dif(calcNZ(b, L - 1, 0), calcNZ(a, L - 1, 0)));
    
    cerr << static_cast<double> (clock() - timer) / CLOCKS_PER_SEC << "\n";
    
    return 0;
}