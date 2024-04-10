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

    int flag = 0;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(i && a[i] != a[i-1]) flag = 1;
    }

    printf("%lld\n", flag ? 1LL : n);
    if(--t) goto st;
    return 0;
}