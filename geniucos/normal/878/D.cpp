#include<bits/stdc++.h>

using namespace std;

int nr, N, K, Q, msk[12][100009], a[12][100009];
bitset < 1 << 12 > b[100019];
vector < int > v[100009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &K, &Q), nr = K;
for (int i=0; i<K; i++)
    for (int j=1; j<=N; j++)
        scanf ("%d", &a[i][j]);
for (int pos = 1; pos <= N; pos ++)
{
    for (int i=0; i<K; i++)
        v[pos].push_back (a[i][pos]);
    sort (v[pos].begin (), v[pos].end ());
    for (int i=0; i<K; i++)
        for (int j=0; j<K; j++)
            if (a[j][pos] >= v[pos][i])
                msk[i][pos] |= 1 << j;
}
for (int i=1; i<=K; i++)
    for (int j=0; j<1 << K; j++)
        b[i][j] = (j >> (i - 1)) & 1;
while (Q --)
{
    int type, x, y;
    scanf ("%d %d %d", &type, &x, &y);
    if (type == 1) b[++nr] = b[x] | b[y];
    else
    if (type == 2) b[++nr] = b[x] & b[y];
    else
    {
        int ans = -1;
        for (int j=K - 1; j>=0; j--)
            if (b[x][msk[j][y]])
            {
                ans = v[y][j];
                break;
            }
        printf ("%d\n", ans);
    }
}
return 0;
}