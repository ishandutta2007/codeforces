#include<bits/stdc++.h>

using namespace std;

int b, k;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &b, &k);
int ans = 0, x;
if (b & 1)
{
    for (int i=1; i<=k; i++)
    {
        scanf ("%d", &x), x &= 1;
        ans ^= x;
    }
}
else
{
    for (int i=1; i<=k; i++)
    {
        scanf ("%d", &x);
        ans = x & 1;
    }
}
if (ans) printf ("odd\n");
else printf ("even\n");
return 0;
}