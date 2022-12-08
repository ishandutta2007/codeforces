#include <cstdio>
#include <iostream>

#include <functional>
#include <algorithm>

using namespace std;

typedef long long ll;

#define ti(x) static_cast<int>(x)
#define tll(x) static_cast<ll>(x)

const int MAXN = 1000 + 100;
const int MAXM = 1000 + 100;
const int MOD = 998244353;
const ll MODS = tll(MOD) * MOD;

int N, M, grid[MAXN][MAXM];

int sum(int a, int b) {
    return ti((tll(a) + b)%MOD);
}
int dif(int a, int b) {
    return ti((tll(a) - b + MODS)%MOD);
}
int prod(int a, int b) {
    return ti((tll(a) * b)%MOD);
}
int pow(int b, int p) {
    int r = 1;
    for(;p > 0;p >>= 1) {
        if(p&1) r = prod(r, b);
        b = prod(b, b);
    }
    return r;
}
int divm(int a, int b) {
    return prod(a, pow(b, MOD - 2));
}

struct PT {
public:
    int x, y, v;
    PT() {x = y = v = -1;}
    PT(int a, int b, int z) {
        x = a;
        y = b;
        v = z;
    }
    bool operator < (const PT& o) const {return v < o.v;}
} pt[MAXN * MAXM]; 

int dp[MAXN * MAXM], psm[MAXN * MAXM];
int xi, yi;

int px[3], py[3];
int pf(int x, int * p) {
    int r = 0;
    for(int i = 0;i < 3;i++) r = sum(r, prod(p[i], pow(x, i)));
    return r;
}
void ins(int x, int * p) {
    p[0] = sum(p[0], prod(x, x));
    p[1] = dif(p[1], prod(2, x));
    p[2] = sum(p[2], 1);
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i = 0;i < N;i++) for(int j = 0;j < M;j++) {
        scanf("%d", &grid[i][j]);
        pt[i * M + j] = PT(i, j, grid[i][j]);
    }
    scanf("%d%d", &xi, &yi);
    xi--;
    yi--;
    
    sort(pt, pt + (N*M), less<PT>());
    
    for(int i = 0;i <= M*N;i++) dp[i] = psm[i] = 0;
    
    int ans = -1;
    for(int i = 0;i < M*N;) {
        int j;
        for(j = i;j < M*N and pt[j].v == pt[i].v;j++) {
            if(i == 0) dp[j] = 0; else dp[j] = divm(sum(psm[i], sum(pf(pt[j].x, px), pf(pt[j].y, py))), i);
            if(pt[j].x == xi and pt[j].y == yi) ans = j;
        }
        for(int k = i;k < j;k++) {
            ins(pt[k].x, px);
            ins(pt[k].y, py);
            psm[k + 1] = sum(dp[k], psm[k]);
        }
        if(pt[i].v >= grid[xi][yi]) break;
        i = j;
    }
    
    printf("%d\n", dp[ans]);
    
    return 0;
}