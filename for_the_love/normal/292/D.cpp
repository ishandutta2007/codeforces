#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, i, r1, r2, num, x[10005], y[10005], q[10005], fa[505], l, r, ans;
int root(int x){
    if (fa[x] != x) fa[x] = root(fa[x]); return fa[x];
}
int main(){
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) fa[i] = i;
    for (i = 1; i <= m; i++){
        scanf("%d%d", &x[i], &y[i]);
        r1 = root(x[i]); r2 = root(y[i]);
        if (r1 != r2){
            q[++num] = i; fa[r2] = r1;
        }
    }
    for (i = 1; i <= n; i++) fa[i] = i;
    for (i = m; i > 0; i--){
        r1 = root(x[i]); r2 = root(y[i]);
        if (r1 != r2){
            q[++num] = i; fa[r2] = r1;
        }
    }
    scanf("%d", &m);
    while (m--){
        scanf("%d%d", &l, &r);
        for (i = 1; i <= n; i++) fa[i] = i;
        for (i = 1; i <= num; i++)
        if (q[i] < l || q[i] > r){
            r1 = root(x[q[i]]); r2 = root(y[q[i]]);
            if (r1 != r2) fa[r2] = r1;
        }
        ans = 0;
        for (i = 1; i <= n; i++) if (fa[i] == i) ans++;
        printf("%d\n", ans);
    }

}