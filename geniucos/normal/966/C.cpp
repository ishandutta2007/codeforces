#include<bits/stdc++.h>

using namespace std;

int N, nr, cnt[109];
long long ans[100009], old[100009], b[100009];
vector < long long > v[109];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    scanf ("%I64d", &b[i]);
    int currPos = -1;
    for (int j=60; j>=0; j--)
        if (b[i] & (1LL << j))
        {
            currPos = j;
            break;
        }
    v[currPos].push_back (b[i]);
}
nr = 0;
for (int i=60; i>=0; i--)
if (!v[i].empty ())
{
    if (cnt[i] + 1 < v[i].size ())
    {
        printf ("No\n");
        return 0;
    }
    memcpy (old, ans, sizeof (old));
    int oldNr = nr, pos = 0;
    nr = 0;
    for (auto j : v[i])
    {
        if (nr != 0)
        {
//            bool ok = 0;
            while (1)
            {
                pos ++;
                ans[++nr] = old[pos];
                if (old[pos] & (1LL << i))
                    break;
            }
            /*if (!ok)
            {
                printf ("No\n");
                assert (0);
            }*/
        }
        ans[++nr] = j;
    }
    for (int j=pos + 1; j<=oldNr; j++)
        ans[++nr] = old[j];
    for (auto j : v[i])
    {
        for (int k=0; k<60; k++)
            if (j & (1LL << k))
                cnt[k] ++;
    }
}
printf ("Yes\n");
for (int i=1; i<=nr; i++)
    printf ("%I64d ", ans[i]);
printf ("\n");
/*long long curr = 0;
for (int i=1; i<=nr; i++)
{
    long long oldCurr = curr;
    curr ^= ans[i];
    if (oldCurr >= curr)
    {
        printf ("fuck\n");
        return 0;
    }
}*/
return 0;
}