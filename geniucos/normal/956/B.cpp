#include<bits/stdc++.h>

using namespace std;

int N, U, E[100009];
long double ans = 2.0;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &U);
for (int i=1; i<=N; i++)
    scanf ("%d", &E[i]);

int k = 1;
for (int i=1; i<N; i++)
{
    while (k + 1 <= N && E[k + 1] - E[i] <= U) k ++;
    if (k > i + 1 && k <= N)
    {
        double r = (long double) (E[i + 1] - E[i]) / (E[k] - E[i]);
        if (r < ans)
            ans = r;
    }
}

ans = 1.0 - ans;
cout << setprecision (20) << ans << '\n';
return 0;
}