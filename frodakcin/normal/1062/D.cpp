#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

const int MAXN = 1e5 + 100;
typedef long long ll;

int N;

int main() {
    scanf("%d", &N);
    
    //if(N&1)N--;
    
    ll ans = 0;
    for(int i = 2;i <= N;i++) {
        ans += 4*((N/i) - 1)*i;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}