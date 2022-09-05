#include<bits/stdc++.h>

using namespace std;

int cnt, N, M;
char sir[200009], ans[200009];

int getCost (vector < int > a, vector < int > b)
{
    if (a.empty () || b.empty ())
        return 0;
    printf ("%d %d ", a.size (), b.size ());
    for (auto it : a)
        printf ("%d ", it);
    for (auto it : b)
        printf ("%d ", it);
    printf ("\n");
    fflush (stdout);
    int ans;
    scanf ("%d", &ans);
    return ans;
}

void giveAns (int ans)
{
    printf ("-1 %d\n", ans);
    fflush (stdout);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d", &N);
    if (N == 1) giveAns (0);
    else
    {
        int ans = 0;
        for (int bit = 0; (1 << bit) <= N; bit ++)
        {
            vector < int > a, b;
            for (int i=1; i<=N; i++)
                if (i & (1 << bit)) a.push_back (i);
                else b.push_back (i);
            int curr = getCost (a, b);
            if (curr > ans)
                ans = curr;
        }
        giveAns (ans);
    }
}
return 0;
}