#include<bits/stdc++.h>

using namespace std;

int mxlv, nr, N, ans[300009], su[300009], lv[300009], cnt[300009], vol[300009], P[300009], nxt[600009][26];
vector < pair < int, int > > moves;

void df2 (int whereToAdd, int nod)
{
    for (int i=0; i<26; i++)
        if (nxt[nod][i] != 0)
        {
            if (nxt[whereToAdd][i] == 0)
            {
                nxt[whereToAdd][i] = ++ nr;
                moves.push_back (make_pair (whereToAdd, i));
            }
            df2 (nxt[whereToAdd][i], nxt[nod][i]);
        }
}

void dfs (int nod)
{
    P[nod] = -1, vol[nod] = 1;
    for (int i=0; i<26; i++)
    if (nxt[nod][i])
    {
        lv[nxt[nod][i]] = lv[nod] + 1, dfs (nxt[nod][i]), vol[nod] += vol[nxt[nod][i]];
        if (P[nod] == -1 || vol[nxt[nod][i]] > vol[P[nod]]) P[nod] = nxt[nod][i];
    }
    if (P[nod] == -1)
    {
        cnt[nod] = 1;
        return ;
    }
    ///tre sa adaug la P
    moves.clear (), nr = N;
    for (int i=0; i<26; i++)
        if (nxt[nod][i] != P[nod] && nxt[nod][i] != 0)
            df2 (P[nod], nxt[nod][i]);
    cnt[nod] = vol[P[nod]] + nr - N;
    for (auto it = moves.begin (); it != moves.end (); it ++)
        nxt[it->first][it->second] = 0;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=2; i<=N; i++)
{
    int x, y;
    char c;
    scanf ("%d %d %c", &x, &y, &c), c -= 'a';
    nxt[x][c] = y;
}
dfs (1);
/*for (int i=1; i<=N; i++)
    printf ("%d\n", cnt[i]);
printf ("\n");*/
for (int i=1; i<=N; i++)
{
    su[lv[i]] ++, ans[lv[i] + 1] += cnt[i];
    if (lv[i] > mxlv) mxlv = lv[i];
}
int curr = 0;
for (int i=1; i<=mxlv + 1; i++)
{
    ///curr mai mici strict ca i - 1 + suma de cnt de alea cu i - 1
    ans[i] += curr;
    curr += su[i - 1];
}
/*for (int i=1; i<=mxlv; i++)
    printf ("%d\n", ans[i]);*/
int mini, how;
for (int i=1; i<=mxlv; i++)
    if (ans[i] < mini || i == 1) mini = ans[i], how = i;
printf ("%d\n%d\n", mini, how);
return 0;
}