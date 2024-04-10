#include<bits/stdc++.h>

using namespace std;

int N, a1, b1, a2, b2, K;
char sir[59][59];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
for (int i=1; i<=N; i++)
{
    gets (sir[i] + 1);
    for (int j=1; j<=N; j++)
        sir[i][j] -= '0';
}
for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
        if (sir[i][j] == 4)
        {
            ++K;
            if (K == 1) a1 = a2 = i, b1 = b2 = j;
            else
            {
                if (i < a1) a1 = i;
                if (i > a2) a2 = i;
                if (j < b1) b1 = j;
                if (j > b2) b2 = j;
            }
        }
if (K == 0 || K != (a2 - a1 + 1) * (b2 - b1 + 1))
{
    printf ("No\n");
    return 0;
}
for (int i=a1; i<=a2; i++)
    for (int j=b1; j<=b2; j++)
        if (sir[i][j] != 4)
        {
            printf ("No\n");
            return 0;
        }
if (a1 > 0)
{
    for (int j=b1; j<=b2; j++)
        if (sir[a1 - 1][j] != 2)
        {
            printf ("No\n");
            return 0;
        }
}
if (a2 < N)
{
    for (int j=b1; j<=b2; j++)
        if (sir[a2 + 1][j] != 2)
        {
            printf ("No\n");
            return 0;
        }
}
if (b1 > 1)
{
    for (int i=a1; i<=a2; i++)
        if (sir[i][b1 - 1] != 2)
        {
            printf ("No\n");
            return 0;
        }
}
if (b2 < N)
{
    for (int i=a1; i<=a2; i++)
        if (sir[i][b2 + 1] != 2)
        {
            printf ("No\n");
            return 0;
        }
}
if (a1 > 1 && b1 > 1 && sir[a1 - 1][b1 - 1] != 1)
{
    printf ("No\n");
    return 0;
}
if (a1 > 1 && b2 < N && sir[a1 - 1][b2 + 1] != 1)
{
    printf ("No\n");
    return 0;
}
if (a2 < N && b1 > 1 && sir[a2 + 1][b1 - 1] != 1)
{
    printf ("No\n");
    return 0;
}
if (a2 < N && b2 < N && sir[a2 + 1][b2 + 1] != 1)
{
    printf ("No\n");
    return 0;
}
for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
    {
        if (i >= a1 - 1 && i <= a2 + 1 && j >= b1 - 1 && j <= b2 + 1) ;
        else
        if (sir[i][j] != 0)
        {
            printf ("No\n");
            return 0;
        }
    }
printf ("Yes\n");
return 0;
}