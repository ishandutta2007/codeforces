#include<bits/stdc++.h>

using namespace std;

int N, a[20];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=0; i<N; i++)
    scanf ("%d", &a[i]);
for (int msk = 0; msk < (1 << N); msk ++)
{
    int sum = 0;
    for (int i=0; i<N; i++)
        if (msk & (1 << i)) sum += a[i];
        else sum -= a[i];
    if (sum % 360 == 0)
    {
        printf ("YES\n");
        return 0;
    }
}
printf ("NO\n");
return 0;
}