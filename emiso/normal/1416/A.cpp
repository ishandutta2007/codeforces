#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans[MN], a[MN];
vector<int> occ[MN];


int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    for(int i = 0; i <= n + 1; i++) {
        occ[i].clear();
        ans[i] = INT_MAX;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        occ[a[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++) {
        if(occ[i].empty()) continue;
        int segm = max(0LL + occ[i][0], n - occ[i].back() + 1);
        for(int j = 1; j < occ[i].size(); j++) {
            int x = occ[i][j], last = occ[i][j-1];
            segm = max(segm, x - last);
        }
        ans[segm] = min(ans[segm], i + 0LL);
    }

    for(int i = 1; i <= n; i++) {
        ans[i] = min(ans[i], ans[i-1]);
        if(ans[i] == INT_MAX) printf("-1 ");
        else printf("%lld ", ans[i]);
    }
    puts("");

    if(--t) goto st;
    return 0;
}