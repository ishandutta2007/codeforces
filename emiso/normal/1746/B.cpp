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

    int r = n - 1;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    for(int i = 0; i < r; i++) {
        while (i < r && a[r] == 1) r--;
        if (i >= r) break;
        if (a[i] == 1) {
            ans++;
            r--;
        }
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}