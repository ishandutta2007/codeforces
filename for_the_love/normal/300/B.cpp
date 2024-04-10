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
int n, m, x, y, i, j, k, ans[100][10], used[100], a[100], tot, fa[100], c[100], b[100], found, cnt;
vector <int> v[100];
int root(int x){if (fa[x] != x) fa[x] = root(fa[x]); return fa[x];}

int main(){
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) fa[i] = i;
    for (i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        x = root(x);
        y = root(y);
        if (x != y) fa[x] = y;
    }

    for (i = 1; i <= n; i++){
        fa[i] = root(i);
        v[fa[i]].push_back(i);
        if (!c[fa[i]]) a[++cnt] = fa[i];
        c[fa[i]]++;
        if (c[fa[i]] > 3){
            puts("-1");
            return 0;
        }
    }

    for (i = 1; i <= n / 3; i++){
        for (j = 1; j <= cnt; j++)
        if (!used[a[j]] && c[a[j]] == 3){
            used[a[j]] = 1;
            for (k = 0; k < v[a[j]].size(); k++)
                ans[i][k + 1] = v[a[j]][k];
            tot++;
            break;
        }else if (!used[a[j]] && c[a[j]] == 2){
            used[a[j]] = 1;
            found = 0;
            for (k = 1; k <= cnt; k++)
            if (!used[a[k]] && c[a[k]] == 1){
                found = 1;
                used[a[k]] = 1;
                break;
            }
            if (!found){
                puts("-1");
                return 0;
            }
            ans[i][1] = v[a[j]][0]; ans[i][2] = v[a[j]][1]; ans[i][3] = v[a[k]][0];
            tot++;
            break;
        }
    }
    for (j = 1; j <= cnt; j++)
    for (k = 1; k <= cnt; k++)
    for (x = 1; x <= cnt; x++)
    if (!used[a[j]] && !used[a[k]] && !used[a[x]] && j != k && k != x && j != x){
        used[a[j]] = used[a[k]] = used[a[x]] = 1;
        ans[++tot][1] = a[j]; ans[tot][2] = a[k]; ans[tot][3] = a[x];
    }
    for (i = 1; i <= n / 3; i++) printf("%d %d %d\n", ans[i][1], ans[i][2], ans[i][3]);
}