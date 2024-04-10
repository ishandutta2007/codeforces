#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;
const int mod = 1e9 + 7;
struct node{
    char x0, x1, x2;
    int v, sum;
    node(char X0 = 0, char X1 = 0, char X2 = 0, int V = 0, int sum1 = 0)
    {
        x0 = X0, x1 = X1, x2 = X2, v = V;
        sum = sum1;
    }
    long long getV(){
        return x0 + 1LL*x1 * 51 + 1LL*x2 * 51 * 51 + 1LL * v * 51 * 51 * 51;
    }
};
vector<node> g[2];
unordered_map<long long, int>have[2];
int f[51][51][51][51][3], all[51][51][51], help[51];
int n, M;
void update(int bz, node &a)
{
    long long v = a.getV();
    int x;
    if (!(x = have[bz][v])) {
        g[bz].push_back(a);
        have[bz][v] = g[bz].size();
    } else {
        g[bz][x - 1].sum += a.sum;
        if (g[bz][x - 1].sum >= mod) g[bz][x - 1].sum -= mod;
    }
}
int main()
{
    f[0][0][0][0][0] = 1;
    help[0] = 1;
    for (int i = 1; i <= 50; i ++) {
        help[i] = 1ll*help[i - 1] * i % mod;
    }
    for (int i = 0; i <= 50 ; i++)
        for (int x0 = 0; x0 < 50; x0 ++)
            for (int x1 = 0 ; x1 < 50; x1 ++)
                for (int x2 = 0; x2 < 50 ; x2 ++)
                    for (int j = 0; j < 3; j ++)
                        if (f[i][x0][x1][x2][j]) {
                            if (i != 50) {
                                if (i == 0 || j != 0) {
                                    f[i + 1][x0 + 1][x1][x2][0] += f[i][x0][x1][x2][j];
                                    if (f[i + 1][x0 + 1][x1][x2][0] >= mod)
                                        f[i + 1][x0 + 1][x1][x2][0] -= mod;
                                }

                                if (i == 0 || j != 1) {
                                    f[i + 1][x0][x1 + 1][x2][1] += f[i][x0][x1][x2][j];
                                    if (f[i + 1][x0][x1 + 1][x2][1] >= mod)
                                        f[i + 1][x0][x1 + 1][x2][1] -= mod;
                                }

                                if (i == 0 || j != 2) {
                                    f[i + 1][x0][x1][x2 + 1][2] += f[i][x0][x1][x2][j];
                                    if (f[i + 1][x0][x1][x2 + 1][2] >= mod)
                                        f[i + 1][x0][x1][x2 + 1][2] -= mod;
                                }
                            }
                            all[x0][x1][x2] = (all[x0][x1][x2] + 1ll * f[i][x0][x1][x2][j] * help[x0] % mod * help[x1] % mod * help[x2] % mod) % mod;
                        }
    node x = node(0, 0, 0, 0, 1);
    g[0].push_back(x);
    int bz = 0, bz1 = 1;
    scanf("%d %d", &n, &M);
    for (int i = 1; i <= n ; i ++, swap(bz, bz1)) {
        int t, G;
        scanf("%d %d", &t, &G);
        for (auto u:g[bz])
        {
            update(bz1, u);
            x = u;
            if (G == 1) x.x0 ++;
            else
            if (G == 2) x.x1 ++;
            else
                x.x2 ++;
            x.v += t;
            if (x.v >M) continue;
            update(bz1, x);
        }
        g[bz].clear();
        have[bz].clear();
    }
    int ans = 0;
    for (auto u:g[bz])
        if (u.v == M)
        ans = (ans + 1ll * all[u.x0][u.x1][u.x2] * u.sum) % mod;
    printf("%d\n", ans);
    return 0;
}