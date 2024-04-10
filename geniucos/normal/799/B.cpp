#include<bits/stdc++.h>

using namespace std;

int ind[3][3], N, M, p[200009], a[200009];
vector < int > v[3][3];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &p[i]);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
for (int i=1; i<=N; i++)
{
    int bi;
    scanf ("%d", &bi);
    v[a[i] - 1][bi - 1].push_back (p[i]);
}
for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
        ind[i][j] = 0, sort (v[i][j].begin (), v[i][j].end ());
scanf ("%d", &M);
while (M --)
{
    int c, hI = -1, hJ, mini = 1e9 + 9;
    scanf ("%d", &c), c --;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            if (i == c || j == c)
            {
                if (ind[i][j] < v[i][j].size ())
                {
                    int curr = v[i][j][ind[i][j]];
                    if (curr < mini)
                        mini = curr, hI = i, hJ = j;
                }
            }
    if (hI == -1) printf ("-1 ");
    else printf ("%d ", mini), ind[hI][hJ] ++;
}
printf ("\n");
return 0;
}