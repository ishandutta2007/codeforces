#include<bits/stdc++.h>

using namespace std;

int nr, N, v[70009][50];
int nxt[3200009][10], cnt[3200009], sz[3200009], ap[3200009], fath[3200009];
char sir[70009][11];

char getVal (int fath, int son)
{
    for (int i=0; i<10; i++)
        if (nxt[fath][i] == son)
            return i + '0';
    return '0';
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N), nr = 1;
for (int i=1; i<=N; i++)
{
    gets (sir[i] + 1);
    for (int j=1; j<=9; j++)
        sir[i][j] -= '0';
    for (int j=1; j<=9; j++)
    {
        int q = 1;
        for (int k=j; k<=9; k++)
        {
            cnt[q] ++;
            if (nxt[q][sir[i][k]] == 0)
                nxt[q][sir[i][k]] = ++nr, fath[nr] = q, sz[nr] = sz[q] + 1;
            q = nxt[q][sir[i][k]];
            v[i][++v[i][0]] = q;
        }
        cnt[q] ++;
    }
}
for (int i=1; i<=N; i++)
{
    gets (sir[i] + 1);
    for (int j=1; j<=v[i][0]; j++)
        ap[v[i][j]] ++;
    int ans = 10, how = -1;
    for (int j=1; j<=v[i][0]; j++)
        if (ap[v[i][j]] == cnt[v[i][j]] && sz[v[i][j]] < ans)
            ans = sz[v[i][j]], how = v[i][j];
    string s;
    while (how != 1)
        s.push_back (getVal (fath[how], how)), how = fath[how];
    reverse (s.begin (), s.end ());
    printf ("%s\n", s.c_str ());
    for (int j=1; j<=v[i][0]; j++)
        ap[v[i][j]] = 0;
}

return 0;
}