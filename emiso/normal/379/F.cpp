#include <bits/stdc++.h>
#define MN 1000100

using namespace std;

int q, l, n = 4, dp[MN][20], dep[MN], c1 = 1, c2 = 2, diam = 2;

int lca(int a, int b) {
    if(dep[a] < dep[b]) swap(a, b);

    for(int i = 19; i >= 0; i--)
        if(dep[dp[a][i]] >= dep[b])
            a = dp[a][i];

    if(a == b) return a;

    for(int i = 19; i >= 0; i--)
        if(dp[a][i] != dp[b][i]) {
            a = dp[a][i];
            b = dp[b][i];
        }

    return dp[a][0];
}

int dist(int a, int b) {
    return dep[a] + dep[b] - 2 * dep[lca(a, b)];
}

int main() {
    scanf("%d", &q);
    dep[1] = dep[2] = dep[3] = 1;

    while(q--) {
        scanf("%d", &l); --l;
        for(int k = 0; k < 2; k++, n++) {
            dp[n][0] = l;
            dep[n] = dep[l] + 1;

            for(int i = 1; i < 20; i++)
                dp[n][i] = dp[dp[n][i-1]][i-1];

            if(dist(n, c1) > diam) {
                c2 = n;
                diam = dist(n, c1);
            }

            else if(dist(n, c2) > diam) {
                c1 = n;
                diam = dist(n, c2);
            }
        }

        printf("%d\n", diam);
    }
    return 0;
}