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

ll t = 1, n, m, q, a[MN];
char s[MN]; string str;

int main() {
    scanf("%lld %lld", &n, &m);

    vector<vector<int>> g(n, vector<int>(m));
    vector<int> xtbl(m);

    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        for(int j = 0; j < m; j++)
            g[i][j] = (s[j] == 'X');
    }

    for(int i = 1; i < m; i++) {
        int tmp = 0;
        for(int j = 1; j < n; j++)
            tmp += (g[j-1][i] && g[j][i-1]);
        xtbl[i] = xtbl[i-1] + tmp;
    }

    scanf("%lld", &q);
    for(int i = 0, l, r; i < q; i++) {
        scanf("%d %d", &l, &r);
        puts((xtbl[r-1] - xtbl[l-1] > 0) ? "NO" : "YES");
    }
    return 0;
}