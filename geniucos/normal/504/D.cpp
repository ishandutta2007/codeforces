#include<bits/stdc++.h>

using namespace std;

int N, fxd[2017];
bitset < 2017 > val[2017], how[2017];

const int base = 1000, baseLength = 3;
const int p2 = 1023, lp2 = 10, maxL = 2000;
void read (int id)
{
    char sir[609];
    int v[600], h[600], l;
    gets (sir + 1), l = strlen (sir + 1), h[0] = v[0] = 0;
    for (int i=l; i>=1; i-=baseLength)
    {
        v[++v[0]] = 0;
        int p = 1;
        for (int j=i; j>=1 && j>i - baseLength; j--)
            v[v[0]] += p * (sir[j] - '0'), p *= 10;
    }
    while (v[0] > 0)
    {
        h[++h[0]] = 0;
        for (int i=v[0]; i>=1; i--)
            h[h[0]] = (h[h[0]] * base + v[i]) & p2;
        int t = 0;
        for (int i=v[0]; i>=1; i--)
        {
            t = t * base + v[i];
            v[i] = t >> lp2, t &= p2;
        }
        while (v[v[0]] == 0 && v[0] > 0) v[0] --;
    }
    for (int i=1; i<=h[0]; i++)
        for (int j=0; j<lp2; j++)
            if (h[i] & (1 << j))
                val[id][(i - 1) * 10 + j] = 1;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
for (int I=1; I<=N; I++)
{
    read (I);
    for (int i=0; i<maxL; i++)
        if (val[I][i] && fxd[i])
            val[I] ^= val[fxd[i]], how[I] ^= how[fxd[i]];
    int j = -1;
    for (int i=0; i<maxL; i++)
        if (val[I][i])
        {
            j = i, fxd[i] = I, how[I][I - 1] = 1;
            break;
        }
    if (j == -1)
    {
        vector < int > ans;
        for (int j=0; j<I; j++)
            if (how[I][j])
                ans.push_back (j);
        printf ("%d", ans.size ());
        for (auto it : ans)
            printf (" %d", it);
        printf ("\n");
    }
    else printf ("0\n");
}
return 0;
}