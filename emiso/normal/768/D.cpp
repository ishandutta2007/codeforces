#include <bits/stdc++.h>

using namespace std;
#define MAXD 7501

int k, q, qq;
double dp[MAXD][1001];

double solve(int days, int orb) {
    if(orb == 0) return 1;
    if(days == 0) return 0;
    double &x = dp[days][orb];
    if(x != -1) return x;

    double mult = 1.0 * orb / k;

    x = solve(days-1, orb-1) * mult;
    x += solve(days-1, orb) * (1.0 - mult);
    return x;
}

int main() {
    scanf("%d %d", &k, &q);

    for(int i = 0; i < MAXD; i++)
        for(int j = 0; j < 1001; j++)
            dp[i][j] = -1;

    while(q--) {
        scanf("%d", &qq);
        int l = 1, r = MAXD-1, m;
        while(l < r) {
            m = (l + r) >> 1;
            if(solve(m, k) >= (1e-7 + qq) / 2000) r = m;
            else l = m + 1;
        }
        printf("%d\n", l);
    }
    return 0;
}