#include <iostream>
#include <cstdio>

#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 202000;

int N, a[MAXN];
int s;

int main() {
    scanf("%d%d", &N, &s);
    
    for(int i = 0;i < N;i++) {
        scanf("%d", &a[i]);
    }
    
    sort(a, a + N);
    
    ll ans = 0;
    for(int i = 0;i < (N/2);i++) {
        if(a[i] > s) ans += (a[i] - s);
    }
    for(int i = N - 1;i > (N/2);i--) {
        if(a[i] < s) ans += (s - a[i]);
    }
    ans += abs(a[(N/2)] - s);
    
    printf("%lld\n", ans);
    
    return 0;
}