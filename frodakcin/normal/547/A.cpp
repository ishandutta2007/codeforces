#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

const int N = 2;

typedef long long ll;
#define tll(x) static_cast<ll>(x)
#define ti(x) static_cast<int>(x)

void ans(ll a) {
    printf("%lld\n", a);
    exit(0);
}

const ll INF = 1e16;
ll solve(ll m, ll b, ll x, ll d) {
    assert(b >= 0 and d != 0);
    if(d < 0) d *= -1LL;
    if(m < 0) m*=-1LL, x *= -1LL;
    
    while(x < 0) x += d * (INF/d);
    x = x%d;
    
    return m * x + b;
}

int M;

int sum(const int& a, const int& b) {
    return ti((tll(a)+tll(b))%M);
}
int prod(const int& a, const int& b) {
    return ti((tll(a)*tll(b))%M);
}

int h[N], a[N], x[N], y[N];
int v[N][2];

ll gcd(const ll& a, const ll& b, ll& n, ll& m) {
    if(a < b) return gcd(b, a, m, n);
    if(b == 0) {
        n = 1;
        m = 0;
        return a;
    }
    ll vb, vm, r = gcd(b, a%b, vb, vm);
    
    n = vm;
    m = vb - vm * (a/b);
    
    assert(n * a + m * b == r);
    
    return r;
}

int main() {
    scanf("%d", &M);
    for(int i = 0;i < N;i++) scanf("%d%d%d%d", h + i, a + i, x + i, y + i);
    
    for(int i = 0;i < N;i++) for(int j = 0;j < 2;j++) v[i][j] = -1;
    
    for(int t = 0, c[2] = {h[0], h[1]}, r;t < 2*M;t++) {
        r = 0;
        for(int i = 0;i < N;i++) {
            if(c[i] == a[i]) {
                for(int j = 0;j < 2;j++) if(v[i][j] == -1) {v[i][j] = t; break;}
                r++;
            }
        }
        if(r == N) ans(t);
        
        for(int i = 0;i < N;i++) c[i] = sum(prod(c[i], x[i]), y[i]);
    }
    
    for(int i = 0;i < N;i++) if(v[i][0] == -1 or v[i][1] == -1) ans(-1);
    
    ll n[N];
    ll cl[N];
    for(int i = 0;i < N;i++) cl[i] = v[i][1] - v[i][0];
    
    ll g = gcd(cl[0], cl[1], n[0], n[1]);
    n[1] *= -1LL;
    assert(cl[0] * n[0] - cl[1] * n[1] == g);
    
    ll l[N];
    for(int i = 0;i < N;i++) l[i] = v[i][0];
    if(abs(l[1] - l[0])%g) ans(-1);
    ll p = (l[1]-l[0])/g;
    
    ll f[2];
    f[0] = solve(cl[0], l[0], n[0]*p, cl[1]/g);
    f[1] = solve(cl[1], l[1], n[1]*p, cl[0]/g);
    
    //cerr << f[0] << " " << f[1] << "\n";
    assert(f[0] == f[1]);
    
    ans(f[0]);
    
    return 0;
}