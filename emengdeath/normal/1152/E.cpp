#include <cstdio>
#include <unordered_map>
#include <algorithm>
#include <map>
using namespace std;
int g[300001], a[300001 * 2][2];
int v[300001];
int n, cnt;
int A[300001], B[300001], du[300001];
unordered_map<int, int>f;
int ans[300001];
void add(int x, int y)
{
    static int sum = 1;
    a[++sum][0] = y, a[sum][1] = g[x], g[x] = sum;
    a[++sum][0] = x, a[sum][1] = g[y], g[y] = sum;
    du[x] ++;
    du[y] ++;
}
void dfs(int x)
{
    for (int i = g[x]; i ;g[x] = i = a[i][1])
        if (a[i][0])
        {
            int y = a[i][0];
            a[i][0] = a[i ^ 1][0] = 0;
            g[x] = i;
            dfs(y);
            if (i > g[x]) i = g[x];
        }

    ans[++ans[0]] = v[x];
}
int main()
{
    scanf("%d", &n);
    for (int i = 1 ; i < n ;  i++) {
        scanf("%d", &A[i]);
        if (!f[A[i]])v[f[A[i]] = ++cnt] = A[i];
    }
    for (int i = 1 ; i < n ;  i++) {
        scanf("%d", &B[i]);
        if (!f[B[i]])v[f[B[i]] = ++cnt] = B[i];
    }
    for (int i = 1; i < n ; i ++)
    {
        if (A[i] > B[i])
        {
            printf("-1");
            return 0;
        }
       // if (A[i] != B[i] )
        add(f[B[i]], f[A[i]]);
    }
   /* for (int i = 1; i < n ; i ++)
        if (A[i] == B[i])
            add(f[B[i]], f[A[i]]);*/
    int s = 1;
    int tot = 0;
    for (int i = 1; i <= cnt ; i ++ )
        if (du[i] & 1)
        {
            s = i;
            tot ++;
        }
    if (tot == 1 || tot > 2)
    {
        printf("-1");
        return 0;
    }
    dfs(s);
    if (ans[0] != n)
    {
        printf("-1");
    }else {
        printf("%d", ans[1]);
        for (int i = 2; i <= ans[0]; i ++)
            printf(" %d", ans[i]);
    }
    return 0;
}