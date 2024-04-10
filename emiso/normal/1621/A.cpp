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

ll t = 1, n, r, ans, a[MN];
char g[44][44];

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &r);

    if (r > (n + 1) / 2) puts("-1");
    else {
        memset(g, '.', sizeof g);
        for (int i = 0; i < r; i++)
            g[2*i][2*i] = 'R';
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%c", g[i][j]);
            puts("");
        }
    }

    if(--t) goto st;
    return 0;
}