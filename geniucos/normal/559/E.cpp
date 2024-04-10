#include<bits/stdc++.h>

using namespace std;

int N, M, Left[109][109][309], best[109][309];
vector < int > x;
pair < int, int > spotlight[109];

void read ()
{
    scanf ("%d", &N);
    for (int i=1; i<=N; i++)
        scanf ("%d %d", &spotlight[i].first, &spotlight[i].second),
        x.push_back (spotlight[i].first - spotlight[i].second),
        x.push_back (spotlight[i].first + spotlight[i].second),
        x.push_back (spotlight[i].first);
    sort (spotlight + 1, spotlight + N + 1);
    x.push_back (-1e9), sort (x.begin (), x.end ());
    x.erase (unique (x.begin (), x.end ()), x.end ()), M = x.size () - 1;
}

void buildLeft ()
{
    ///Left[l][r][j] is the minimum i so that all the segment x[i], x[j] can be illuminated using only spotlights [l, r]
    for (int r=1; r<=N; r++)
        for (int l=1; l<=r; l++)
            for (int j=1; j<=M; j++)
            {
                Left[l][r][j] = j;
                int pntr = j;
                for (int p=r; p>=l; p--)
                {
                    while (pntr > 1 && x[pntr - 1] >= spotlight[p].first)
                        pntr --;
                    if (spotlight[p].first + spotlight[p].second >= x[j])
                        Left[l][r][j] = min (Left[l][r][j], (l == p ? pntr : Left[l][p - 1][pntr]));
                    while (pntr > 1 && x[pntr - 1] >= spotlight[p].first - spotlight[p].second)
                        pntr --;
                    if (spotlight[p].first >= x[j])
                        Left[l][r][j] = min (Left[l][r][j], (l == p ? pntr : Left[l][p - 1][pntr]));
                }
            }
}

void buildBest ()
{
    ///best[R][i] the answer is we used the first R spotlights and the rightmost illuminated point is x[i]
    for (int R=1; R<=N; R++)
        for (int i=1; i<=M; i++)
            for (int L=1; L<=R; L++)
            {
                int j = Left[L][R][i], curr = x[i] - x[j];
                for (int k=1; k<j; k++)
                    if (best[L - 1][k] + x[i] - x[j] > curr)
                        curr = best[L - 1][k] + x[i] - x[j];
                if (curr > best[R][i])
                    best[R][i] = curr;
            }
}

void print ()
{
    int ans = 0;
    for (int i=1; i<=M; i++)
        if (best[N][i] > ans)
            ans = best[N][i];
    printf ("%d\n", ans);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

read ();
buildLeft ();
buildBest ();
print ();

return 0;
}