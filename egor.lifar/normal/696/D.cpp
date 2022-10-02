#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <tuple>


using namespace std;


#define next next2203
#define link link2203
const long long INF = 2LL * (long long)(1e18);
const int N = 222;
int sz;
int link[N], pv[N], pc[N], a[N], ver[N], q[N];
char buf[N];
int next[N][26], go[N][26], sum[N];
long long dp[N][N], tmp[N][N], g[N][N];


inline void update(long long a[N][N], long long b[N][N]) {
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            tmp[i][j] = -INF;
            for (int z = 0; z < sz; z++) {
                if (a[i][z] == -INF || b[z][j] == -INF) {
                    continue;
                }
                tmp[i][j] = max(tmp[i][j], a[i][z] + b[z][j]);
            }
        }
    }
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            a[i][j] = tmp[i][j];
        }
    }
}


inline void findans(long long n) {
    if (n == 1) {
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                dp[i][j] = g[i][j];
            }
        }
        return;
    }
    if (n % 2 == 0) {
        findans(n / 2);
        update(dp, dp);
    } else {
        findans(n - 1);
        update(dp, g);
    }
}

int main() {
    int n;
    long long L;
    cin >> n >> L;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sz = 1;
    for (int i = 0; i < 26; i++) {
        next[0][i] = -1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", buf);
        int len = strlen(buf), cur = 0;
        for (int j = 0; j < len; j++) {
            int c = buf[j] - 'a';
            if (next[cur][c] == -1) {
                for (int z = 0; z < 26; z++) {
                    next[sz][z] = -1;
                }
                pv[sz] = cur;
                pc[sz] = c;
                next[cur][c] = sz++;
            }
            cur = next[cur][c];
        }
        ver[i] = cur;
        sum[cur] += a[i];
    }
    int l = 0, r = 1;
    q[0] = 0;
    while (l < r) {
        int v = q[l++];
        if (v == 0 || pv[v] == 0) {
            link[v] = 0;
        } else {
            link[v] = go[link[pv[v]]][pc[v]];
        }
        if (v > 0) {
            sum[v] += sum[link[v]];
        }
        for (int i = 0; i < 26; i++) {
            if (next[v][i] != -1) {
                go[v][i] = next[v][i];
                q[r++] = next[v][i];
            } else {
                if (v == 0) {
                    go[v][i] = 0;
                } else {
                    go[v][i] = go[link[v]][i];
                }
            }
        }
    }
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            g[i][j] = -INF;
        }
    }
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < 26; j++) {
            g[i][go[i][j]] = max(g[i][go[i][j]], 1LL * sum[go[i][j]]);
        }
    }
    findans(L);
    long long ans = -INF;
    for (int i = 0; i < sz; i++) {
        ans = max(ans, dp[0][i]);
    }
    cout << ans << endl;
    return 0;
}