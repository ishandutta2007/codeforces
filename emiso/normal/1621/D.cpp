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

ll t = 1, n, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    int mini = INT_MAX;
    for(int i = 0; i < 2*n; i++) {
        for (int j = 0, x; j < 2 * n; j++) {
            scanf("%d", &x);
            if (i >= n && j >= n) ans += x;
            else if ((i == 0 || i + 1 == n) && (j == n || j + 1 == 2*n)) {
                mini = min(mini, x);
            }
            else if ((j == 0 || j + 1 == n) && (i == n || i + 1 == 2*n)) {
                mini = min(mini, x);
            }
        }
    }

    printf("%lld\n", ans + mini);
    if(--t) goto st;
    return 0;
}