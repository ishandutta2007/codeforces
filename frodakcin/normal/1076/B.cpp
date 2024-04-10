#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

void ans(const ll& v) {
    printf("%lld\n", v);
    exit(0);
}

ll N;

int main() {
    scanf("%lld", &N);
    
    for(ll i = 2;i * i <= N;i++) {
        if(N%i == 0) {
            if(i == 2) ans(N/i);
            else ans(1 + ((N-i)/2));
        }
    }
    ans(1);
    
    return 0;
}