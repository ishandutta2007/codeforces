#include <bits/stdc++.h>

using namespace std;

int n, k, l[110], r[110], dp[2][100010], ndp[2][100010];
vector<int> gmin[2];

vector<int> get_min(int n, int sz, int id) {
    vector<int> tmp, ret;
    int cont = 0;
    for(int i = 0; i <= n; i++) {
        int x = dp[id][i];
        while(cont < tmp.size() && x < dp[id][tmp.back()])
            tmp.pop_back();
        tmp.push_back(i);

        if(i > sz && tmp[cont] == i - sz - 1) cont++;
        ret.push_back(dp[id][tmp[cont]]);
    }
    return ret;
}

int main() {
    scanf("%d %d", &n, &k);

    for(int i = 1; i <= k; i++)
        scanf("%d %d", &l[i], &r[i]);

    for(int i = 1; i < 100010; i++)
        dp[0][i] = dp[1][i] = 99999;

    l[0] = r[0] = 0;
    l[k+1] = r[k+1] = 2*n;
    for(int i = 1; i <= k+1; i++) {
        for(int j = 0; j < 100010; j++)
            ndp[0][j] = ndp[1][j] = 99999;

        int dist = l[i] - r[i-1];
        gmin[0] = get_min(n, r[i] - l[i], 0);
        gmin[1] = get_min(n, r[i] - l[i], 1);

        for(int p = 0; p <= n; p++) {
            ndp[1][p] = dp[1][p];
            if(p >= r[i] - r[i-1]) ndp[0][p] = min(ndp[0][p], dp[0][p - r[i] + r[i-1]]);

            ndp[0][p] = min(ndp[0][p], gmin[1][p] + 1);
            if(p >= dist) ndp[1][p] = min(ndp[1][p], gmin[0][p-dist] + 1);

            if(p >= dist) ndp[0][p] = min(ndp[0][p], gmin[0][p-dist] + 2);
            ndp[1][p] = min(ndp[1][p], gmin[1][p] + 2);
        }
        memcpy(dp, ndp, sizeof dp);
    }
    int x = min(dp[0][n], dp[1][n]);
    if(x > 1000) puts("Hungry");
    else {
        puts("Full");
        printf("%d\n", x);
    }
    return 0;
}