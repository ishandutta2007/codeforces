#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
template<typename... Args> void recInit(Args... args) {}
template<typename... Args> void recEnd(Args... args) {}
#define trace2(args...) trace(args)
#endif

ll t, n, k, a[MN], b[MN], ans;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &k);

    fill(a, a + 2*n+2, 0);
    vector<int> un;
    for(int i = 0; i < k; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u] = v;
        a[v] = u;
    }
    for(int i = 1; i <= 2*n; i++) {
        if(a[i] == 0) un.push_back(i);
    }

    for(int ini = 0; ini < max((int)un.size(), 1); ini++) {
        //for(int d = 1; d < un.size(); d++) {
        int d = un.size() / 2;
            for(int i = 1; i <= 2*n; i++) b[i] = a[i];
            for(int i = ini, z = 0; z < un.size(); z++, i = (i + 1) % un.size()) {
                if(b[un[i]]) continue;
                b[un[i]] = -1;
                int j = (i + d) % un.size();
                while(b[un[j]]) j = (j + 1) % un.size();
                b[un[i]] = un[j];
                b[un[j]] = un[i];
            }

            ll cur = 0, sum = 0;
            for(int i = 1; i <= 2*n; i++) {
                if(b[i] > i) {
                    for(int j = i + 1; j < b[i]; j++)
                        cur += (b[j] > b[i]);
                }
            }
            ans = max(ans, cur);
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}