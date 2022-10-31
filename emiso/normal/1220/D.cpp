#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, x[MN], f[MN], ans, pot = -1, qual[MN];

int main() {
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &x[i]);
        ll tmp = 0, X = x[i];
        while(X % 2 == 0) {
            X /= 2;
            tmp++;
        }
        f[tmp]++;
        qual[i] = tmp;
    }

    ans = 0;
    for(int i = 0; i < MN; i++) {
        if(ans < f[i]) {
            ans = f[i];
            pot = i;
        }
    }

    printf("%lld\n", n - ans);
    for(int i = 0; i < n; i++) {
        if(qual[i] != pot) printf("%lld ", x[i]);
    }

    return 0;
}