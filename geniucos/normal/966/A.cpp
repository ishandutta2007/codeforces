#include<bits/stdc++.h>

using namespace std;

int N, M, speed[2], sz[2], v[2][100009];

int firstToLeft (int sz, int v[], int pos)
{
    int p = 1, u = sz, mij, ras = 0;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (v[mij] <= pos) ras = mij, p = mij + 1;
        else u = mij - 1;
    }
    return ras;
}

int firstToRight (int sz, int v[], int pos)
{
    int ans = firstToLeft (sz, v, pos);
    if (v[ans] == pos) return ans;
    ans ++;
    if (ans > sz) return 0;
    return ans;
}

int modul (int x)
{
    if (x < 0) return -x;
    return x;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d %d %d", &N, &M, &sz[0], &sz[1], &speed[1]);
for (int i=0; i<2; i++)
    for (int j=1; j<=sz[i]; j++)
        scanf ("%d", &v[i][j]);
speed[0] = 1;

int Q;
scanf ("%d", &Q);
while (Q --)
{
    int x1, y1, x2, y2;
    scanf ("%d %d %d %d", &x1, &y1, &x2, &y2);
    if (x1 > x2) swap (x1, x2);
    if (y1 > y2) swap (y1, y2);
    if (x1 == x2)
    {
        printf ("%d\n", y2 - y1);
        continue;
    }
    int ans = 2e9;
    for (int i=0; i<2; i++)
    {
        vector < int > p;
        int curr = firstToLeft (sz[i], v[i], y1);
        if (curr != 0) p.push_back (v[i][curr]);
        if (curr + 1 <= sz[i]) p.push_back (v[i][curr + 1]);
        curr = firstToLeft (sz[i], v[i], y2);
        if (curr != 0) p.push_back (v[i][curr]);
        if (curr + 1 <= sz[i]) p.push_back (v[i][curr + 1]);
        for (auto j : p)
        {
            int currV = (x2 - x1) / speed[i];
            if ((x2 - x1) % speed[i] != 0) currV ++;
            currV += modul (y1 - j);
            currV += modul (y2 - j);
            if (currV < ans)
                ans = currV;
        }
    }
    printf ("%d\n", ans);
}
return 0;
}