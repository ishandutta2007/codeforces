#include<bits/stdc++.h>

using namespace std;

int N;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

/*int N, ans = 0, curr = 1;
scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    int x, sc = 0;
    scanf ("%d", &x), sc = (x - 1) / curr;
    ans += sc, x -= sc * curr, curr = max (curr, x + 1);
}
printf ("%d\n", ans);*/
scanf ("%d", &N);
if (N == 1)
{
    printf ("-1\n");
    return 0;
}
printf ("%d %d %d\n", N, N + 1, N * (N + 1));
return 0;
}