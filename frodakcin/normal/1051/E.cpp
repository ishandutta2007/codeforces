#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

const int MAXN = 1e6 + 100;
const int MOD = 998244353;

int sum(int a, int b) {
    return (a + b)%MOD;
}
int dif(int a, int b) {
    return (a - b + MOD)%MOD;
}

char inp[MAXN];
void takeinput(int * a, int& l) {
    scanf("%s", inp);
    for(l = 0;inp[l] != '\0';l++) a[l] = static_cast<int> (inp[l]) - 48;
    a[l] = -1;
}

void printout(int * s) {
    while(*s != -1) printf("%d", *(s++));
    printf("\n");
}
void printout(int * s, int * e) {
    while(s != e) printf("%d", *(s++));
    printf("\n");
}

int f[MAXN];
void zfunc(int * p, int pl, int * n, int nl, int * z) {
    f[0] = 0;
    for(int i = 1, l = -1, r = 0;i < pl;i++) {
        if(i < r) f[i] = min(f[i - l], r - i); else f[i] = 0;
        while(f[i] + i < pl and p[f[i]] == p[f[i] + i]) f[i]++;
        if(f[i] + i > r) l = i, r = f[i] + i;
    }
    for(int i = 0, l = -1, r = 0;i < nl;i++) {
        if(i < r) z[i] = min(f[i - l], r - i); else z[i] = 0;
        while(z[i] < pl and i + z[i] < nl and p[z[i]] == n[i + z[i]]) z[i]++;
        if(i + z[i] > r) l = i, r = i + z[i];
    }
}

int N, L, R;
int n[MAXN], l[MAXN], r[MAXN];
int lz[MAXN], rz[MAXN];

int dp[MAXN], dps[MAXN];

int cmpL(int n1, int n2) {      //1 if l > a[n1..n2]
    if(n1 >= n2) return 1;
    if(n[n1] == 0) return cmpL(n1 + 1, n2);
    
    if(L > n2 - n1) return 1;
    if(L < n2 - n1) return -1;
    
    int d = lz[n1];
    if(d >= L) return 0;
    if(l[d] > n[n1 + d]) return 1;
    if(l[d] < n[n1 + d]) return -1;
    
    assert(false);
    return -2;
}
int cmpR(int n1, int n2) {      //1 if r > a[n1..n2]
    if(n1 >= n2) return 1;
    if(n[n1] == 0) return cmpL(n1 + 1, n2);
    
    if(R > n2 - n1) return 1;
    if(R < n2 - n1) return -1;
    
    int d = rz[n1];
    if(d >= R) return 0;
    if(r[d] > n[n1 + d]) return 1;
    if(r[d] < n[n1 + d]) return -1;
    
    assert(false);
    return -2;
}

int main() {
    
    takeinput(n, N);
    takeinput(l, L);
    takeinput(r, R);
    
    zfunc(l, L, n, N, lz);
    zfunc(r, R, n, N, rz);
    
    for(int i = 0;i <= N;i++) dp[i] = 0;
    
    dp[N] = dps[N] = 1;
    for(int i = N - 1;i >= 0;i--) {
        if(n[i] == 0) {
            if(l[0] == 0) dp[i] = dp[i + 1]; else dp[i] = 0;
            dps[i] = sum(dp[i], dps[i + 1]);
            continue;
        }
        
        int lb = min(i + L, N);
        int rb = min(i + R, N);
        
        if(cmpL(i, lb) == 1) lb++;
        if(cmpR(i, rb) == -1) rb--;
        
        dp[i] = dif(dps[lb], dps[rb + 1]);
        dps[i] = sum(dps[i + 1], dp[i]);
    }
    
    printf("%d\n", dp[0]);
    
    return 0;
}