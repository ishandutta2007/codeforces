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

ll t, n, ans, a[MN];
char s[MN]; string str, pat;
vector<int> occ[256];

int main() {
    scanf("%lld", &t);
    st:
    ans = 0;
    scanf("%s", &s); pat = s; n = pat.size();
    scanf("%s", &s); str = s;

    for(int i = 0; i < 256; i++) occ[i].clear();
    for(int i = 0; i < n; i++) {
        occ[pat[i]].push_back(i);
    }

    ans = 1;
    int i = 0;
    for(int j = 0; j < str.size(); j++) {
        auto lb = lower_bound(occ[str[j]].begin(), occ[str[j]].end(), i);
        if(lb == occ[str[j]].end()) {
            i = 0;
            ans++;
            lb = lower_bound(occ[str[j]].begin(), occ[str[j]].end(), i);
            if(lb == occ[str[j]].end()) {
                ans = -1;
                break;
            }
        }
        i = *lb + 1;
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}