#include<bits/stdc++.h>

using namespace std;

int N;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
int t = 1;
for (int i=1; i<=N; i++)
{
    int x;
    scanf ("%d", &x), t = max (t, x);
}
printf ("%d\n", max (0, t - 25));
return 0;
}