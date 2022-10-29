#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;
const int N = (1 << 9);
int sum[N], f[N], c[100001], ans[2], v[100001];
int n, m;
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n ; i ++) {
        int x = 0, y, cnt;
        scanf("%d", & cnt);
        while (cnt --) {
            scanf("%d", &y);
            x |= (1 << (y - 1));
        }
        for (int j = 1; j < N; j ++)
            if ((j & x) == x) sum[j] ++;
    }
    for (int i = 1; i <= m ; i++) {
        scanf("%d", &c[i]);
        int x = 0, y , cnt;
        scanf("%d",&cnt);
        while (cnt --) {
            scanf("%d", &y);
            x |= (1 << ( y - 1));
        }
        v[i] = x;
        for (int j = 1; j < N ; j ++) {
            if (f[j]) {
                if (!ans[0] ||(sum[v[ans[0]] | v[ans[1]]] < sum[v[f[j]] | v[i]] || ( sum[v[ans[0]] | v[ans[1]]] == sum[v[f[j]] | v[i]] && c[ans[0]] + c[ans[1]] > c[f[j]] + c[i])) ) ans[0] = f[j], ans[1] = i;
            }
        }
        if (!f[v[i]] || c[f[v[i]]] > c[i]) f[v[i]] = i;
    }
    printf("%d %d\n", ans[0], ans[1]);
    return 0;
}