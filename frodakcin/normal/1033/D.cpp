#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

typedef long long ll;
const int MAXN = 5e2 + 100;
const ll MOD = 998244353LL;

int N;
ll a[MAXN];

ll u[MAXN]; int uc[MAXN], us;
ll p[MAXN]; int pc[MAXN], ps;

ll rt4(ll v) {
    ll l = 1, h = v;
    while(h > l + 1) {
        ll m = l + (h - l)/2;
        if(m > v/m/m/m) h = m;
        else l = m;
    }
    if(l*l*l*l == v) return l;
    return -1;
}
ll rt3(ll v) {
    ll l = 1, h = v;
    while(h > l + 1) {
        ll m = l + (h - l)/2;
        if(m > v/m/m) h = m;
        else l = m;
    }
    if(l*l*l == v) return l;
    return -1;
}
ll rt2(ll v) {
    ll l = 1, h = v;
    while(h > l + 1) {
        ll m = l + (h - l)/2;
        if(m > v/m) h = m;
        else l = m;
    }
    if(l*l == v) return l;
    return -1;
}

ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a%b);
}

void addp(ll v, int m) {
    bool f = false;
    for(int i = 0;(not f) and i < ps;i++) if(p[i] == v) pc[i]+= m, f = true;
    if(not f) p[ps] = v, pc[ps++] = m;
}

int main() {
    
    scanf("%d", &N);
    for(int i = 0;i < N;i++) scanf("%lld", a + i);
    
    us = ps = 0;
    int st = 0;
    
    ll t;
    for(int i = 0;i < N;i++) {
        if((t = rt4(a[i])) != -1) {
            addp(t, 4);
            swap(a[i], a[st++]);
        } else if((t = rt3(a[i])) != -1) {
            addp(t, 3);
            swap(a[i], a[st++]);
        } else if((t = rt2(a[i])) != -1) {
            addp(t, 2);
            swap(a[i], a[st++]);
        }
    }
    
    for(int i = st;i < N;i++) {
        ll v = a[i];
        int f = 0;
        
        for(int j = 0;j < ps;j++) if(v%p[j] == 0) v/=p[j], pc[j]++, f++;
        if(f != 2) { 
            
            int d = 0;
            for(int j = 0;j < us;j++) {
                if(d) u[j] = u[d + j], uc[j] = uc[j + d];
                if(v == 1) continue;
                if(u[j] == v) {
                    v = 1;
                    uc[j]++;
                    f = 2;
                    continue;
                }
                if((t = gcd(v, u[j])) != 1) {
                    f++;
                    addp(t, uc[j] + 1);
                    addp(u[j]/t, uc[j]);
                    v /= t;
                    
                    j--, us--, d++;
                }
            }
            if(f == 0) u[us] = v, uc[us++] = 1;
            if(f == 1) addp(v, 1);
        }
        if(f == 2) {
            //cerr << v << '\n';
            assert(v == 1);
        }
    }
    
    ll ans = 1;
    
    for(int i = 0;i < ps;i++) {
        ans = (ans * (pc[i] + 1))%MOD;
    }
    for(int i = 0;i < us;i++) {
        ans = (ans * (uc[i] + 1) * (uc[i] + 1) )%MOD;
    }
    printf("%lld\n", ans);
    
    return 0;
}