#include<bits/stdc++.h>

using namespace std;

int N, M, ap[100009], partialXor[100009];
vector < pair < int, int > > edge[100009];

int nr, v[30];
void addVal (int val)
{
    for (int i=nr; i>=1; i--)
        val = min (val, val ^ v[i]);
    if (val == 0) return ;
    v[++nr] = val + 1;
    for (int i=1; i<=nr; i++)
        if (val < v[i])
        {
            for (int j=nr; j>=i + 1; j--)
                v[j] = v[j - 1];
            v[i] = val;
            break;
        }
}

void dfs (int nod, int tata)
{
    ap[nod] = 1;
    bool alreadySkipped = 0;
    for (auto it : edge[nod])
    {
        if (it.first == tata && alreadySkipped == 0)
        {
            alreadySkipped = 1;
            continue;
        }
        if (ap[it.first] != 0)
        {
            if (ap[it.first] == 1)
                addVal (partialXor[it.first] ^ partialXor[nod] ^ it.second);
            continue;
        }
        partialXor[it.first] = partialXor[nod] ^ it.second;
        dfs (it.first, nod);
    }
    ap[nod] = -1;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
while (M --)
{
    int x, y, d;
    scanf ("%d %d %d", &x, &y, &d);
    edge[x].push_back ({y, d});
    edge[y].push_back ({x, d});
}
dfs (1, -1);
int ans = partialXor[N];
for (int i=nr; i>=1; i--)
    ans = min (ans, ans ^ v[i]);
printf ("%d\n", ans);
return 0;
}