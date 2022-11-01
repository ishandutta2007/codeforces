#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
#define trace2(args...) trace(args)
#endif

#define MN 1001000

ll t = 1, n, ans, a[MN], deg[MN];
vector<int> radj[MN];

int main() {
    scanf("%lld", &t);
    st: ans = 1;
    scanf("%lld", &n);

    for(int i = 0; i <= n; i++) {
        radj[i].clear();
        deg[i] = 0;
    }

    for(int i = 1, x, j; i <= n; i++) {
        scanf("%d", &x);
        while(x--) {
            scanf("%d", &j);
            radj[j].push_back(i);
            deg[i]++;
        }
    }

    int tot = 0, idx = 0;
    set<int> pq;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 0)
            pq.insert(i);
    }

    while(!pq.empty()) {
        auto tt = pq.upper_bound(idx);
        if(tt == pq.end()) {
            tt = pq.begin();
            ans++;
        }
        
        idx = *tt;
        pq.erase(tt);
        tot++;

        for(int v : radj[idx]) {
            deg[v]--;
            if(deg[v] == 0) {
                pq.insert(v);
            }
        }
    }

    if(tot == n) printf("%lld\n", ans);
    else puts("-1");
    if(--t) goto st;
    return 0;
}