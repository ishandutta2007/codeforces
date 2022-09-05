#include<bits/stdc++.h>

using namespace std;

int C, N, ap[200009], lst[200009], a[200009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n%d", &C, &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), ap[a[i]] ++;
sort (a + 1, a + N + 1);
int j = C;
for (int i=N; i>=1; i--)
    while (j >= a[i]) lst[j] = i, j --;
for (int K = 1; K <= C; K ++)
{
    int curr = C, i = N + 1;
    bool luat = 0;
    while (curr)
    {
        int j = lst[curr];
        if (j >= i) j = i - 1;
        if (j == 0)
        {
            if (K <= curr && luat == 0) curr -= K;
            break;
        }
        if (a[j] <= K && K <= curr && luat == 0)
        {
            curr -= K, luat = 1;
            continue;
        }
        int k = min (ap[a[j]], curr / a[j]);
        curr -= k * a[j], j = j - k + 1;
        i = j;
    }
    if (curr != 0)
    {
        printf ("%d\n", K);
        return 0;
    }
}
printf ("Greed is good\n");
return 0;
}