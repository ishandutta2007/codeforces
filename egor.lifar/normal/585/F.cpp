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
#include <complex>
#include <unordered_map>


using namespace std;


#define next _next
#define link _link
const int N = 1010;
const int M = 25;
const int MOD = int(1e9) + 7;

int sz;
char s[N], x[N], y[N];
int pv[N * M], pc[N * M], link[N * M], q[N * M], len[N * M];
int next[N * M][10], go[N * M][10];
int dp[N * M][2][2], ndp[N * M][2][2];


inline void build() {
    scanf("%s", s);
    int n = strlen(s);
    sz = 1;
    for (int i = 0; i < 10; i++) {
        next[0][i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < M && i + j < n; j++) {
            if (next[cur][s[i + j] - '0'] == -1) {
                for (int z = 0; z < 10; z++) {
                    next[sz][z] = -1;
                }
                pv[sz] = cur;
                pc[sz] = s[i + j] - '0';
                len[sz] = len[cur] + 1;
                next[cur][s[i + j] - '0'] = sz++;
            }
            cur = next[cur][s[i + j] - '0'];
        }
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
        for (int i = 0; i < 10; i++) {
            if (next[v][i] != -1) {
                go[v][i] = next[v][i];
            } else {
                if (v == 0) {
                    go[v][i] = 0;
                } else {
                    go[v][i] = go[link[v]][i];
                }
            }
        }
        for (int i = 0; i < 10; i++) {
            if (next[v][i] != -1) {
                q[r++] = next[v][i];
            }
        }
    }
}


inline int calc(char* s) {
    int n = strlen(s);
    assert(n / 2 <= M);
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < 2; j++) {
            for (int z = 0; z < 2; z++) {
                dp[i][j][z] = 0;
            }
        }
    }
    dp[0][0][1] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz; j++) {
            for (int z = 0; z < 2; z++) {
                for (int h = 0; h < 2; h++) {
                    ndp[j][z][h] = 0;
                }
            }
        }
        for (int j = 0; j < sz; j++) {
            for (int z = 0; z < 2; z++) {
                for (int h = 0; h < 2; h++) {
                    if (dp[j][z][h] == 0) {
                        continue;
                    }
                    for (int c = (i == 0 ? 1 : 0); c <= (h ? s[i] - '0' : 9); ++c) {
                        int nj = go[j][c];
                        int nz = (z | (len[nj] >= n / 2));
                        int nh = h;
                        if (h && c < s[i] - '0') {
                            nh = 0;
                        }
                        ndp[nj][nz][nh] += dp[j][z][h];
                        if (ndp[nj][nz][nh] >= MOD) {
                            ndp[nj][nz][nh] -= MOD;
                        }
                    }
                }
            }
        }
        for (int j = 0; j < sz; j++) {
            for (int z = 0; z < 2; z++) {
                for (int h = 0; h < 2; h++) {
                    dp[j][z][h] = ndp[j][z][h];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < sz; i++) {
        ans = (ans + dp[i][1][0]) % MOD;
        ans = (ans + dp[i][1][1]) % MOD;
    }
    return ans;
}


inline bool check(char* s) {
    int n = strlen(s), cur = 0, max_len = 0;
    for (int i = 0; i < n; i++) {
        cur = go[cur][s[i] - '0'];
        max_len = max(max_len, len[cur]);
    }
    if (max_len >= n / 2) {
        return true;
    } else {
        return false;
    }
}


int main() {
    build();
    scanf("%s %s", x, y);
    int n = strlen(x);
    int ptr = 0;
    while (ptr < n && x[ptr] == y[ptr]) {
        ptr++;
    }
    if (ptr < n && x[ptr] > y[ptr]) {
        puts("0");
        return 0;
    }
    int ans = (MOD - calc(x)) % MOD;
    if (check(x)) {
        ans = (ans + 1) % MOD;
    }
    ans = (ans + calc(y)) % MOD;
    cout << ans << endl;
    return 0;
}