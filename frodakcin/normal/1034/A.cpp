#include <iostream>
#include <cstdio>

#include <ctime>
#include <bitset>
#include <cassert>

#include <vector>

using namespace std;

const int MAXN = 3e5 + 1000;
const int MAXV = 15e6 + 1500;
const int MAXV6 = MAXV/6;
const int PIV = 1e6;

typedef vector<int> vi;

int p[PIV], ps, loc[MAXV];
bitset<MAXV6 + 1> m1, m5;

bool prime(int n) {
    if(n == 2 or n == 3) return true;
    if(n%6 == 1) return m1[n/6];
    if(n%6 == 5) return m5[n/6];
    return false;
}
void fill1(int n) {
    assert(n%6 == 1);
    for(int i = n/6 + n;i < MAXV6;i += n) m1[i] = false;
    for(int i = 5*n/6 + n;i < MAXV6;i += n) m5[i] = false; 
}
void fill5(int n) {
    assert(n%6 == 5);
    for(int i = n/6 + n;i < MAXV6;i += n) m5[i] = false;
    for(int i = 5*n/6 + n;i < MAXV6;i += n) m1[i] = false; 
}

int N, a[MAXN];
int fc[PIV], cc[PIV], oc[PIV];

int f[PIV], c[PIV], ct;
void factor(int n) {
    ct = 0;
    for(int i = 0;i < ps and p[i] * p[i] <= n;i++) {
        if(n%p[i] == 0) {
            f[ct] = i;
            c[ct] = 0;
            while(n%p[i] == 0) n /= p[i], c[ct]++;
            ct++;
        }
    }
    if(n > 1) {
        assert(prime(n) and loc[n] != -1);
        f[ct] = loc[n];
        c[ct] = 1;
        ct++;
    }
}

int main() {
    ps = 0;
    p[ps++] = 2;
    p[ps++] = 3;
    
    for(int i = 0;i < MAXV6;i++) m1[i] = m5[i] = true;
    for(int i = 0;i < MAXV;i++) loc[i] = -1;
    fill5(5);
    p[ps++] = 5;
    
    loc[2] = 0;
    loc[3] = 1;
    loc[5] = 2;
    
    
    for(int i = 1;i < MAXV6;i++) {
        if(prime(i * 6 + 1)) {
            loc[i * 6 + 1] = ps;
            p[ps++] = i * 6 + 1;
            fill1(i * 6 + 1);
        }
        if(prime(i * 6 + 5)) {
            loc[i * 6 + 5] = ps;
            p[ps++] = i * 6 + 5;
            fill5(i * 6 + 5);
        }
    }
    
    scanf("%d", &N);
    for(int i = 0;i < N;i++) scanf("%d", a + i);
    
    for(int i = 0;i < PIV;i++) fc[i] = 1e9, cc[i] = 0, oc[i] = N;
    
    int ans = 0;
    for(int i = 0;i < N;i++) {
        factor(a[i]);
        for(int j = 0;j < ct;j++) {
            oc[f[j]]--;
            if(fc[f[j]] == c[j]) cc[f[j]]++;
            if(fc[f[j]] > c[j]) {
                fc[f[j]] = c[j];
                cc[f[j]] = 1;
            }
        }
    }
    
    ans = N;
    for(int i = 0, t;i < ps;i++) {
        if((t = oc[i] > 0 ? oc[i] : cc[i]) < ans) ans = t;
    }
    if(ans == N) ans = -1;
    
    printf("%d\n", ans);
    
    return 0;
}