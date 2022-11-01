#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN], q;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &q);

    for(int i = 0; i < n; i++) {
        scanf("%1lld", &a[i]);
    }
    for(int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--; r--;
        int flag = 0;
        for(int i = 0; !flag && i < l; i++) if(a[i] == a[l]) flag = 1;
        for(int i = r+1; !flag && i < n; i++) if(a[i] == a[r]) flag = 1;
        puts(flag ? "YES" : "NO");
    }

    if(--t) goto st;
    return 0;
}