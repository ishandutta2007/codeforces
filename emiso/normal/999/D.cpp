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

ll t, n, m, ans, a[MN], f[MN];
vector<int> ch, occ[MN];

int main() {
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        f[a[i] % m]++;
        occ[a[i] % m].push_back(i);
    }
    for(int tt = 0; tt < 2; tt++)
        for(int i = 0; i < m; i++) {
            if(f[i] > n / m) {
                ans += f[i] - n / m;
                while(occ[i].size() > n / m) {
                    ch.push_back(occ[i].back());
                    occ[i].pop_back();
                }
                f[(i+1)%m] += f[i] - n / m;
                f[i] = n / m;
            }
            while(!ch.empty() && occ[i].size() < n / m) {
                int idx = ch.back();
                ch.pop_back();
                a[idx] = a[idx] / m * m + i + m * (a[idx] % m > i);
                occ[i].push_back(-1);
            }
        }

    printf("%lld\n", ans);
    for(int i = 0; i < n; i++)
        printf("%lld ", a[i]);
    return 0;
}