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
char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    ans = 0;
    scanf("%s", &s); str = s; n = str.size();

    deque<int> fila[256];
    for(int i = 0, r = 0; i < n; i++) {
        while(r < n) {
            if(str[r] != '?') {
                char ot = (str[r] == '0') ? '1' : '0';
                if(!fila[str[r]].empty() && (r-fila[str[r]].back()) % 2) break;
                if(!fila[ot].empty() && (r-fila[ot].back()) % 2 == 0) break;
            }
            fila[str[r]].push_back(r);
            r++;
        }
        ans += (r - i);
        fila[str[i]].pop_front();
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}