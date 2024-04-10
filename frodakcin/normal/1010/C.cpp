#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 101000;
const int MAXK = 101000;

int N, K;

int gcd(int a, int b) {
    if(b < a) return gcd(b, a);
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main() {
    //freopen("border.in", "r", stdin);
    
    scanf("%d%d", &N, &K);
    
    int a = K, b;
    for(int i = 0;i < N;i++) {
        scanf("%d", &b);
        a = gcd(a, b);
    }
    printf("%d\n", K/a);
    for(int i = 0;i < K;i++) {
        if(i%a == 0) printf("%d ", i);
    }
    printf("\n");
    
    return 0;
}