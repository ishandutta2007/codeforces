#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e5 + 1;
int n, ans, sig;
int a[N];
int f[N * 4], to[N];
int find(int l, int r, int s ,int ll, int rr)
{
    if (rr <l || r < ll) return 0;
    if (ll <= l && r <= rr) return f[s];
    return max(find(l, (l + r) / 2, s + s, ll, rr), find((l + r) / 2 + 1, r, s + s + 1, ll, rr));
}
void work(int l, int r)
{
    if (l >= r) return;
    int s = find(1, n ,1, l, r);
    int wz = to[s];
    if (wz <= (l + r) / 2)
    {
        for (int i = l ; i < wz ; i ++)
            if (to[s - a[i]] <= r && to[s - a[i]] > wz)
                ans ++;
    } else {
        for (int i = wz + 1 ; i <= r ; i ++)
            if (to[s - a[i]] < wz && to[s - a[i]] >= l)
                ans ++;
    }
    work(l, wz -1);
    work(wz + 1, r);
}
void build(int l, int r, int s)
{
    if (l == r)
    {
        f[s] = a[l];
        return;
    }
    build(l, (l + r) / 2, s + s);
    build((l + r) / 2 + 1, r, s + s + 1);
    f[s] = max(f[s + s], f[s + s + 1]);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++)
        scanf("%d", &a[i]), to[a[i]] = i;
    build(1, n, 1);
    work(1, n);
    printf("%d\n", ans);
    return 0;
}