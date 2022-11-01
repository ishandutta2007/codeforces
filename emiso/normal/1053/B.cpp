#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a, b[MN], acumb[MN], acum2[2][MN];

int main() {
    scanf("%lld", &n);

    acum2[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a);
        b[i] = __builtin_popcountll(a);
        acumb[i] = acumb[i-1] + b[i];
        acum2[0][i] = acum2[0][i-1] + (acumb[i] % 2 == 0);
        acum2[1][i] = acum2[1][i-1] + (acumb[i] % 2 == 1);
    }

    for(int i = 1; i <= n; i++) {
        ll soma = b[i], maxi = b[i], flag = 0;
        for(int j = i-1; j > 0; j--) {
            soma += b[j];
            maxi = max(maxi, b[j]);
            if(soma % 2 == 0 && soma >= 2 * maxi) ans++;

            if(soma >= 128) {
                flag = j;
                break;
            }
        }

        if(flag > 1) ans += acum2[acumb[i]%2][flag-2];
    }

    printf("%lld\n", ans);
    return 0;
}