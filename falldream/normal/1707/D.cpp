#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define ll long long
#define MN 2000
using namespace std;
// my fast read template
inline int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='1')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

/*
label each node with 1-n
label of x not smaller than maximum of any two subtrees (can be smaller than only 1)
then iterate over total number of rounds R, include-exclude to find s.t. all numbers in [1,R] do appear
treat the root specially since it's not deleted (labeled)
*/


int n, mod, cnt, head[MN + 5], f[MN + 5][MN + 5], c[MN + 5][MN + 5], zero_num[MN + 5][MN + 5], g[MN + 5][MN + 5], C[MN + 5][MN + 5];
struct edge{
    int to, next;
}e[MN * 2 + 5];

inline void ins(int x, int y) {
    e[++cnt] = (edge){y, head[x]}; head[x] = cnt;
    e[++cnt] = (edge){x, head[y]}; head[y] = cnt;
}

inline int inv(int x) {
    int ans = 1;
    for (int k = mod - 2; k; k >>= 1, x = 1LL * x * x % mod) {
        if (k & 1) {
            ans = 1LL * ans * x % mod;
        }
    }
    return ans;
}

int exclude(int x, int z, int y) {
    if (y == 0) {
        return z == 1 ? x : 0;
    } else {
        return z ? 0 : 1LL * x * inv(y) % mod;
    }
}

void dp(int x, int fa) {
    bool first_vertex = true;
    for (int i = head[x]; i; i = e[i].next) {
        if (e[i].to != fa) {
            dp(e[i].to, x);
            if (x > 1) {
                if (first_vertex) {
                    for (int j = 1; j < n; ++j) {
                        if (g[e[i].to][j] > 0) {
                            c[x][j] = g[e[i].to][j];
                        } else {
                            c[x][j] = 1;
                            zero_num[x][j] = 1;
                        }
                    }
                    first_vertex = false;
                } else {
                    for (int j = 1; j < n; ++j) {
                        if (g[e[i].to][j]) {
                            c[x][j] = 1LL * c[x][j] * g[e[i].to][j] % mod;
                        } else {
                            ++zero_num[x][j];
                        }
                    }
                }
            }
        }
    }
    if (x == 1) return;
    for (int i = 1; i < n; ++i) {
        f[x][i] = zero_num[x][i] ? 0 : c[x][i];
    }
    for (int i = head[x]; i; i = e[i].next) {
        if (e[i].to != fa) {
            int t = 0;
            for (int j = 1; j < n; ++j) {
                f[x][j] = (f[x][j] + 1LL * t * f[e[i].to][j]) %mod;
                t = (t + exclude(c[x][j], zero_num[x][j], g[e[i].to][j])) % mod;
            }
        }
    }
    if (first_vertex) {
        for (int i = 1; i < n; ++i) {
            f[x][i] = 1;
        }
    }
    for (int j = 1; j < n; ++j) {
        g[x][j] = (g[x][j - 1] + f[x][j]) % mod;
    }
}

int main() {
    n = read(); mod = read();
    for (int i = 1; i < n; ++i) {
        ins(read(), read());
    }
    dp(1, 0);
    f[1][1] = 1;
    for (int i = head[1]; i; i = e[i].next) {
        int t = 0, to = e[i].to;
        for (int j = 1; j < n; ++j) {
            int tt = f[1][j];
            f[1][j] = (1LL * g[to][j] * f[1][j] + 1LL * t * f[to][j]) % mod;
            t = (t + tt) % mod;
        }
    }
    for (int i = 0; i <= n; ++i) C[i][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }
    for (int i = 1; i < n; ++i) {
        g[1][i] = f[1][i];
        int sign = mod - 1;
        for (int j = i; --j; sign = mod - sign) {
            g[1][i] = (g[1][i] + 1LL * sign * C[i - 1][j - 1] % mod * f[1][j]) % mod;
        }
        printf("%d ", g[1][i]);
    }
    return 0;
}