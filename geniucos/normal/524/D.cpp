#include<bits/stdc++.h>

using namespace std;

int cnt, N, M, T, R, ans[20009], a[20009], ap[20009];
bool achieved_target;
deque < int > dq;

int val (char c1, char c2) {return (c1 - 48) * 10 + c2 - 48;}
int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d\n", &N, &M, &T);
for (int i=1; i<=N; i++)
{
    char h1, h2, m1, m2, s1, s2;
    scanf ("%c%c:%c%c:%c%c\n", &h1, &h2, &m1, &m2, &s1, &s2);
    int x = val (h1, h2), y = val (m1, m2), z = val (s1, s2);
    a[i] = x * 3600 + y * 60 + z;
}
int i = 1, j = 0;
for (int t = T - 1; t<86400; t++)
{
    while (a[i] <= t - T && i <= N)
    {
        ap[ans[i]] --;
        if (ap[ans[i]] == 0) cnt --;
        i ++;
    }
    if (i > N || a[i] > t)
    {
        j = i - 1;
        continue;
    }
    int k = j;
    while (a[k] <= t && k <= N) k ++;
    k --; ///[j + 1, k]
    if (k > j)
    {
        while (j < k)
        {
            j ++;
            if (cnt < M) ans[j] = ++R, ap[R] ++, cnt ++;
            else ans[j] = ans[j - 1], ap[ans[j]] ++;
        }
        if (cnt == M) achieved_target = 1;
    }
}
if (!achieved_target)
{
    printf ("No solution\n");
    return 0;
}
printf ("%d\n", R);
for (int i=1; i<=N; i++)
    printf ("%d\n", ans[i]);
return 0;
}