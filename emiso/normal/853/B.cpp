#include <bits/stdc++.h>

#define MN 1001000
#define INF 1000000000000LL
#define BINF 1000000000000000000LL
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n, m, k;
ll ans, d[MN], f[MN], t[MN], c[MN], be[MN], br[MN], minc[MN];
vector<int> esq[MN], dir[MN];

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);

    for(int i=1; i<=m; i++) {
        scanf("%lld %lld %lld %lld", &d[i], &f[i], &t[i], &c[i]);
        if(f[i] == 0) dir[d[i]].push_back(i);
        else esq[d[i]].push_back(i);
    }

    for(int i=1; i<=n; i++) minc[i] = INF;
    be[0] = INF * n;

    for(int i=1; i<=1000000; i++) {
        be[i] = be[i-1];
        for(int j : esq[i]) {
            if(c[j] < minc[f[j]]) {
                be[i] = be[i] - minc[f[j]] + c[j];
                minc[f[j]] = c[j];
            }
        }
    }

    for(int i=1; i<=n; i++) minc[i] = INF;
    br[1000001] = INF * n;

    for(int i=1000000; i>0; i--) {
        br[i] = br[i+1];
        for(int j : dir[i]) {
            if(c[j] < minc[t[j]]) {
                br[i] = br[i] - minc[t[j]] + c[j];
                minc[t[j]] = c[j];
            }
        }
    }

    ans = BINF;
    for(int i = 1; i + k <= 1000000; i++) {
        if(be[i] < INF && br[i + k + 1] < INF) ans = min(ans, be[i] + br[i + k + 1]);
    }

    if(ans > INF) printf("-1\n");
    else printf("%lld\n", ans);
    return 0;
}