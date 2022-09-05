#include<bits/stdc++.h>

using namespace std;

int N, M, lgt[100009], k[100009];
char s[100009];

int nodes = 1, nxt[200009][26], pi[200009], id[200009], lastNonZero[200009], cc[200009];
char currS[100009];
void addString (int label)
{
    int l = strlen (currS + 1), q = 1; lgt[label] = l;
    for (int i=1; i<=l; i++)
    {
        char c = currS[i] - 'a';
        if (nxt[q][c] == 0) nxt[q][c] = ++nodes;
        q = nxt[q][c];
    }
    id[q] = label;
}

void buildAho ()
{
    int nr = 1;
    cc[1] = 1, pi[1] = 1, lastNonZero[1] = 1;
    for (int i=1; i<=nr; i++)
        for (int j=0; j<26; j++)
            if (nxt[cc[i]][j] != 0)
            {
                cc[++nr] = nxt[cc[i]][j];
                if (i == 1) pi[cc[nr]] = 1;
                else
                {
                    int k = pi[cc[i]];
                    while (k != 1 && nxt[k][j] == 0) k = pi[k];
                    if (nxt[k][j] != 0) k = nxt[k][j];
                    pi[cc[nr]] = k;
                }
                if (id[pi[cc[nr]]] != 0)
                    lastNonZero[cc[nr]] = pi[cc[nr]];
                else
                    lastNonZero[cc[nr]] = lastNonZero[pi[cc[nr]]];
            }
}
vector < int > appearance[100009];

void computeAppearances ()
{
    int k = 1;
    for (int i=1; i<=N; i++)
    {
        char c = s[i] - 'a';
        while (k != 1 && nxt[k][c] == 0) k = pi[k];
        if (nxt[k][c] != 0) k = nxt[k][c];
        int aux = k;
        while (aux != 1)
        {
            if (id[aux] > 0) appearance[id[aux]].push_back (i);
            aux = lastNonZero[aux];
        }
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%s", s + 1), N = strlen (s + 1);
scanf ("%d\n", &M);
for (int i=1; i<=M; i++)
{
    scanf ("%d %s\n", &k[i], currS + 1);
    addString (i);
}
buildAho ();
computeAppearances ();
for (int i=1; i<=M; i++)
{
    if (appearance[i].size () < k[i]) printf ("-1\n");
    else
    {
        int mini = N + 1;
        for (int j=k[i] - 1; j<appearance[i].size (); j++)
        {
            int d = appearance[i][j] - appearance[i][j + 1 - k[i]];
            if (d < mini)
                mini = d;
        }
        printf ("%d\n", mini + lgt[i]);
    }
}
return 0;
}