#include <iostream>
#include <cstdio>

#include <ctime>
#include <iomanip>
#include <bitset>
#include <utility>
#include <cassert>

using namespace std;

const int MOD = 998244353;
const int D2C = 499122177;
const int MAXK = 10;
typedef long long ll;
#define ti(x) static_cast<int>(x)
#define tll(x) static_cast<ll>(x)
typedef pair<int, int> pii;
#define mp make_pair

int sum(const int& a, const int& b) {
    return ti((tll(a) + tll(b))%MOD);
}
int prod(const int& a, const int& b) {
    return ti((tll(a)*tll(b))%MOD);
}
int pow(int b, int p) {
    assert(p>=0);
    if(b == 1) return 1;
    int r = 1;
    for(;p;p>>=1, b=prod(b, b)) if(p&1) r = prod(r, b);
    return r;
}
int div(const int& n, const int& d) {
    assert(d > 0);
    if(d == 2) return prod(n, D2C);
    return prod(n, pow(d, MOD - 2));
}
int dif(const int& a, const int& b) {
    return ti((tll(a) - tll(b) + tll(MOD) * 10)%MOD);
}

ll L, R;
int K;

int p10[20];
ll p10R[20];
int dpc[20][MAXK + 1][1 << MAXK], dpv[20][MAXK + 1][1 << MAXK];

int l10(ll v) {
    int r = 0;
    while(v /= 10) r++;
    return r;
}

pii operator + (const pii& a, const pii& b) {
    return mp(sum(a.first, b.first), sum(a.second, b.second));
}
pii operator += (pii& a, const pii& b) {
    a = a + b;
    return a;
}

pii calcZ(const ll& v, const int& mask, const int& l) {
    int d = (v/p10R[l])%10;
    
    pii r(0, 0);
    
    for(int i = 0;i < d;i++) {
        if(mask & (1 << i)) {
            r += mp(dpc[l][i][mask], dpv[l][i][mask]);
        }
    }
    if(l == 0) {
        r += mp(dpc[l][d][mask], dpv[l][d][mask]);
    }
    if(l > 0) {
        pii u (0, 0);
        if(mask&(1 << d)) {
            u = calcZ(v, mask, l - 1) + calcZ(v, mask - (1 << d), l - 1);
        }
        r += u;
        r.second = sum(r.second, prod(u.first, prod(d, p10[l])));
    }
    return r;
}
pii calcNZ(const ll& v, const int& mask) {
    if(v == 0) return mp(0, 0);
    
    int l = l10(v);
    int d = v/p10R[l];
    assert(0 < d and d < 10);
    
    pii r = calcNZ(p10R[l] - 1, mask);
    
    for(int i = 1;i < d;i++) {
        if(mask & (1 << i)) {
            r += mp(dpc[l][i][mask], dpv[l][i][mask]);
        }
    }
    
    if(l == 0) {
        r += mp(dpc[0][d][mask], dpv[0][d][mask]);
    }
    if(l > 0) {
        if(mask&(1 << d)) {
            pii u = calcZ(v, mask, l - 1) + calcZ(v, mask - (1 << d), l - 1);
            r += u;
            r.second = sum(r.second, prod(u.first, prod(d, p10[l])));
        }
    }
    
    return r;
}
int calc(ll v) {
    int r = 0;
    for(int m = 1;m < (1 << MAXK);m++) {
        if(__builtin_popcount(m) <= K) {
            r = sum(r, calcNZ(v, m).second);
            //cerr << bitset<10>(m) << " " << calcNZ(v, m).second << " " << r << "\n";
        }
    }
    return r;
}

int main() {
    clock_t timer = clock();
    cerr << setprecision(3);
    
    p10[0] = 1;
    p10R[0] = 1;
    for(int i = 1;i < 20;i++) p10[i] = prod(10, p10[i - 1]);
    for(int i = 1;i < 19;i++) p10R[i] = p10R[i - 1] * 10;
    
    for(int i = 0;i < 20;i++) for(int j = 0;j <= MAXK;j++) for(int k = 0;k < (1 << MAXK);k++) dpc[i][j][k] = dpv[i][j][k] = 0;
    for(int i = 0;i < MAXK;i++) {
        dpc[0][i][1 << i] = 1;
        dpv[0][i][1 << i] = i;
    }
    for(int i = 0;i < MAXK;i++) for(int j = 0;j < (1 << MAXK);j++) dpc[0][MAXK][j] = sum(dpc[0][MAXK][j], dpc[0][i][j]), dpv[0][MAXK][j] = sum(dpv[0][MAXK][j], dpv[0][i][j]);
    
    for(int i = 1;i < 20;i++) {
        for(int j = 0;j < MAXK;j++) {
            for(int m = (1 << j);m < (1 << MAXK);m = (m + 1)|(1 << j)) {
                //cerr << j << " " << bitset<10> (m) << "\n";
                dpc[i][j][m] = sum(dpc[i - 1][MAXK][m], dpc[i - 1][MAXK][m ^ (1 << j)]);
                dpv[i][j][m] = sum(sum(dpv[i - 1][MAXK][m], dpv[i - 1][MAXK][m ^ (1 << j)]), prod(prod(dpc[i][j][m], j), p10[i]));
            }
        }
        for(int j = 0;j < MAXK;j++) {
            for(int m = 0;m < (1 << MAXK);m++) {
                dpc[i][MAXK][m] = sum(dpc[i][MAXK][m], dpc[i][j][m]);
                dpv[i][MAXK][m] = sum(dpv[i][MAXK][m], dpv[i][j][m]);
            }
        }
    }
    
    cerr << (clock() - timer) * static_cast<double>(1) / CLOCKS_PER_SEC << "\n";
    
    scanf("%lld%lld%d", &L, &R, &K);
    
    printf("%d\n", dif(calc(R), calc(L - 1)));
    
    return 0;
}