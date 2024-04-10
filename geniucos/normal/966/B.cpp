#include<bits/stdc++.h>

using namespace std;

int N, x1, x2, can1[300009], can2[300009], how1[300009], how2[300009];
pair < int, int > v[300009];

void print (int i1, int j1, int i2, int j2)
{
    printf ("Yes\n");
    printf ("%d %d\n", j1 - i1 + 1, j2 - i2 + 1);
    for (int k=i1; k<=j1; k++)
        printf ("%d ", v[k].second);
    printf ("\n");
    for (int k=i2; k<=j2; k++)
        printf ("%d ", v[k].second);
    printf ("\n");
    exit (0);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &x1, &x2);
for (int i=1; i<=N; i++)
    scanf ("%d", &v[i].first), v[i].second = i;
sort (v + 1, v + N + 1);
for (int i=N; i>=1; i--)
{
    can1[i] = can1[i + 1], how1[i] = how1[i + 1];
    if (1LL * (N - i + 1) * v[i].first >= x1) can1[i] = 1, how1[i] = i;
    can2[i] = can2[i + 1], how2[i] = how2[i + 1];
    if (1LL * (N - i + 1) * v[i].first >= x2) can2[i] = 1, how2[i] = i;
}
for (int i=N; i>=1; i--)
{
    int minK = (x1 / v[i].first) + (x1 % v[i].first != 0);
    if (i + minK <= N && can2[i + minK] == 1)
        print (i, i + minK - 1, how2[i + minK], N);

    minK = (x2 / v[i].first) + (x2 % v[i].first != 0);
    if (i + minK <= N && can1[i + minK] == 1)
        print (how1[i + minK], N, i, i + minK - 1);
}
printf ("No\n");
return 0;
}