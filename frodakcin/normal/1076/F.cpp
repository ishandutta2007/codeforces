#include <iostream>
#include <cstdio>

using namespace std;

void ans(bool b) {
    if(b) printf("YES\n");
    else printf("NO\n");
    exit(0);
}

const int MAXN = 3e5 + 100;

typedef long long ll;
#define tll(x) static_cast<ll>(x)
#define ti(x) static_cast<int>(x)

int N, K;

int x[MAXN], y[MAXN];

int main() {
    scanf("%d%d", &N, &K);
    
    for(int i = 1;i <= N;i++) scanf("%d", x + i);
    for(int i = 1;i <= N;i++) scanf("%d", y + i);
    
    int mx = 0, my = 0;
    
    for(int i = 1;i <= N;i++) {
        mx = ti(max(tll(0), x[i] + mx - tll(y[i]) * K));
        my = ti(max(tll(0), y[i] + my - tll(x[i]) * K));
        
        if(mx > K or my > K) ans(false);
    }
    ans(true);
    
    return 0;
}