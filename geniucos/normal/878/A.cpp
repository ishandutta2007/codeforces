#include<bits/stdc++.h>

using namespace std;

int N, must[10];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
for (int j=0; j<10; j++)
    must[j] = -1;
for (int i=1; i<=N; i++)
{
    char t;
    int x;
    scanf ("%c %d\n", &t, &x);
    for (int j=0; j<10; j++)
    {
        bool bit = (x >> j) & 1;
        if (t == '&' && bit == 0) must[j] = 0;
        else
        if (t == '|' && bit == 1) must[j] = 1;
        else
        if (t == '^' && bit == 1)
        {
            if (must[j] >= 0) must[j] ^= 1;
            else
            if (must[j] == -1) must[j] = -2;
            else must[j] = -1;
        }
    }
}
/*for (int j=0; j<10; j++)
    printf ("%d\n", must[j]);*/
int x = 0, y = 0, z = 0;
for (int j=0; j<10; j++)
{
    if (must[j] == 0) ;
    else
    if (must[j] == 1) y |= 1 << j;
    else
    if (must[j] == -1) x |= 1 << j;
    else x |= 1 << j, z |= 1 << j;
}
printf ("3\n& %d\n| %d\n^ %d\n", x, y, z);
return 0;
}