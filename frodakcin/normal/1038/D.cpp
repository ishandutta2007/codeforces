#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

const int MAXN = 5e5 + 100;
const int INF = 1e9 + 1e6;
int N;

typedef long long ll;
ll a[MAXN];

int main() {
    scanf("%d", &N);
    for(int i = 0;i < N;i++) scanf("%lld", a + i);
    if(N == 1) {
        printf("%lld\n", a[0]);
        return 0;
    }
    bool np = true, nn = true;
    for(int i = 0;i < N;i++) {
        if(a[i] >= 0) np = false;
        if(a[i] <= 0) nn = false;
    }
    ll ans = 0;
    assert(!np or !nn);
    for(int i = 0;i < N;i++) if(a[i] < 0) ans -= a[i]; else ans += a[i];
    if(np) {
        ll mn = -INF;
        for(int i = 0;i < N;i++) if(a[i] > mn) mn = a[i];
        ans += mn*2;
    }
    if(nn) {
        ll mn = INF;
        for(int i = 0;i < N;i++) if(a[i] < mn) mn = a[i];
        ans -= mn*2;
    }
    printf("%lld\n", ans);
    return 0;
}