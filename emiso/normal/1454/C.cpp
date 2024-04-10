#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];
vector<int> occ[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        occ[a[i]].push_back(i);
    }

    ans = n;
    for(int i = 1; i <= n; i++) {
        if(occ[i].empty()) continue;
        int last = -1, tmp = 0;
        for(int x : occ[i]) {
            tmp += (last + 1 < x);
            last = x;
        }
        tmp += (last < n-1);
        ans = min(ans, tmp + 0LL);
    }

    printf("%lld\n", ans);
    for(int i = 0; i <= n; i++) {
        occ[i].clear();
    }

    if(--t) goto st;
    return 0;
}