#include<bits/stdc++.h>

using namespace std;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int N, a, b, c, xi, ans = 0;
scanf ("%d %d %d", &a, &b, &c);
scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &xi), ans += (xi > b && xi < c);
printf ("%d\n", ans);

return 0;
}