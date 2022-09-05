#include<bits/stdc++.h>

using namespace std;

int N, T, ans[309];
const bool DBG = 0;
int hiddenString[309], aux[309], queryCount = 0;
const int maxQueryCount = 10000;

void init ()
{
    scanf ("%d %d", &N, &T);
    if (DBG)
    {
        srand (time (0));
        for (int i=1; i<=N; i++)
            hiddenString[i] = (i <= T);
        random_shuffle (hiddenString + 1, hiddenString + N + 1);
/*        for (int i=1; i<=N; i++)
            hiddenString[i] = i % 2;*/
        for (int i=1; i<=N; i++)
            aux[i] = hiddenString[i];
    }
}

int ask (int l, int r)
{
    queryCount ++;
    if (DBG)
    {
        int which = rand () & 1;
        if (which == 0) l = 1;
        else r = N;
        for (int i=l; i<=r; i++)
            aux[i] ^= 1;
        int ans = 0;
        for (int i=1; i<=N; i++)
            ans += aux[i];
        return ans;
    }
    printf ("? %d %d\n", l, r);
    fflush (stdout);
    int ans;
    scanf ("%d", &ans);
    if (ans == -1)
        assert (0);
    return ans;
}

void finish ()
{
    if (DBG)
    {
        for (int i=1; i<=N; i++)
            if (ans[i] != hiddenString[i])
            {
                printf ("WA\n");
                for (int j=1; j<=N; j++)
                    printf ("%d", ans[j]);
                printf ("\n");
                for (int j=1; j<=N; j++)
                    printf ("%d", hiddenString[j]);
                printf ("\n");
                exit (0);
            }
        printf ("OK %d\n", queryCount);
        for (int j=1; j<=N; j++)
            printf ("%d", ans[j]);
        printf ("\n");
        exit (0);
    }
    printf ("! ");
    for (int i=1; i<=N; i++)
        printf ("%d", ans[i]);
    printf ("\n");
    fflush (stdout);
    exit (0);
}

void solve ()
{
    int steps = maxQueryCount / N;
    if (steps % 2 == 1)
        steps --;
    int A = T, B = 0;
    bool xoredSuffix = 0;
    for (int i=N - 1; i>=1; i--)
    {
        int currAns = -1, oldValue = A + B, Y = N - i - 1;
        map < int, int > mp;
        mp[oldValue] = 1;
        for (int j=1; j<=steps; j++)
        {
            currAns = ask (1, i);
            if (j % 2 == 0)
            {
                mp[currAns] ++;
                if (mp.size () == 2)
                    break;
            }
        }
        int xoredValue = 0;
        if (mp.size () == 1) xoredValue = mp.begin () -> first;
        else
        {
            auto it = mp.begin ();
            if (it->first == oldValue) it ++;
            xoredValue = it->first;
        }
        int x1mx = xoredValue - (A + Y - B);
        if (x1mx == -1) ans[i + 1] = 1;
        else ans[i + 1] = 0;

        A -= ans[i + 1], B = currAns - A;
    }
    ans[1] = T;
    for (int i=2; i<=N; i++)
        ans[1] -= ans[i];
    finish ();
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

init ();
solve ();

return 0;
}