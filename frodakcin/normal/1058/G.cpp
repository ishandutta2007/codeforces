#include <iostream>
#include <cstdio>

#include <functional>
#include <algorithm>
#include <utility>

#include <cassert>

using namespace std;

#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2e5 + 1000;
const int MAXV = 2e6 + 100;
const int PIV = 16e5;
const int MOD = 1e9 + 7;

int prod(int a, int b) {
    return static_cast<int>((static_cast<ll>(a)*b)%MOD);
}
int pow(int b, int p) {
    assert(p >= 0);
    int ret = 1;
    for(;p > 0;p >>= 1) {
        if(p&1) ret = prod(ret, b);
        b = prod(b, b);
    }
    return ret;
}

int N;
int p[MAXN];

int ploc[MAXV];
int pr[PIV], prs;

pii pf[PIV];
int pfs;

void fact(int n, bool alpr = false) {
    if(alpr) {
        pfs = 1;
        pf[0] = mp(ploc[n], 1);
        return;
    }
    pfs = 0;
    for(int i = 0;i < prs and pr[i] * pr[i] <= n;i++) {
        if(n%pr[i] == 0) {
            pf[pfs].first = i;
            pf[pfs].second = 0;
            for(;n%pr[i] == 0;n /= pr[i]) pf[pfs].second++;
            pfs++;
        }
    }
    if(n > 1) {
        pf[pfs++] = mp(ploc[n], 1);
    }
}

int ans[PIV];
bool dup[PIV];

bool chk(int n, bool alpr = false) {
    fact(n, alpr);
    for(int i = 0;i < pfs;i++) if(pf[i].second > ans[pf[i].first]) return true;
    return false;
}
bool ins(int n) {
    //fact(n);
    
    bool used = false;
    for(int i = 0;i < pfs;i++) {
        if(pf[i].second > ans[pf[i].first]) dup[pf[i].first] = false, ans[pf[i].first] = pf[i].second, used = true;
        else if(pf[i].second == ans[pf[i].first]) dup[pf[i].first] = true;
    }
    return used;
}

int u[MAXN], us;

int main() {
    scanf("%d", &N);
    
    for(int i = 0;i < MAXV;i++) ploc[i] = -1;
    for(int i = 0;i < PIV;i++) ans[i] = dup[i] = 0;
    
    prs = 0;
    for(int i = 2;i < MAXV;i++) {
        bool pm = true;
        for(int j = 0;j < prs and pr[j] * pr[j] <= i;j++) if(i%pr[j] == 0) {
            pm = false;
            break;
        }
        if(pm) {
            pr[prs] = i, ploc[i] = prs;
            prs++;
        }
    }
    
    for(int i = 0;i < N;i++) scanf("%d", p + i);
    
    sort(p, p + N, greater<int>());
    
    bool a0 = false;
    
    us = 0;
    for(int i = 0, j;i < N;i = j) {
        for(j = i;j < N and p[j] == p[i];j++);
        
        int amo = j - i;
        
        if(amo) {
            if(chk(p[i], true)) {
                assert(ins(p[i]));
                u[us++] = p[i];
                amo--;
            }
        }
        if(amo and p[i] != 2) {
            if(chk(p[i] - 1, false)) {
                assert(ins(p[i] - 1));
                u[us++] = p[i] - 1;
                amo--;
            }
        }
        if(amo) a0 = true;
    }
    
    if(!a0) {
        for(int i = 0;i < us;i++) {
            fact(u[i]);
            
            bool crem = true;
            for(int k = 0;k < pfs;k++) if(ans[pf[k].first] == pf[k].second and !dup[pf[k].first]) {
                crem = false;
                break;
            }
            
            if(crem) {
                a0 = true;
                break;
            }
        }
    }
    
    int fin = 1;
    for(int i = 0;i < PIV;i++) {
        fin = prod(fin, pow(pr[i], ans[i]));
    }
    fin = (a0 + fin)%MOD;
    
    printf("%d\n", fin);
    
    return 0;
}