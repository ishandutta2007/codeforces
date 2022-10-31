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

ll t, n, m, a[MN], f[MN], pos[MN], b[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        a[i]--;
        a[i+n] = a[i];
        pos[a[i]] = i;
        f[i] = f[i+n] = 0;
    }

    for(int i = 0; i < n; i++) {
        if(pos[i] >= i) f[pos[i]-i]++;
        f[pos[i]+n-i]++;
    }

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(f[i] + 2*m < n) continue;

        int swaps = 0;
        for(int j = 0; j < n; j++) b[j] = a[i+j];
        for(int j = 0; swaps <= m && j < n; j++) {
            while(b[j] != j) {
                swaps++;
                swap(b[j], b[b[j]]);
            }
        }

        if(swaps <= m) ans.push_back(i);
    }


    printf("%lld", ans.size());
    for(int x : ans) printf(" %d", x);
    puts("");
    if(--t) goto st;
    return 0;
}