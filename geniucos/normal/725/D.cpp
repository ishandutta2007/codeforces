#include<bits/stdc++.h>

using namespace std;

int lg, N, ans, aib2[300009], pos[300009];
long long T, INF = 1e18 + 1, aib[300009];
pair < long long, long long > v[300009];
pair < long long, int > h[300009];

void U (int pos, long long val)
{
    while (pos <= N)
    {
        if (aib[pos] >= INF - val) aib[pos] = INF;
        else aib[pos] += val;
        aib2[pos] ++;
        pos += (pos - (pos & (pos - 1)));
    }
}

int Query (long long budget)
{
    int pos = 0, ans = 0;
    for (int i=lg; i>=0; i--)
        if (pos + (1 << i) <= N && aib[pos + (1 << i)] <= budget)
            budget -= aib[pos + (1 << i)], ans += aib2[pos + (1 << i)], pos |= 1 << i;
    return ans;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), lg = 0;
while ((1 << (lg + 1)) <= N) lg ++;
long long irelevant;
scanf ("%I64d", &T), scanf ("%I64d", &irelevant), ans = 1, N --;
for (int i=1; i<=N; i++)
{
    scanf ("%I64d %I64d", &v[i].first, &v[i].second), v[i].second -= v[i].first, v[i].second ++;
    if (v[i].first > T) ans ++;
}
if (ans == 1)
{
    printf ("1\n");
    return 0;
}
sort (v + 1, v + N + 1), reverse (v + 1, v + N + 1);
for (int i=1; i<=N; i++)
    h[i] = make_pair (v[i].second, i);
sort (h + 1, h + N + 1);
for (int i=1; i<=N; i++)
    pos[h[i].second] = i;
for (int i=1; i<=N; i++)
{
    U (pos[i], v[i].second);
    if (v[i].first != v[i + 1].first)
    {
        long long curr = T - v[i + 1].first;
        if (curr >= 0)
        {
            int curr_P = i + 1 - Query (curr);
            if (curr_P < ans) ans = curr_P;
        }
    }
}
printf ("%d\n", ans);
return 0;
}