#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN], c[2][4];

int main() {
    scanf("%lld", &t);
    st:

    for(int i = 0; i < 4; i++) {
        scanf("%lld %lld", &c[0][i], &c[1][i]);
    }

    ans = 10LL * INT_MAX;
    for(int d = 0; d < 2; d++) {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(c[d][i] == c[d][j]) continue;
                for(int k = 0; k < 4; k++) {
                    ll delta = abs(c[d][i] - c[d][j]);
                    vector<int> p({0, 1, 2, 3});
                    do {
                        for(int z = 0; z < 2; z++, delta = -delta) {
                            ans = min(ans, abs(c[d][p[0]] - c[d][i]) + abs(c[!d][p[0]] - c[!d][k]) +
                                           abs(c[d][p[1]] - c[d][i]) + abs(c[!d][p[1]] - c[!d][k]  + delta) +
                                           abs(c[d][p[2]] - c[d][j]) + abs(c[!d][p[2]] - c[!d][k]  + delta) +
                                           abs(c[d][p[3]] - c[d][j]) + abs(c[!d][p[3]] - c[!d][k]));
                        }
                    } while(next_permutation(p.begin(), p.end()));
                }
            }
        }
    }


    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}