#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, m, ans, a[550][550];

int main() {
    scanf("%lld %lld", &n, &m);

    if(n == 1 && m == 1) puts("0");
    else if(n == 1) {
        for(int i = 0; i < m; i++) printf("%d ", i + 2);
        puts("");
    } else if(m == 1) {
        for(int i = 0; i < n; i++) printf("%d\n", i + 2);
    } else {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                printf("%lld ", (i + 1LL) * (j + 1LL + n));
            }
            puts("");
        }
    }
    return 0;
}