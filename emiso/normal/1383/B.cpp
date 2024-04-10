#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, t, ans, a[MN], f[70];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    memset(f, 0, sizeof f);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        for(int b = 0; b <= 30; b++) {
            if(a[i] & (1LL << b)) f[b]++;
        }
    }

    int flag = 0;
    for(int b = 30; b >= 0 && flag == 0; b--) {
        if(f[b] % 2 == 0) continue;
        int i = f[b], p = n - f[b];
        if(i % 4 == 1) flag = 1;
        else if(i % 4 == 3) {
            if(p % 2 == 0) flag = -1;
            else flag = 1;
        } else assert(false);
    }

    if(flag == 0) puts("DRAW");
    else if(flag < 0) puts("LOSE");
    else puts("WIN");

    if(--t) goto st;
    return 0;
}