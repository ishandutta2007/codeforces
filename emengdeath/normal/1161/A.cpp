#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include <cstdio>
using namespace std;
const int N = 1e5 + 1;
struct node{
    int x, wz;
}q[N];
int a[N];
bool bz[N], bzr[N][2], bzl[N][2];
int sum[N];
int n, k;
long long ans;
bool cmp(const node &a,const node & b)
{
    return a.wz > b.wz;
}
int main(){
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k ;  i++) {
        scanf("%d", &a[i]);
        bz[a[i]] = 1;
        if  (!q[a[i]].wz) q[a[i]].wz = i;
        sum[a[i]] ++;
    }
    for (int i = 1; i <= n ; i ++) {
        if (!bz[i]) {
            if (i == 1 || i == n)
                ans += 2;
            else
                ans += 3;

        }
        bz[i] = 0;
    }
    for (int i =1; i <= n ; i++)
        q[i].x = i;
    sort(q + 1, q + n + 1, cmp);
    int r = k + 1;
    for (int i = 1; i <= n ; i ++)
    {
        if (!q[i].wz) continue;
        while (r > q[i].wz + 1)
        {
            r --;
            bz[a[r]] = 1;
        }
        if (q[i].x < n && !bz[q[i].x + 1]) {
            bzr[q[i].x][1] = 1;
        }
        if (q[i].x > 1 && !bz[q[i].x - 1])
            bzr[q[i].x][0] = 1;
    }
    for (int i = 1; i <= n ; i ++) {
        bz[i] = 0;
    }
    int  l = 0;
    for (int i = n  ; i >= 1; i --)
    {
        if (!q[i].wz) continue;
        while (l < q[i].wz - 1)
        {
            l ++;
            bz[a[l]] = 1;
        }
        if (q[i].x < n && !bz[q[i].x + 1])
            bzl[q[i].x][1] = 1;
        if (q[i].x > 1 && !bz[q[i].x - 1])
            bzl[q[i].x][0] = 1;
    }
    for (int i = 1; i <= n ; i++)
        for (int j = 0; j < 2; j ++)
            ans += bzr[i][j];
    printf("%d\n", ans);
    return 0;
}