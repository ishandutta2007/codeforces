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
struct Node{
    long long d[5];
} ans[1000005];
int n, i, j, a[15], b[15], cnt, tot, v[15];
long long d[15];
int cmp(Node a, Node b){
    for (int i = 1; i <= 4; i++)
    if (a.d[i] < b.d[i]) return 1;
    else if (a.d[i] > b.d[i]) return 0;
}

void dfs2(int k, int last, int n){
    int i;
    if (last > n) return;
    if (k == 4){
        if (n > last && b[last] == 0) return;
        d[k] = 0;
        for (i = last; i <= n; i++) d[k] = d[k] * 10 + b[i];
        if (d[k] > 255) return;
        cnt++;
        for (i = 1; i <= 4; i++) ans[cnt].d[i] = d[i];
        return;
    }
    for (i = last; i <= n; i++){
        if (i > last && b[last] == 0) continue;
        d[k] = 0;
        for (int j = last; j <= i; j++) d[k] = d[k] * 10 + b[j];
        if (d[k] > 255) continue;
        dfs2(k + 1, i + 1, n);
    }
}
void dfs(int k, int limit){
    int i, j;
    if (k > limit){
        if (tot == n){
            for (j = 1; j <= limit; j++) b[limit * 2 - j + 1] = b[j];
            dfs2(1, 1, limit * 2);
            for (j = 1; j <= limit; j++) b[limit * 2 - j] = b[j];
            dfs2(1, 1, limit * 2 - 1);
        }
        return;
    }
    for (i = 1; i <= n; i++){
        if (!v[i]) tot++;
        v[i]++;
        b[k] = a[i];
        dfs(k + 1, limit);
        v[i]--;
        if (!v[i]) tot--;
    }
}

int main(){
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = max(2, n); i <= 6; i++) dfs(1, i);
    sort(ans + 1, ans + cnt + 1, cmp);
    printf("%d\n", cnt);
    for (i = 1; i <= cnt; i++){
        for (j = 1; j <= 3; j++) printf("%d.", ans[i].d[j]); printf("%d\n", ans[i].d[j]);
    }

}