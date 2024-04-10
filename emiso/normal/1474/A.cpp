#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, a[MN], b[MN], ans[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    int last = -1;
    for(int i = 0; i < n; i++) {
        scanf("%1lld", &b[i]);
        if(last != b[i] + 1) a[i] = 1;
        else a[i] = 0;
        last = a[i] + b[i];
    }

    for(int i = 0; i < n; i++) {
        printf("%lld", a[i]);
    } puts("");
    if(--t) goto st;
    return 0;
}