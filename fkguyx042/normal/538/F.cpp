#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
using namespace std;
 
#define maxn 200500
#define maxc maxn*20
 
int n;
int a[maxn], b[maxn];
int res[maxn];
int root[maxn];
int nsize;
 
int lc[maxc], rc[maxc];
int sum[maxc];
int tot;
 
int insert(int rt, int L, int R, int v)
{
    int cur = tot++;
    if (L == R){
        sum[cur] = sum[rt] + 1;
        return cur;
    }
    int M = (L + R) >> 1;
    if (v <= M){
        rc[cur] = rc[rt];
        lc[cur] = insert(lc[rt], L, M, v);
    }
    else{
        lc[cur] = lc[rt];
        rc[cur] = insert(rc[rt], M + 1, R, v);
    }
    sum[cur] = sum[lc[cur]] + sum[rc[cur]];
    return cur;
}
 
 
int query(int rt, int L, int R, int l, int r)
{
    if (l == L&&r == R){
        return sum[rt];
    }
    int M = (L + R) >> 1;
    if (r <= M){
        return query(lc[rt], L, M, l, r);
    }
    else if (l>M){
        return query(rc[rt], M + 1, R, l, r);
    }
    else{
        return query(lc[rt], L, M, l, M) + query(rc[rt], M + 1, R, M + 1, r);
    }
}
 
 
int main()
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            b[i] = a[i];
        }
        sort(b+1, b + n+1);
        nsize = unique(b+1, b + n+1) - b;
        for (int i = 1; i <= n; ++i){
            a[i] = lower_bound(b + 1, b + nsize, a[i]) - b + 1;
        }
        memset(res, 0, sizeof(res));
        tot = 1;
        root[n + 1] = tot;
        lc[tot] = rc[tot] = sum[tot] = 0;
        tot++;
        for (int i = n; i >= 1; i--){
            root[i] = insert(root[i + 1], 1, nsize, a[i]);
        }
        for (int k = 1; k <= n - 1; ++k){
            int maxBound = (n + k - 2) / k;
            for (int v = 1; v <= maxBound; ++v){
                int cnt = 0;
                int lbound = k*(v - 1) + 2;
                int rbound = min(k*v + 1, n);
                cnt = query(root[lbound], 1, nsize, 1, a[v] - 1)- query(root[rbound+1], 1, nsize, 1, a[v] - 1);
                res[k] += cnt;
            }
        }
        for (int i = 1; i <= n - 1; ++i){
            if (i > 1) printf(" ");
            printf("%d", res[i]);
        }
        puts("");
    }
    return 0;
}