#include <iostream>
#include <cstdio>

#include <vector>
#include <bitset>

#include <cassert>

using namespace std;

typedef long long ll;
#define tll(x) static_cast<ll>(x)
#define ti(x) static_cast<int>(x)

const int MAXN = 2e5 + 100;
const int MAXA = 5e5 + 100;
const int NUMP = 5e4;

int N, Q;
int a[MAXN];

int p[NUMP], ps;
int sd[MAXA], nx[MAXA];
bitset<MAXA> prime;

int convert(int n) {
    int r = 1;
    for(;n != 1;n = nx[n]) r *= sd[n];
    return r;
}

typedef vector<int> vi;
#define pb push_back

vi factors[MAXA];

ll ans;


int ct[MAXA];
int tp[1 << 8], mu[1 << 8];
int log2(int v) {
    int r = 0;
    while(v>>=1) r++;
    return r;
}
void upd(int v, int a) {
    int fn = factors[v].size();
    for(int i = 1;i < (1 << fn);i++) {
        int bc = __builtin_popcount(i);
        if(bc == 1) tp[i] = factors[v][log2(i)]; else tp[i] = tp[i-((-i)&i)]*tp[((-i)&i)];
        if(bc&1) ans -= a * ct[tp[i]]; else ans += a * ct[tp[i]];
    }
}
void change(int v, int a) {
    if(prime[v]) {
        ct[v] += a;
        return;
    }
    
    int fn = factors[v].size();
    
    for(int i = 1, nv;i < (1 << fn);i++) {
        if(i == 1 or (nx[i] == 1 and sd[i] == 2)) tp[i] = factors[v][log2(i)]; else tp[i] = tp[i-((-i)&i)]*tp[((-i)&i)];
        ct[tp[i]] += a;
    }
}

bitset<MAXN> used;

int main() {
    for(int i = 0;i < MAXA;i++) prime[i] = 1;
    
    sd[1] = nx[1] = 1;
    factors[1].clear();
    
    ps = 0;
    for(int i = 2;i < MAXA;i++) {
        if(prime[i]) p[ps++] = i, nx[i] = 1, sd[i] = i, factors[i].pb(i);
        for(int j = 0;j < ps;j++) {
            if(i*p[j] >= MAXA) break;
            assert(prime[i*p[j]]);
            prime[i*p[j]] = 0;
            
            sd[i*p[j]] = p[j];
            if(sd[i] != p[j]) {
                nx[i*p[j]] = i; 
                factors[i*p[j]] = factors[i];
                factors[i*p[j]].pb(p[j]);
            }
            else {
                nx[i*p[j]] = nx[i];
                factors[i*p[j]] = factors[i];
            }
            
            if(i%p[j] == 0) break;
        }
    }
    
    scanf("%d%d", &N, &Q);
    for(int i = 1;i <= N;i++) scanf("%d", a + i), used[i] = false;
    for(int i = 1;i < MAXA;i++) ct[i] = 0;
    
    ans = 0;
    for(int i = 0, q, cu = 0, cq;i < Q;i++) {
        scanf("%d", &q);
        cq = convert(a[q]);
        if(used[q]) {
            cu--;
            change(cq, -1);
            upd(cq, -1);
            used[q] = false;
        } else {
            cu++;
            upd(cq, 1);
            change(cq, 1);
            used[q] = true;
        }
        printf("%lld\n", tll(cu) * tll(cu-1) / 2 + ans);
    }
    
    return 0;
}