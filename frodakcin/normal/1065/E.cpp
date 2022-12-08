#include <cstdio>
#include <iostream>

#include <algorithm>
#include <cassert>

using namespace std;

typedef long long ll;
#define ti(x) static_cast<int>(x)
#define tll(x) static_cast<ll>(x)

const int MOD = 998244353;
const int MAXM = 2e5 + 100;

int sum(int a, int b) {
    return (a + b)%MOD;
}
int dif(int a, int b) {
    return ti((tll(a) + b + MOD)%MOD);
}
int prod(int a, int b) {
    return ti((tll(a) * b)%MOD);
}
int pow(int b, int p) {
    assert(p >= 0);
    if(p == 0 or b == 1) return 1;
    int r = 1;
    for(;p;p>>=1, b=prod(b, b)) if(p&1) r=prod(r, b);
    return r;
}
int DC2;
int divb(int n, int d) {
    assert(d > 0);
    if(d == 1) return n;
    if(d == 2) return prod(n, DC2);
    return prod(n, pow(d, MOD - 2));
}

int N, M, A;
int b[MAXM];

int get_ans(int len) {
    int a = pow(A, len);
    return divb(prod(a, a + 1), 2);
}

int main() {
    DC2 = pow(2, MOD - 2);
    
    scanf("%d%d%d", &N, &M, &A);
    for(int i = 0;i < M;i++) scanf("%d", b + i);
    
    sort(b, b + M);
    
    int ans = get_ans(b[0]);
    for(int i = 1;i < M;i++) {
        ans = prod(ans, get_ans(b[i] - b[i - 1]));
    }
    ans = prod(ans, pow(A, N - 2 * b[M - 1]));
    printf("%d\n", ans);
    
    bool dominance = true;
    assert(dominance);
    
    return 0;
}