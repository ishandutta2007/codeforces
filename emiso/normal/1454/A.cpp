#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    printf("%lld", n);
    for(int i = 2; i <= n; i++) {
        printf(" %d", i-1);
    }
    puts("");

    if(--t) goto st;
    return 0;
}