// Codeforces Beta Round #12
// Problem D -- Ball
#include <cstdio>
#include <climits>
#include <utility>
#include <algorithm>

#define maxN 500000

using namespace std;

int n, a[maxN], b[maxN], c[maxN], bt[maxN + 1];
pair<int, int> au[maxN];
pair<int, pair<int, int> > od[maxN];

void work(int *a)
{
    for(int i = 0; i != n; ++ i)
        au[i] = make_pair(a[i], i);
    sort(au, au + n);
    a[au[0].second] = 0;
    for(int i = 1; i != n; ++ i)
        a[au[i].second] = a[au[i - 1].second] + (au[i].first != au[i - 1].first);
}

void insert(int x, int a)
{
    for(int i = x; i <= n; i += i & -i)
        if(a > bt[i])
            bt[i] = a;
}

int getmax(int x)
{
    int t = INT_MIN;
    for(int i = x; i >= 1; i -= i & -i)
        if(bt[i] > t)
            t = bt[i];
    return t;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i != n; ++ i)
        scanf("%d", a + i);
    for(int i = 0; i != n; ++ i)
        scanf("%d", b + i);
    for(int i = 0; i != n; ++ i)
        scanf("%d", c + i);
    work(b);
    for(int i = 0; i != n; ++ i)
        od[i] = make_pair(-a[i], make_pair(b[i], c[i]));
    sort(od, od + n);
    for(int i = 0; i != n; ++ i)
        b[i] = od[i].second.first, c[i] = od[i].second.second;
    for(int i = 1; i <= n; ++ i)
        bt[i] = INT_MIN;
    int ct = 0;
    for(int i = 0; i != n; ++ i)
    {
        ct += getmax(n - b[i] - 1) > c[i];
        insert(n - b[i], c[i]);
    }
    printf("%d\n", ct);
    return 0;
}