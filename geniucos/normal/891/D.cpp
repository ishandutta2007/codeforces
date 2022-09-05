#include<bits/stdc++.h>

using namespace std;

int N, t[500009], vol[500009];
vector < int > fii[500009], v[500009];

struct state
{
    int dp[2][2];
    ///0/1 already taken
    ///0/1 any skipped?
    state ()
    {
        dp[0][0] = dp[0][1] = 0;
        dp[1][0] = dp[1][1] = 0;
    }
    state (bool val)
    {
        if (val)
        {
            dp[0][0] = dp[1][1] = 1;
            dp[0][1] = dp[1][0] = 0;
        }
        else
        {
            dp[1][0] = 1;
            dp[0][0] = dp[0][1] = dp[1][1] = 0;
        }
    }
}down[500009], up[500009], prf[500009], suf[500009];

state addSon (state curr, state son)
{
    state nv;
    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
            for (int k=0; k<2; k++)
                for (int p=0; p<2; p++)
                {
                    if (j == 1 && p == 1) continue;
                    int ni, nj = j + p;
                    if (i == 1 && k == 1) ni = 1;
                    else
                    if (i == 0 && k == 0) ni = 1;
                    else
                    if (i == 1 && k == 0) continue;
                    else ni = 0;
                    nv.dp[ni][nj] += curr.dp[i][j] * son.dp[k][p];
//                    if (ni == 1 && nj == 1 && curr.dp[i][j] * son.dp[k][p] > 0)
  //                      printf ("%d %d %d %d (%d)\n", i, j, k, p, curr.dp[i][j] * son.dp[k][p]);
                }
    //printf ("\n");
    return nv;
}

state addBrother (state curr, state bro)
{
    state nv;
    nv.dp[0][0] = nv.dp[0][1] = nv.dp[1][0] = nv.dp[1][1] = 0;
    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
            for (int k=0; k<2; k++)
                for (int p=0; p<2; p++)
                {
                    if (i == 0 && k == 0) continue;
                    if (j == 1 && p == 1) continue;
                    nv.dp[min (i, k)][j + p] += curr.dp[i][j] * bro.dp[k][p];
                }
    return nv;
}

void doDown (int nod)
{
    down[nod] = state (1), vol[nod] = 1;
    for (auto it : v[nod])
        if (t[it] == 0)
            t[it] = nod, fii[nod].push_back (it), doDown (it), vol[nod] += vol[it], down[nod] = addSon (down[nod], down[it]);
}

void doUp (int nod)
{
    if (fii[nod].empty ()) return ;
    if (fii[nod].size () == 1)
    {
        int son = fii[nod][0];
        up[son] = addSon (state (1), up[nod]);
        doUp (son);
        return ;
    }
    for (int i=0; i<fii[nod].size (); i++)
    {
        if (i == 0) prf[i] = down[fii[nod][i]];
        else prf[i] = addBrother (prf[i - 1], down[fii[nod][i]]);
    }
    for (int i=fii[nod].size () - 1; i>=0; i--)
    {
        if (i == fii[nod].size () - 1) suf[i] = down[fii[nod][i]];
        else suf[i] = addBrother (suf[i + 1], down[fii[nod][i]]);
    }
    for (int i=0; i<fii[nod].size (); i++)
    {
        state curr;
        if (i == 0) curr = suf[i + 1];
        else
        if (i == fii[nod].size () - 1) curr = prf[i - 1];
        else curr = addBrother (prf[i - 1], suf[i + 1]);
        curr = addBrother (curr, up[nod]);
        up[fii[nod][i]] = addSon (state (1), curr);
    }
    for (auto it : fii[nod])
        doUp (it);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
if (N & 1)
{
    printf ("0\n");
    return 0;
}
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
t[1] = -1, doDown (1);
up[1] = state (0), doUp (1);
long long ans = 0;
for (int i=2; i<=N; i++)
{
    ans += 1LL * down[i].dp[1][1] * up[i].dp[1][1];
    if (down[i].dp[1][0] && up[i].dp[1][0])
        ans += 1LL * vol[i] * (N - vol[i]);
}
printf ("%I64d\n", ans);
return 0;
}