#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], x, y, lst = 1, segm = 0;

int main() {
    scanf("%lld %lld %lld", &n, &x, &y);

    for(int i = 0; i < n; i++) {
        scanf("%1lld", &a[i]);
        if(lst == 1 && a[i] == 0) segm++;
        lst = a[i];
    }

    if(segm > 0) {
        if(x > y) ans = segm * y;
        else ans = (segm-1) * x + y;
    }

    printf("%lld\n", ans);
    return 0;
}