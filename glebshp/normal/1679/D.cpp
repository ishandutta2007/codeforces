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

const int maxn = 200 * 1000 + 1;

int n, m, k;
vector <int> vertex[maxn];
int dp[maxn];
int clr[maxn];
int a[maxn];

int dfs(int v, int x) {
    if (a[v] > x) {
        return false;
    }

    clr[v] = 1;
    dp[v] = 1;
    bool found = false;
    for (auto e : vertex[v]) {
        if (a[e] > x) {
            continue;
        }
        if (clr[e] == 1) {
            found = true;
        }
        if (clr[e] == 0) {
            if (dfs(e, x)) {
                found = true;
            }
        }
        dp[v] = max(dp[v], dp[e] + 1);
    }

    clr[v] = 2;
    return found;
}

bool check(int x) {
    for (int i = 0; i < n; i++) {
        dp[i] = -1;
        clr[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (clr[i] == 0 && a[i] <= x) {
            if (dfs(i, x)) {
                return true;
            }
            if (dp[i] >= k) {
                return true;
            }
        }
    }

    return false;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    vector <int> alla;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        alla.pb(a[i]);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;

        vertex[u].pb(v);
    }

    sort(alla.begin(), alla.end());
    
    if (!check(alla[n - 1])) {
        printf("-1");

        return 0;
    }

    int lb = -1;
    int rb = n - 1;
    while (lb + 1 < rb) {
        int mid = (lb + rb) / 2;
        if (check(alla[mid])) {
            rb = mid;
        } else {
            lb = mid;
        }
    }

    printf("%d\n", alla[rb]);

    return 0;
}