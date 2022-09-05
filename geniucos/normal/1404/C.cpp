#include<bits/stdc++.h>

using namespace std;

const int maxN = 300009, maxM = maxN;
int N, M, a[maxN], need[maxN], aib[maxN], ans[maxM];
vector < pair < int, int > > queries[maxN];
vector < int > updates[maxN];

void update (int pos, int val)
{
    while (pos <= N)
        aib[pos] += val,
        pos += pos - (pos & (pos - 1));
}

int query (int pos)
{
    if (pos <= 0)
        return 0;
    int sum = 0;
    while (pos)
        sum += aib[pos],
        pos &= pos - 1;
    return sum;
}

int query (int l, int r)
{
    return query (r) - query (l - 1);
}

void clearAib ()
{
    for (int i=0; i<=N; i++)
        aib[i] = 0;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), a[i] = i - a[i];
/*for (int i=1; i<=N; i++)
    printf ("%2d ", a[i]);
printf ("\n");*/
int cnt0 = 0, lg = 0;
while ((2 << lg) <= N) lg ++;
for (int i=1; i<=N; i++)
{
    if (a[i] < 0)
        need[i] = 0, cnt0 ++;
    else
    {
        int maxF = i - 1 - a[i] - cnt0;
        if (maxF < 0)
            need[i] = 0;
        else
        {
            ///want biggest pos s.t. sum to pos <= maxF
            int pos = 0;
            for (int j=lg; j>=0; j--)
                if (pos + (1 << j) <= N && aib[pos + (1 << j)] <= maxF)
                    pos |= 1 << j, maxF -= aib[pos];
            need[i] = min (i, pos + 1);
        }
        if (need[i] == 0) cnt0 ++;
        else update (need[i], +1);
    }
}
/*for (int i=1; i<=N; i++)
    printf ("%2d ", need[i]);
printf ("\n");*/
for (int i=1; i<=M; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y), x ++, y = N - y;
    queries[x].push_back ({y, i});
    /*int ans = 0;
    for (int j=x; j<=y; j++)
        ans += (need[j] >= x);
    printf ("%d\n", ans);*/
}
clearAib ();
for (int i=1; i<=N; i++)
    updates[need[i]].push_back(i);
for (int i=N; i>=1; i--)
{
    for (auto j : updates[i])
        update (j, +1);
    for (auto j : queries[i])
        ans[j.second] = query (i, j.first);
}
for (int i=1; i<=M; i++)
    printf ("%d\n", ans[i]);
return 0;
}