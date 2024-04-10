#include<bits/stdc++.h>

using namespace std;

int N;

bool prime (int x)
{
    if (x == 1) return 0;
    for (int i=2; i * i <= x; i++)
        if (x % i == 0) return 0;
    return 1;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=1000; i++)
    if (!prime (N * i + 1))
    {
        printf ("%d\n", i);
        return 0;
    }


return 0;
}