#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

typedef long long ll;

ll N, M, K;

int gcd(int a, int b) {
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    scanf("%lld%lld%lld", &N, &M, &K);
    
    if((2 * N * M)%K != 0) {
        printf("NO\n");
        return 0;
    }
    
    int x = N, y = M, t;
    
    if((t = gcd(x, K)) > 1) x = x/t, K = K/t;
    if((t = gcd(y, K)) > 1) y = y/t, K = K/t;
    
    assert(K == 2 or (K == 1 and (x << 1 <= N or y << 1 <= M)));
    
    if(K == 2);
    else if(x << 1 <= N) x <<= 1;
    else if(y << 1 <= M) y <<= 1;
    
    printf("YES\n");
    printf("0 0\n");
    printf("%d 0\n", x);
    printf("0 %d\n", y);
    
    return 0;
}