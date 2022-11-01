#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    if(n == 1) puts("9");
    else if(n == 2) puts("98");
    else {
        printf("98");
        for(int i = 2, d = 9; i < n; i++, d = (d + 1) % 10) {
            printf("%d", d);
        } puts("");
    }

    if(--t) goto st;
    return 0;
}