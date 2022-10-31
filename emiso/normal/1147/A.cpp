#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, k, ans, a[MN], fst[100010], lst[100010];

int main() {
    scanf("%lld %lld", &n, &k);
    ans = 3*n - 2;

    for(int i = 1; i <= k; i++) {
        scanf("%lld", &a[i]);
        if(fst[a[i]] == 0) fst[a[i]] = i;
        lst[a[i]] = i;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i-1; j <= i+1; j++) {
            if(j < 1 || j > n || fst[i] == 0 || lst[j] == 0) continue;
            if(fst[i] <= lst[j]) ans--;
        }
    }

    printf("%lld\n", ans);
    return 0;
}