#include<bits/stdc++.h>

using namespace std;

int N, M, K, S, d[103][100009], aux[109], type[100009];
vector < int > v[100009], h[109];
queue < int > cc;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d %d", &N, &M, &K, &S);
for (int i=1; i<=N; i++)
{
    scanf ("%d", &type[i]), type[i] --;
    h[type[i]].push_back (i);
}
while (M --)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
for (int i=0; i<K; i++)
{
    for (int j=1; j<=N; j++)
        d[i][j] = -1;
    for (auto it : h[i])
        d[i][it] = 0, cc.push (it);
    while (!cc.empty ())
    {
        int nod = cc.front ();
        cc.pop ();
        for (auto it : v[nod])
            if (d[i][it] == -1)
                d[i][it] = d[i][nod] + 1, cc.push (it);
    }
}
for (int i=1; i<=N; i++)
{
    for (int j=0; j<K; j++)
        aux[j] = d[j][i];
    sort (aux, aux + K);
    long long curr = 0;
    for (int j=0; j<S; j++)
        curr += aux[j];
    printf ("%I64d ", curr);
}
printf ("\n");
return 0;
}