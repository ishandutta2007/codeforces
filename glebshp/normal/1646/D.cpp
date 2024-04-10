#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int maxn = 200 * 1000 + 100;

int n;
vector <int> vertex[maxn];
int ans[maxn];
int deg[maxn];
pair <int, int> dp[maxn][2];

void go(int v, int from) {
    dp[v][0].fs = 0;
    dp[v][0].sc = 1;
    dp[v][1].fs = 1;
    dp[v][1].sc = deg[v];

    for (int u : vertex[v]) {
        if (u == from) {
            continue;
        }

        go(u, v);

        dp[v][1].fs += dp[u][0].fs;
        dp[v][1].sc += dp[u][0].sc;

        if (dp[u][0].fs > dp[u][1].fs || (dp[u][0].fs == dp[u][1].fs && dp[u][0].sc < dp[u][1].sc)) {
            dp[v][0].fs += dp[u][0].fs;
            dp[v][0].sc += dp[u][0].sc;
        } else {
            dp[v][0].fs += dp[u][1].fs;
            dp[v][0].sc += dp[u][1].sc;
        }
    }
}

void buildans(int v, int from, int a) {
    if (a == 0) {
        ans[v] = 1;
    } else {
        ans[v] = deg[v];
    }

    for (int u : vertex[v]) {
        if (u == from) {
            continue;
        }

        if (a == 1) {
            buildans(u, v, 0);
        } else {
            if (dp[u][0].fs > dp[u][1].fs || (dp[u][0].fs == dp[u][1].fs && dp[u][0].sc < dp[u][1].sc)) {
                buildans(u, v, 0);
            } else {
                buildans(u, v, 1);
            }
        }
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;

        vertex[u].pb(v);
        vertex[v].pb(u);
    }

    if (n == 2) {
        printf("2 2\n1 1\n");

        return 0;
    }

    for (int i = 0; i < n; i++) {
        deg[i] = (int) vertex[i].size();
    }

    go(0, -1);

    if (dp[0][0].fs > dp[0][1].fs || (dp[0][0].fs == dp[0][1].fs && dp[0][0].sc < dp[0][1].sc)) {
        printf("%d %d\n", dp[0][0].fs, dp[0][0].sc);
        buildans(0, -1, 0);
    } else {
        printf("%d %d\n", dp[0][1].fs, dp[0][1].sc);
        buildans(0, -1, 1);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    
    return 0;
}