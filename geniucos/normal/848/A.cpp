#include<bits/stdc++.h>

using namespace std;

int K, ap[1000];

bool solve (int K)
{
    char c = 'a';
    while (K)
    {
        int F = 1;
        for (int i=1; i * (i - 1) / 2 <= K; i++)
            F = i;
        K -= F * (F - 1) / 2;
        ap[c ++] = F;
    }
    return (c <= 'z');
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &K);
if (K == 0)
{
    printf ("a\n");
    return 0;
}
solve (K);
for (int i='a'; i<='z'; i++)
    while (ap[i] --)
        printf ("%c", i);
printf ("\n");
return 0;
}