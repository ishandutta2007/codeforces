#include<bits/stdc++.h>

using namespace std;

int N, ans;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), ans = 4 * N;
for (int i=1; i<=N; i++)
{
    int j = N / i;
    if (i * j < N) j ++;
    if (2 * (i + j) < ans)
        ans = 2 * (i + j);
}
printf ("%d\n", ans);
return 0;
}