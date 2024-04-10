#include <cstdio>
#include <iostream>

#include <ctime>
#include <random>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

ll N;
int K;

bool guess(ll l, ll r) {
    printf("%lld %lld\n", l, r);
    fflush(stdout);
    char c[10];
    scanf(" %s", c);
    if(c[0] == 'B') exit(0);
    if(l == r and c[0] == 'Y') exit(0);
    return c[0] == 'Y';
}

ll L, R;

mt19937 rng;

ll getrnd(ll l, ll h) {
    return l + (h - l) * rng() / (static_cast<ll> (rng.max()) - rng.min() + 1);
}

int main() {
    scanf("%lld%d", &N, &K);
    
    L = 1, R = N;
    rng = mt19937(clock());
    
    while(R > L + 6 * K) {
        ll M = L + (R - L)/2;
        if(guess(L, M)) {
            L = max(L - K, 1LL);
            R = min(M + K, N);
        } else {
            L = max(M - K + 1, 1LL);
            R = min(R + K, N);
        }
    }
    
    ll t;
    for(int i = 0;i < 1500;i++) {
        t = getrnd(L, R + 1);
        guess(t, t);
        L = max(L - K, 1LL);
        R = min(R + K, N);
        ll M = L + (R - L)/2;
        
        if(guess(L, M)) {
            L = max(L - K, 1LL);
            R = min(M + K, N);
        } else {
            L = max(M - K + 1, 1LL);
            R = min(R + K, N);
        }
    }
    
    return 0;
}