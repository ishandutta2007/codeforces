#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        for (int j = 0; j <= i; j++) {
            int z = 0;
            for (int k = j; k <= i; k++) z += (a[k] == 0);
            ans += (i - j + 1 + z);
        }
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}