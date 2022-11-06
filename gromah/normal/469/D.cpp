#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000000 + 5

int n, a, b, f, A[N], B[N], Ord[N];
bool Vis[N];

inline bool cmp(int u, int v)
{
    return A[u] < A[v];
}

inline int find(int l, int r, int x)
{
    if (l > r) return 0;
    int mid = l + r >> 1;
    if (A[Ord[mid]] == x) return Vis[Ord[mid]] == 1 ? 0 : mid;
    else if (A[Ord[mid]] > x) return find(l, mid - 1, x);
    else return find(mid + 1, r, x);
}

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", A + i);
        Ord[i] = i;
    }
    sort(Ord + 1, Ord + n + 1, cmp);
    if (a > b)
        swap(a, b), f = 1;
    if (A[Ord[n]] >= b)
    {
        puts("NO");
        return 0;
    }
    for (int i = n; i; i --)
    {
        if (Vis[Ord[i]]) continue ;
        int _a = 0, _b = 0;
        if (a > A[Ord[i]])
            _a = find(1, n, a - A[Ord[i]]);
        if (_a) B[Ord[_a]] = B[Ord[i]] = f, Vis[Ord[_a]] = Vis[Ord[i]] = 1;
        else
        {
            _b = find(1, n, b - A[Ord[i]]);
            if (_b) B[Ord[_b]] = B[Ord[i]] = f ^ 1, Vis[Ord[_b]] = Vis[Ord[i]] = 1;
            else
            {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    for (int i = 1; i <= n; i ++)
        printf("%d%c", B[i], i == n ? '\n' : ' ');
    return 0;
}