#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int i, n, x, fa[10005], cnt[10005], f[10005], a[10005], r1, r2, c[10005], j;
int root(int x){if (fa[x] != x) fa[x] = root(fa[x]); return fa[x];}
int main(){
    while (scanf("%d%d", &n, &x) == 2){
        for (i = 1; i <= n; i++){
            fa[i] = i;
            cnt[i] = 1;
        }
        for (i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            if (a[i]){
                r1 = root(a[i]); r2 = root(i);
                if (r1 != r2){
                    fa[r1] = r2;
                    cnt[r2] += cnt[r1];
                }
            }
        }
        int num = 0;
        for (i = 1; i <= n; i++) fa[i] = root(i);
        for (i = 1; i <= n; i++)
        if (fa[i] == i && i != fa[x]) c[++num] = cnt[i];
        int ans = 1;
        while (a[x] != 0){
            x = a[x];
            ans++;
        }
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (i = 1; i <= num; i++)
        for (j = n; j >= c[i]; j--)
        if (f[j - c[i]]) f[j] = 1;
        for (i = 0; i <= n; i++)
        if (f[i]) printf("%d\n", ans + i);
    }
}