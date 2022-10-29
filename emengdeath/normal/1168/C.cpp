#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
#include <vector>
using namespace std;
const int N = 1e6;
int a[N],g[N][20];
int f[20][20], h[20];
int n, q;
int tag[N];
int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n ; i ++)
        scanf("%d", &a[i]);
    int tot = 0;
    for (int i = n ; i >= 1; i--) {
        tag[i] = ++tot;
        for (int j = 0; j < 20; j ++)
            if (a[i] & (1 << j))
            {
                for (int k = 0; k < 20; k ++)
                    g[i][k] = max(g[i][k], f[j][k]);
                g[i][j] = max(g[i][j], h[j]);
            }
        for (int j = 0; j < 20; j ++)
            if (a[i] & (1 << j))
            {
                h[j] = max(tot, h[j]);
            }
        for (int j = 0; j < 20; j ++)
            if (a[i] & (1 << j))
            {
                for (int k = 0; k < 20; k ++)
                    f[j][k] = max(g[i][k], f[j][k]);
            }
    }
    while (q --)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        bool sig = 0;
        for (int i = 0; i < 20; i ++)
            if (a[y] & (1 << i)) {
                sig |= (g[x][i] >= tag[y]);
            }
        if (sig) printf("Shi\n");
        else
            printf("Fou\n");
    }
    return 0;
}