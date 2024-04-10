#include<bits/stdc++.h>

using namespace std;

int start, X, N, v[50009], nxt[50009], p[50009];
const int Konst = 1200, DBG = 0;
pair < int, int > h[50009];

int realAns, queries = 0, realV[50009], realNxt[50009];
pair < int, int > realH[50009];

void ask (int i)
{
    if (nxt[i] != 0) return ;
    if (DBG)
    {
        v[i] = realV[i], nxt[i] = realNxt[i];
        queries ++;
        return ;
    }
    printf ("? %d\n", i);
    fflush (stdout);
    scanf ("%d %d", &v[i], &nxt[i]);
}

void finish (int ans)
{
    printf ("! %d\n", ans);
    if (DBG)
        printf ("instead of %d with %d\n", realAns, queries);
    fflush (stdout);
    exit (0);
}

int rand15 () {return rand () & 32767;}
int Rand () {return (rand15 () << 15) + rand15 ();}

void chooseK ()
{
    int sz = 1;
    p[1] = start;
    for (int i=1; i<=N; i++)
        if (i != start)
            p[++sz] = i;
    random_shuffle (p + 2, p + N + 1);
/*    for (int i=1; i<=N; i++)
        printf ("%d%c", p[i], " \n"[i == N]);*/
}

void Search (int bg, int nd)
{
    while (bg != nd)
    {
        ask (bg);
        if (v[bg] > X) finish (v[bg]);
        bg = nxt[bg];
    }
    if (nd == -1)
        finish (-1);
    else finish (v[nd]);
}

void play ()
{
    scanf ("%d", &N);
    for (int i=1; i<=N; i++)
        realV[i] = i;
    random_shuffle (realV + 1, realV + N + 1);
    for (int i=1; i<=N; i++)
        realH[i] = {realV[i], i};
    sort (realH + 1, realH + N + 1);
    start = realH[1].second;
    X = 1;//X = Rand () % N + 1;
    X --;
    for (int i=1; i<N; i++)
        realNxt[realH[i].second] = realH[i + 1].second;
    realNxt[realH[N].second] = -1;
    realAns = -1;
    for (int i=1; i<=N; i++)
        if (realH[i].first > X)
        {
            realAns = realH[i].first;
            break;
        }
/*    printf ("inp:\n----------------------\n");
    printf ("%d %d %d\n", N, start, X);
    for (int i=1; i<=N; i++)
        printf ("%d %d\n", realV[i], realNxt[i]);
    printf ("--------------------------\n");*/
}

int main ()
{
srand (time (0));
if (!DBG) scanf ("%d %d %d", &N, &start, &X), X --;
else play ();
if (N <= Konst + 1)
{
    for (int i=start; i != -1; i = nxt[i])
    {
        ask (i);
        if (v[i] > X) finish (v[i]);
    }
    finish (-1);
}
chooseK ();
for (int i=1; i<=Konst; i++)
    ask (p[i]);
for (int i=1; i<=Konst; i++)
    h[i] = {v[p[i]], p[i]};
sort (h + 1, h + Konst + 1);
h[Konst + 1] = {X + 2, -1};
for (int i=1; i<=Konst + 1; i++)
    if (h[i].first > X)
    {
        if (i == 1) finish (h[1].first);
        else Search (h[i - 1].second, h[i].second);
    }
finish (-1);
return 0;
}