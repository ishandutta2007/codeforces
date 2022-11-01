#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, m, ans[MN], a[MN], use[MN], where, sum;

int main() {
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < m; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }

    if(sum < n) {
        puts("-1");
        return 0;
    }

    for(int i = m-1; i >= 0; i--) {
        if(where < a[i]) {
            use[i] = a[i] - where;
            where = a[i];
            ans[i] = 1;
        } else {
            ans[i] = where + 1 - a[i] + 1;
            use[i] = 1;
            where = where + 1;
        }
    }

    if(where > n) {
        puts("-1");
        return 0;
    }

    int tmp = 0;
    for(int i = m-1; i >= 0; i--) {
        if(use[i] < a[i]) {
            tmp += min(a[i] - use[i], n - tmp - where);

        }
        ans[i] += tmp;
    }

    for(int i = 0; i < m; i++) {
        printf("%lld ", ans[i]);
    }

    return 0;
}