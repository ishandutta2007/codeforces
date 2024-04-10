#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


int n, m, a[1005][1005], v[1005][1005], q[1005], cnt, l, r, ans;


bool check(int l){
    memset(v, 0, sizeof(v));
    for (int i = 1; i <= n; i++){
        cnt = 0;
        for (int j = 1; j <= m; j++) if (a[i][j] >= l) q[++cnt] = j;
        for (int j = 1; j <= cnt; j++)
        for (int k = j + 1; k <= cnt; k++){
            if (v[q[j]][q[k]]) return 1;
            v[q[j]][q[k]] = 1;
        }
    }
    return 0;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++){
        scanf("%d", &a[i][j]);
        r = max(a[i][j], r);
    }
    while (l <= r){
        int mid = (l + r) / 2;
        if (check(mid)){
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    printf("%d\n", ans);
}