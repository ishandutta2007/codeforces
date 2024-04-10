#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;
#define tll(x) static_cast<ll>(x)

const int MAXN = 110;

int N, M, w[MAXN][MAXN];
ll a[MAXN], b[MAXN], e[MAXN][MAXN];

ll gcd(ll x, ll y) {
    if(x < y) swap(x, y);
    if(y == 0) return x;
    return gcd(y, x%y);
}

int maxw;
bool rpl(int& v, const int& r) {
    if(v < r) {v = r; return true;}
    return false;
}

ll K;

ll fix(ll& v) {
    while(v < 0) v += K;
    while(v >= K) v -= K;
    return v;
}

int main() {
    scanf("%d%d", &N, &M);
    
    maxw = 0;
    for(int i = 0;i < N;i++) for(int j = 0;j < M;j++) scanf("%d", w[i] + j), rpl(maxw, w[i][j]);
    
    for(int i = 0;i < M;i++) b[i] = w[0][i];
    for(int i = 0;i < N;i++) a[i] = w[i][0] - b[0];
    
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) {
            e[i][j] = abs(w[i][j] - a[i] - b[j]);
        }
    }
    
    ll minK = e[0][0];
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) {
            minK = gcd(minK, e[i][j]);
        }
    }
    if(minK == 0) K = maxw + 1; else K = minK;
    
    if(K > maxw) {
        printf("YES\n%lld\n", K);
        for(int i = 0;i < N;i++) {
            printf("%lld ", fix(a[i]));
        }
        printf("\n");
        for(int j = 0;j < M;j++) {
            printf("%lld ", fix(b[j]));
        }
        printf("\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}